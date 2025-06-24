#define tempPin A0  

void setup() {
  Serial.begin(9600);
}

void loop() {
  int analogValue = analogRead(tempPin);
  
  float voltage = analogValue * (5.0 / 1023.0);  // Convert to voltage
  float temperatureC = voltage * 100;            // Convert to °C (10mV per °C)

  Serial.print("Temperature: ");
  Serial.print(temperatureC);
  Serial.println(" °C");

  delay(1000);  
}
