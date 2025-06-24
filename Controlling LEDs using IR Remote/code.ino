#include <IRremote.h>

#define IR_Recv 12
#define bluePin 2
#define redPin 3
#define greenPin 4
  
IRrecv irrecv(IR_Recv);
decode_results results;

void setup(){
  Serial.begin(9600);
  irrecv.enableIRIn();
  pinMode(bluePin, OUTPUT);
  pinMode(redPin,OUTPUT);
  pinMode(greenPin,OUTPUT);
  
}
void loop(){
  
  if (irrecv.decode(&results)){
    long int decode = results.value;
    Serial.println(results.value);
    
    switch (results.value){
      case 16582903:
      digitalWrite(bluePin, HIGH); //button 1
    break;
    case 16615543: 
    digitalWrite(bluePin, LOW); //button 2
    break;
  case 16599223:
    digitalWrite(redPin, HIGH); // button 3
    break;
    case 16591063:
    digitalWrite(redPin, LOW); // button 4
    break;
    case 16623703:
    digitalWrite(greenPin, HIGH); // button 5
    break;
    case 16607383:
    digitalWrite(greenPin, LOW); //button 6
    break;
    
  }
  
  irrecv.resume(); //receives the next value
}
delay(100);
}
