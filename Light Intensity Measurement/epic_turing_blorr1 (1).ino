#define ldr A1
#define led 9 


void setup() {
  pinMode(led, OUTPUT);
  pinMode(ldr, INPUT);
  Serial.begin(9600);
}

void loop() {
  int x = analogRead(ldr);
  Serial.println(x);
 int y=map(x,0,1023,255,0);
  analogWrite(led,y);
  delay(100);
}
              