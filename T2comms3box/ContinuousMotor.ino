#include <Servo.h>

/* Pins */
const int servoPin = 3;
const int buttonPin = 4;

/* Servo Details */
Servo servo1;

  // Servo Constants //
  const int still = 1500;		    // IN MILISECONDS;
  const int fullSpeed = 2000;		// IN MILISECONDS;

///////////////////////////////////////////////////////////////////////////////////////

void setup() {
  servo1.attach(servoPin); 	    // Servo pin attach
  pinMode(buttonPin, INPUT);    // Button pin attach
 
 /* Begin tickrate 9600 for console */
  Serial.begin(9600);
}

///////////////////////////////////////////////////////////////////////////////////////

void loop() {

  /* Start still */
  servo1.writeMicroseconds(still);
  delay(30);
  
/////////////////////////////////////////////////////////

  /* If button Pressed then go full speed */
  if(digitalRead(buttonPin) == HIGH) {                                        // CHANGE TO IF PHOTORESISTER HAS NO LIGHT //
    
    /* Debug */ 
    Serial.println("BUTTON: Received");

    /* Go Full speed (2000) */
    servo1.writeMicroseconds(fullSpeed);
    delay(30);
  }

  
///////////////////////////////////////////////////////  

  /* If button isn't pressed go still & halt */
  if(digitalRead(buttonPin) == LOW) {	                                        // CHANGE TO IF PHOTORESISTER HAS LIGHT //
    
    /* Debug */
    Serial.println("BUTTON: Awaiting input");
    
    /* Stay still (1500) */
    servo1.writeMicroseconds(still);
    delay(30);
  }
  delay(30);

}



