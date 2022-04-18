#include <atmel_start.h>
#include <util/delay.h>
#include <avr/eeprom.h>
#include <avr/io.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

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


#define RED 5
#define ORANGE 4
#define GREEN 3
#define BLUE 2

#define REDB 8
#define ORANGEB 9
#define GREENB 10
#define BLUEB 11

#define SPKR 12



//OLD FOR PIN ASSIGNMENTS
/*
#define R '0'
#define Y '1'
#define G '2'
#define B '3'
*/

//New for bits in register
#define R '5'
#define Y '4'
#define G '3'
#define B '2'


#define TEST_MODE 15

char sequence[] = "";
char currLight = 0;

int speed = 400;
bool waitForInput = 1;

void lightLED (int i) {
	PIND = 1 << i;
	_delay_ms(200);
	PIND = 0;
}

bool checkButton(char b) {
	char expectingButton = sequence[currLight];
	return (expectingButton==b);
}

void advanceOrEnd() {
	//Serial.println(currLight);
	if (currLight==sizeof sequence) {
		waitForInput=0;
		//Serial.println("Correct.");
		_delay_ms(1000);
	}
	else currLight++;
}

void addToSequence() {
	srand(time(NULL));
	int nextLight = (rand()%4) + 2;
	sequence[sizeof sequence] = (char)nextLight;
	
}


void playSequence() {
	for(int i = 0; i < sizeof sequence; i++ ) {
		char c = sequence[i];
		lightLED(c);
		_delay_ms(300);
	}
}

void playATone() {
	for (int i =0; i <1000; i++) {
	 PORTB |=(1<<3); 
	 _delay_us(1000); 
	 PORTB &= ~(1<<3);
	 _delay_us(1000); 
	}
}

void endGame() {
	//Serial.println("Game Over.");
	_delay_ms(50);
	//tone(SPKR,NOTE_D4,d);
	//delay(d);
	//tone(SPKR,NOTE_CS3,350);
	_delay_ms(350);
	//tone(SPKR,NOTE_C2,350);
	_delay_ms(350);

	_delay_ms(200);

	updateHighScoreIfHigher();

	//playSong();
	
	memset(sequence,'0',1);
	currLight = 0;
	waitForInput = 0;
}

void playSong(int leng) {
	
}

void updateHighScoreIfHigher() {
	
	uint8_t score = eeprom_read_byte(0);
	if (sizeof sequence > score) eeprom_write_byte(0,score);
}

int main(void)
{
	atmel_start_init();
	DDRD = 0b00111100; //PD2-5 as output
	DDRB = 0b00010000; //PB4 is speaker as output
	PORTB = 0b00001111; //PB0-3 as input pullup
	PORTC_set_pin_pull_mode(1,1);
 	 //playATone();
	 if (PORTC & 1<<1 == 1) {
		 
		PORTD = 0b00111100;
		//reset high score
		eeprom_write_byte(0x00,4);
		 
	 } else {
		 //show high score 
		 uint8_t score = eeprom_read_byte(0x00);
		 PORTD = score<<2;
	 }
	 
	 PORTD = 0;
	 _delay_ms(500);
	 
	while (1) {			
		
		//Play song
		
		 if (!waitForInput) {
			 currLight = 0;
			 addToSequence();
			 playSequence();
			 waitForInput = 1;
		 }

		 if (PINB == 0b00000001 ) //button PB1 is pressed
		 {
			 lightLED(R);
			 _delay_ms(250);
			 checkButton(R) ? advanceOrEnd() : endGame();
		 }
		 
		 if (PINB == 0b00000010) //button PB1 is pressed
		 {
			lightLED(Y);
			_delay_ms(250);
			checkButton(Y) ? advanceOrEnd() : endGame();

		 }
		 
		if (PINB == 0b00000100 ) //button PB1 is pressed
		{
			lightLED(G);
			_delay_ms(250);			
			checkButton(G) ? advanceOrEnd() : endGame();
		}
		  
		if (PINB == 0b00001000) //button PB1 is pressed
		{
			lightLED(B);
			_delay_ms(250);
			checkButton(B) ? advanceOrEnd() : endGame();

		}
		
	}
}



