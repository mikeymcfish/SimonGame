#include <atmel_start.h>
#include <util/delay.h>
#include <avr/eeprom.h>
#include <avr/io.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <organ.h>
#include <scale16.h>
#include <avr/eeprom.h>

#define NOTE_C2  65
#define NOTE_CS3 139
#define NOTE_G3  196
#define NOTE_A3  220
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_D4  294
#define NOTE_D5  587
#define NOTE_A4  440
#define NOTE_F4  349
#define NOTE_DURATION 0xF000
#define SCORE_ADDRESS 0x1400

#define A 0
#define B 0b01000000
#define C 0b00100000
#define D 0b01100000
#define E 0b00010000
#define F 0b01010000
#define G 0b00110000
#define P 0b01110000

#define NUM0 0x3F
#define NUM1 0x06
#define NUM2 0x5B
#define NUM3 0x4F
#define NUM4 0x66
#define NUM5 0x6D
#define NUM6 0x7D
#define NUM7 0x07
#define NUM8 0x7F
#define NUM9 0x6F 
#define ENABLE (1 << 2)

#define DEL 50

#define LOOP_COUNT 1200

#define TEST_MODE 15

/*

PB[0:3] LEDS (R, Y, G, B) 
PC[0:3] BUTTONS (R, Y, G, B)
PA0 UDPI
PA1 SPEAKER
PA2 SEG0EN
PA3 SEG1EN
PA4 SEG0
PA5 SEG1
PA6 SEG2

*/
bool hold_display = 1;

char sequence[20] = {};
char currLight = 0;
char lightCount = 0;
char sizeQ = 0;
int speed = 400;
bool waitForInput = 0;
bool isMatch = 0;

uint8_t testThing = 1;

// change this with ADC:
int psuedo = 14;

void displayNumber(int NUM) {
	
	PORTA_OUT = 0; 
	
	for (int i = 0; i < LOOP_COUNT; i++) {
		
		NUM & 1 << 0 ? PORTA_OUT = ENABLE | A : 1;
		_delay_us(DEL);
		NUM & 1 << 1 ? PORTA_OUT = ENABLE | B : 1;
		_delay_us(DEL);
		NUM & 1 << 2 ? PORTA_OUT = ENABLE | C : 1;
		_delay_us(DEL);		
		NUM & 1 << 3 ? PORTA_OUT = ENABLE | D : 1;
		_delay_us(DEL);
		NUM & 1 << 4 ? PORTA_OUT = ENABLE | E : 1;
		_delay_us(DEL);
		NUM & 1 << 5 ? PORTA_OUT = ENABLE | F : 1;
		_delay_us(DEL);
		NUM & 1 << 6 ? PORTA_OUT = ENABLE | G : 1;
		_delay_us(DEL);
		PORTA_OUT &= 0b10001111;
	}
	PORTA_OUT &= 0b10000011; 
	
}

void lightLED (int i) {
	
	PORTB_OUT = 1 << i;
	switch (i)
	{
	case 0:
		playNote(B3,NOTE_DURATION);
		break;
	case 1:
		playNote(C4,NOTE_DURATION);
		break;
	case 2:
		playNote(D5,NOTE_DURATION);
		break;
	case 3:
		playNote(E6,NOTE_DURATION);
		break;
	
	}
	if (waitForInput)
		_delay_ms(200);
	else
		_delay_ms(600);
	PORTB_OUT = 0;
}
	
bool checkButton(char b) {
	char expectingButton = sequence[currLight];
	isMatch = (expectingButton==b);
	return isMatch;
}

void advanceOrEnd() {
	currLight++;
	if (currLight!=lightCount) {
		waitForInput=1;
		_delay_ms(10);
	}
	else {
		waitForInput=0;
	}
}

void addToSequence() {
	_delay_ms(100);
	int nextLight = (rand()%4);
	sequence[lightCount] = (char)nextLight;
	lightCount++;
}

void playSequence() {
	for(int i = 0; i < lightCount; i++ ) {
		char c = sequence[i];
		lightLED(c);
		_delay_ms(50);
	}
}

void endGame() {
	
	playNote(D4,(NOTE_DURATION));
	playNote(D4,(NOTE_DURATION));
	
	playNote(Cx3,NOTE_DURATION);
	playNote(Cx3,NOTE_DURATION);

	playNote(C2,NOTE_DURATION);
	playNote(C2,NOTE_DURATION);
	playNote(C2,NOTE_DURATION);

	updateHighScoreIfHigher();

	memset(sequence,'0',1);
	currLight = 0;
	waitForInput = 0;
	for (int i=0; i<20; i++) sequence[i]=0;
	lightCount = 0;
	_delay_ms(500);
	playSong();
}

void playSong() {
	
	playNote(D4,(NOTE_DURATION));
	
	playNote(A4,(NOTE_DURATION));
	
	playNote(F4,(NOTE_DURATION));
	
	playNote(D5,(NOTE_DURATION));
	playNote(D5,(NOTE_DURATION));
	
	playNote(F4,(NOTE_DURATION));
	
	playNote(D5,(NOTE_DURATION));
	playNote(D5,(NOTE_DURATION));
}

void updateHighScoreIfHigher() {

	uint8_t *location = (uint8_t *) 0;
	//eeprom_update_byte(location, 11);
	uint8_t score = eeprom_read_byte(location);
	uint8_t currScore = (uint8_t) --lightCount;
	if (currScore > score) 
		eeprom_update_byte(location,lightCount);
}

int main(void)
{
	atmel_start_init();
	PORTA_OUT = 0; 
	srand(psuedo);
	PORTB_OUT = 0x0F;  

//are there consistent segments that are more powerful? is it timing?
	 displayNumber(NUM0);
	 _delay_ms(100);
	 displayNumber(NUM1);
	 _delay_ms(100);
	 displayNumber(NUM2);
	 _delay_ms(100);
	 displayNumber(NUM3);
	 _delay_ms(100);
	 displayNumber(NUM4);
	 _delay_ms(100);
	 displayNumber(NUM5);
	 _delay_ms(100);
	 displayNumber(NUM6);
	 _delay_ms(100);
	 displayNumber(NUM7);
	 _delay_ms(100);
	 displayNumber(NUM8);
	 _delay_ms(100);
	 displayNumber(NUM9);
	 _delay_ms(100);
	 
	 //show high score
	PORTB_OUT = eeprom_read_byte( (uint8_t *) 0);
	_delay_ms(1200);
	PORTB_OUT = 0;
	_delay_ms(200);
		
	playSong();
		
	while (1) {			
		
		 if (!waitForInput) {
			 currLight = 0;
			 addToSequence();
			 playSequence();
			 waitForInput = 1;
		 }

		 if (!BTN_R_get_level()) 
		 {
			 lightLED(0);
			 _delay_ms(150);
			 checkButton(0) ? advanceOrEnd() : endGame();
		 }
		 
		 if (!BTN_Y_get_level())
		 {
			lightLED(1);
			_delay_ms(150);
			checkButton(1) ? advanceOrEnd() : endGame();

		 }
		 
		if (!BTN_G_get_level())
		{
			lightLED(2);
			_delay_ms(150);			
			checkButton(2) ? advanceOrEnd() : endGame();
		}
		  
		if (!BTN_B_get_level()) 
		{
			lightLED(3);
			_delay_ms(150);
			checkButton(3) ? advanceOrEnd() : endGame();

		}
			
	}
}



