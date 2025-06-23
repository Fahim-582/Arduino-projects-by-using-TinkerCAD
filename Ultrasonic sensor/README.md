📌 Ultrasonic Sensor with Arduino
🧠 Description
This Arduino project uses an HC-SR04 ultrasonic sensor to measure the distance of an object in centimeters and displays the result on the Serial Monitor.

🎯 Objective
To demonstrate how to use an ultrasonic sensor to measure distance and understand how sound waves can be used in embedded systems for object detection.

🔧 Components Used
Arduino UNO/Nano

HC-SR04 Ultrasonic Sensor

Jumper wires

Breadboard

USB cable

🧾 Circuit Diagram
diff
Copy code
HC-SR04      Arduino
--------     -------
VCC      →    5V  
GND      →    GND  
TRIG     →    D10  
ECHO     →    D11
🧑‍💻 Code
cpp
Copy code
#define trig 10
#define echo 11

long time;
float distance;

void setup() {
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(9600);
}

void loop() {
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
📷 Working Principle
The ultrasonic sensor sends out a sound wave through the TRIG pin and listens for its echo on the ECHO pin. The time difference is used to calculate the distance using the formula:

ini
Copy code
Distance = (Time × Speed of Sound) / 2
📈 Output Example
makefile
Copy code
Distance: 12.34 cm
Distance: 10.87 cm
...
🚀 Future Improvements
Show distance on an LCD or OLED.

Add buzzer alerts for close-range detection.

Display distance in inches or meters.
