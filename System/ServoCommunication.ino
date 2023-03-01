// Servo Library
#include <Servo.h>

Servo servo1; // Up + Down
Servo servo2; // Left + Right

int posX = 0;
int posY = 0;

void setup() {
  Serial.begin(9600);
  
  // Depending on which pin you use for the servo, you attach the servo with the number belonging to the pin
  // For example: On the arduino, if a servo is connected to the 4th pin, it will be .attach(4)
  servo1.attach(3);
  servo2.attach(5);

  // .write(#) refers to the the angle at which the servo turns to, with 0 being the default position
  // Can go from 0 to 180
  servo1.write(0);
  servo2.write(0);
}

void loop() {
  readSerialPort();
  delay(500);
}

void readSerialPort(){
  if (Serial.available() > 0) {
    int x = Serial.readStringUntil('\n');
    int y = Serial.readStringUntil('\n');

    posX += x;
    posY += y;

    servo1.write(posY);
    servo2.write(posX);
    
    Serial.print("You sent me: ");
    Serial.println(data);
  }
}
