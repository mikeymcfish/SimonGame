#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978


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



int melody[] = {
  NOTE_D4, NOTE_A4, NOTE_F4, NOTE_D5, NOTE_F4, NOTE_D5
};

int noteDurations[] = {
  8, 8, 8, 4, 8, 4
};

String sequence = "";
int currLight = 0;

int speed = 400;
bool waitForInput = 1;

void setup()
{
  pinMode(RED, OUTPUT);
  pinMode(ORANGE, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  pinMode(REDB, INPUT_PULLUP);
  pinMode(ORANGEB, INPUT_PULLUP);
  pinMode(GREENB, INPUT_PULLUP);
  pinMode(BLUEB, INPUT_PULLUP);

  Serial.begin(9600);
  randomSeed(analogRead(14));
  digitalWrite(ORANGE, HIGH);
  digitalWrite(RED, HIGH);
  digitalWrite(GREEN, HIGH);
  digitalWrite(BLUE, HIGH);

  playSong();

  digitalWrite(ORANGE, LOW);
  digitalWrite(RED, LOW);
  digitalWrite(GREEN, LOW);
  digitalWrite(BLUE, LOW);


  waitForInput = 0;

}

void playSong() {
    for (int thisNote = 0; thisNote < 6; thisNote++) {

    int noteDuration = 1000 / noteDurations[thisNote];
    tone(SPKR, melody[thisNote], noteDuration);  
    int pauseBetweenNotes = noteDuration * 1.5;
    delay(pauseBetweenNotes);
    noTone(SPKR);

  }
  delay(500);
}

void loop()
{
  if (!waitForInput) { 
    currLight = 0;
  	addToSequence();
  	playSequence();
 	  waitForInput = 1;   
  }

  if (!digitalRead(REDB))
  {
  	lightR(100);
    if (checkButton(R)) {
      advanceOrEnd();
    }
    else endGame();
    delay(250);
  }
  
   if (!digitalRead(ORANGEB))
  {
  	lightY(100);
    if (checkButton(Y)) {
      advanceOrEnd();
    }
    else endGame();
    delay(250);
    
  }
  
  if (!digitalRead(GREENB))
  {
  	lightG(100);
    if (checkButton(G)) {
      advanceOrEnd();
    }
    else endGame();
    delay(250);
  }
  
  if (!digitalRead(BLUEB))
  {
  	lightB(100);
    if (checkButton(B)) {
      advanceOrEnd();
    }
    else endGame();
    delay(250);
  }
  
  delay(5);
}

void endGame() {
  Serial.println("Game Over.");
  int d = 350;
  delay(50);
  //tone(SPKR,NOTE_D4,d); 
  //delay(d);
 	tone(SPKR,NOTE_CS3,d); 
  delay(d);
 	tone(SPKR,NOTE_C2,d); 
  delay(d);

  delay(200);
  playSong();
  
  sequence = "";
 	currLight = 0;
	waitForInput = 0;
}

bool checkButton(char b) {
  char expectingButton = sequence.charAt(currLight);
  return (expectingButton==b);
}

void advanceOrEnd() {
  Serial.println(currLight);
  if (currLight==sequence.length()-1) {
   	waitForInput=0; 
    Serial.println("Correct.");
    delay(1000);
  }
  else currLight++;
}

void addToSequence() {
  
  int nextLight = random(0,4);
  sequence+=nextLight;
  Serial.println(sequence);
  
}

void playSequence() {
 	for(int i =0; i < sequence.length(); i++ ) {
  		char c = sequence.charAt(i);
   		playLight(c);
      delay(300);
	}  
}

void playLight(char c) {
  if (c=='0') {
    lightR(speed);
  }
  else if (c=='1') {
    lightY(speed);
  }
  else if (c=='2') {
    lightG(speed);
  }
  else if (c=='3') {
    lightB(speed);
  }
  
}

void increaseSpeed() {
  if (speed>150)speed-=50;
  else speed-=10;
}

void addToGuess() {
  
  
}

void lightR(int del) {
  digitalWrite(RED, HIGH);
  tone(SPKR, NOTE_C4,100);
  delay(del);
  digitalWrite(RED, LOW);
}

void lightY(int del) {
  digitalWrite(ORANGE, HIGH);
  tone(SPKR, NOTE_G3,100);
  delay(del);
  digitalWrite(ORANGE, LOW);
}

void lightG(int del) {
  digitalWrite(GREEN, HIGH);
  tone(SPKR, NOTE_A3,100);
  delay(del);
  digitalWrite(GREEN, LOW);
}

void lightB(int del) {
  digitalWrite(BLUE, HIGH);
  tone(SPKR, NOTE_B3,100);
  delay(del);
  digitalWrite(BLUE, LOW);
}
  