#include <Servo.h>

const int encoderPinA = 2; 
const int encoderPinB = 3; 

const int servoPin = 9;

Servo myServo;

volatile int encoderPos = 0; 
int prevEncoderPos = 0; 

void updateEncoder() {
  int aState = digitalRead(encoderPinA);
  int bState = digitalRead(encoderPinB);
  
  if (aState == HIGH) {

    if (bState == LOW) {
      encoderPos++; 
    } else {
      encoderPos--; 
    }
  }
  else {
    if (bState == HIGH) {
      encoderPos--;
    } else {
      encoderPos++; 
    }
  }
}

void setup() {
  pinMode(encoderPinA, INPUT);
  pinMode(encoderPinB, INPUT);
  
  myServo.attach(servoPin);
  
  attachInterrupt(digitalPinToInterrupt(encoderPinA), updateEncoder, CHANGE);
  attachInterrupt(digitalPinToInterrupt(encoderPinB), updateEncoder, CHANGE);
  
  myServo.write(90); 
}

void loop() {
  if (prevEncoderPos != encoderPos) {
    int servoAngle = map(encoderPos, 0, 100, 0, 180); 
    servoAngle = constrain(servoAngle, 0, 180);
    myServo.write(servoAngle);
    prevEncoderPos = encoderPos; 
    delay(15); 
  }
}