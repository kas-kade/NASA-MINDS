#include <Servo.h>

Servo servo1; // Up + Down
Servo servo2; // Left + Right

int posX = 0;
int posY = 0;

void setup() {
  Serial.begin(9600);
  servo1.attach(3);
  servo2.attach(5);

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

    servo1.(posY);
    servo2.(posX);
    
    Serial.print("You sent me: ");
    Serial.println(data);
  }
}
