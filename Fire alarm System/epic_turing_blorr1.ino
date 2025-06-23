#define temp A1
#define gas A2
#define buz 7
#define led 13

void setup() {
  pinMode(buz, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int tempValue = analogRead(temp);
  float voltage = tempValue * (5.0 / 1023.0);
  float temperature = voltage * 100; // for LM35

  int gasValue = analogRead(gas);

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print(" °C, Gas: ");
  Serial.println(gasValue);

  if (temperature > 80 || gasValue > 100) {
    digitalWrite(buz, HIGH);
    digitalWrite(led, HIGH);
  } else {
    digitalWrite(buz, LOW);
    digitalWrite(led, LOW);
  }

  delay(1000);
}
