#include <EEPROM.h>

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

#define R '0'
#define Y '1'
#define G '2'
#define B '3'

#define TEST_MODE 15


char sequence[] = {};
char currLight = 0;
char currLength = 0;

int speed = 400;
bool waitForInput = 1;

void setup()
{
  DDRD = 0b00111100; //PD2-5 as output
  PORTB = 0b00001111; //PB0-3 as input pullup
  PORTC &= 0b00000010;

  //Serial.begin(9600);
  randomSeed(analogRead(14));

  /// get random seed from the random eeprom

  if (digitalRead(TEST_MODE) == HIGH) {

    //DEAULT -- TEST LEDS
   PORTD = 0b00111100;
   resetHighScore();

  } else {

    //JUMPER PLACED -- RUN
    showHighScore();

  }

  playSong();
  
  PORTD = 0;

  _delay_ms(500);

  waitForInput = 0;

}

void showHighScore() {
  //read data
  //display on leds

  byte value;
  value = EEPROM.read(0);
  //Serial.println("high score:");
  //Serial.println(value);

  PORTD = value<<2;



}

void updateHighScoreIfHigher(int score) {
  byte value;
  value = EEPROM.read(0);
  //Serial.println(score);
  //Serial.println(value);
  if (score > value)
    EEPROM.write(0, score);
}

void resetHighScore () {
  
  EEPROM.write(0, 0x00);
}

void playSong() {

  int melody[] = {
  NOTE_D4, NOTE_A4, NOTE_F4, NOTE_D5, NOTE_F4, NOTE_D5
};

byte noteDurations[] = {
  8, 8, 8, 4, 8, 4
};

    for (byte thisNote = 0; thisNote < 6; thisNote++) {
      tone(SPKR, melody[thisNote], 1000 / noteDurations[thisNote]);  
      delay(noteDurations[thisNote] * 1.5);
      noTone(SPKR);
    }
  _delay_ms(500);
}

void loop()
{
  if (!waitForInput) { 
    currLight = 0;
  	addToSequence();
  	playSequence();
 	  waitForInput = 1;   
  }

  if (PINB & 1 == 1) //btn PB1 is pressed
  {
  	lightR();
    if (checkButton(R)) {
      advanceOrEnd();
    }
    else endGame();
    _delay_ms(250);
  }
  
   if (!digitalRead(ORANGEB))
  {
  	lightY();
    if (checkButton(Y)) {
      advanceOrEnd();
    }
    else endGame();
    _delay_ms(250);
    
  }
  
  if (!digitalRead(GREENB))
  {
  	lightG();
    if (checkButton(G)) {
      advanceOrEnd();
    }
    else endGame();
    _delay_ms(250);
  }
  
  if (!digitalRead(BLUEB))
  {
  	lightB();
    if (checkButton(B)) {
      advanceOrEnd();
    }
    else endGame();
    _delay_ms(250);
  }
  
  _delay_ms(5);
}

void endGame() {
  //Serial.println("Game Over.");
  _delay_ms(50);
  //tone(SPKR,NOTE_D4,d); 
  //delay(d);
 	tone(SPKR,NOTE_CS3,350); 
  _delay_ms(350);
 	tone(SPKR,NOTE_C2,350); 
  _delay_ms(350);

  _delay_ms(200);

  updateHighScoreIfHigher(currLength);

  playSong();
 	currLight = 0;
	waitForInput = 0;
}

bool checkButton(char b) {
  char expectingButton = sequence[currLight];
  return (expectingButton==b);
}

void advanceOrEnd() {
  //Serial.println(currLight);
  if (currLight==currLength)) {
   	waitForInput=0; 
    //Serial.println("Correct.");
    _delay_ms(1000);
  }
  else currLight++;
}

void createSequence() {
  
  int nextLight = random(0,4);
  sequence[sizeof(sequence)]=nextLight;
  //Serial.println(sequence);
  
}

void playSequence() {
 	for(int i =0; i < sizeof(sequence); i++ ) {
  		char c = sequence[i];
   		playLight(c);
      _delay_ms(300);
	}  
}

void playLight(char c) {
  if (c=='0') {
    lightR();
  }
  else if (c=='1') {
    lightY();
  }
  else if (c=='2') {
    lightG();
  }
  else if (c=='3') {
    lightB();
  }
  
}

void increaseSpeed() {
  if (speed>150)speed-=50;
  else speed-=10;
}

void lightR() {
  PIND = 1 << 5;
  tone(SPKR, NOTE_C4,100);
  _delay_ms(100);
  PIND = 0;
}

void lightY() {
  PIND = 1 << 4;
  tone(SPKR, NOTE_G3,100);
  _delay_ms(100);
  PIND = 0;
}

void lightG() {
  PIND = 1 << 3;
  tone(SPKR, NOTE_A3,100);
  _delay_ms(100);
  PIND = 0;
}

void lightB() {
  PIND = 1 << 2;
  tone(SPKR, NOTE_B3,100);
  _delay_ms(100);
  PIND = 0;
}
  
