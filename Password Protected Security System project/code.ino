#include<Keypad.h>


const byte row = 4;
const byte col = 4;
const int redLed= 10;
const int greenLed= 11;
const int buz = 12;

char numPad [row][col]={
  {'1', '2','3'},{'4','5','6'},
  {'7','8','9'},{'*','0','#'}
};

byte rowPin[row]={9,8,7,6};
byte colPin[col]={5,4,3,2};

String password= "6556";
String vatup = "";

Keypad cKeypad = Keypad(makeKeymap(numPad), rowPin ,colPin ,row , col);

void setup()
{
  pinMode(redLed, OUTPUT);
  pinMode(greenLed,OUTPUT);
  pinMode(buz,OUTPUT);
  digitalWrite(redLed,HIGH);
  Serial.begin(9600);
  Serial.print("Enter Passcode: ");
}
  
  void loop(){

  char cKey =cKeypad.getKey();
  
  if (cKey){
    if(vatup.length() < 4) {
      Serial.print("*");
      vatup+= cKey;
      
    }  
  }
  if (vatup.length()==4){
    delay(1500);
    if(password==vatup){
      Serial.println("\nEnter");
      digitalWrite(redLed,LOW);
      digitalWrite(greenLed,HIGH);
      tone(buz,900);
      delay(800);
      noTone(buz);
    }else{
      Serial.println("\nWrong Passcode ");
      digitalWrite(redLed,HIGH);
      digitalWrite(greenLed,LOW);
      tone(buz,800);
      delay(800);
      noTone(buz);
      delay(800);
    }
    delay(1500);
    vatup="";
    Serial.println("Enter password: ");
    digitalWrite(redLed,HIGH);
    digitalWrite(greenLed,LOW);
  }
  }

