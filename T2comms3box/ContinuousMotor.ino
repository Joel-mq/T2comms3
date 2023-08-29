#include <Servo.h>

/* Pins */
const int servoPin = 3;
const int buttonPin = 4;

/* Servo Details */
Servo wheelServo;

  // Servo Constants //
  const int still = 1500;		    // IN MILISECONDS;
  const int fullSpeed = 2000;		// IN MILISECONDS;
  bool halt;

///////////////////////////////////////////////////////////////////////////////////////

void setup() {
  wheelServo.attach(servoPin); 	    // Servo pin attach
  pinMode(buttonPin, INPUT);    // Button pin attach
 
 /* Begin tickrate 9600 for console */
  Serial.begin(9600);
}

///////////////////////////////////////////////////////////////////////////////////////

void loop() {

  /* If button Pressed */
  if(digitalRead(buttonPin) == HIGH) {                                        // CHANGE TO IF PHOTORESISTER HAS NO LIGHT //
    
    halt = true;
    
    /* Debug */ 
    Serial.println("BUTTON: Received");

    /* Go Full speed (2000) */
    stopWheel();
    delay(30);
    
    
  }

  /* If button isn't pressed */
  if(digitalRead(buttonPin) == LOW) {	                                        // CHANGE TO IF PHOTORESISTER HAS LIGHT //
    
    /* Debug */
    Serial.println("BUTTON: Awaiting input");
    
    /* Stay still (1500) */
    startWheel();
  }
  delay(30);

}

// FUNCTIONS

void stopWheel() {
  wheelServo.writeMicroseconds(still);
  delay(30);
}

void startWheel() {
  wheelServo.writeMicroseconds(fullSpeed);
  delay(30);
}


