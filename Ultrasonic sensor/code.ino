// C++ code
#define trig 10
#define echo 11
long time;
int distance;
void setup()
{
  pinMode(trig,OUTPUT);
  pinMode (echo,INPUT);
  Serial.begin(9600);
}

void loop()
{
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  
  time = pulseIn(echo, HIGH);
  distance = time * 0.034 / 2;
  
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  delay(500);
}
