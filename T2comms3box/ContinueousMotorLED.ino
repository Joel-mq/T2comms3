#include <Servo.h>

/* Pins */
const int servoPin = 3;
const int buttonPin = 4;
const int ledPin = 5;

/* Servo Details */
Servo wheelServo;

// Servo Constants
const int still = 1500;     // IN MILISECONDS;
const int fullSpeed = 2000; // IN MILISECONDS;

// Button states
int lastButtonState = HIGH; // Last state of the button
int buttonState = HIGH;     // Current state of the button

// Modes
int wheelMode = 0; // 0 for stopped, 1 for started

void setup() {
  wheelServo.attach(servoPin);  // Servo pin attach
  pinMode(buttonPin, INPUT);    // Button pin attach
  pinMode(ledPin, OUTPUT);		// LED pin attach

  // Begin tickrate 9600 for console
  Serial.begin(9600);
}

void loop() {
  // Read current button state
  buttonState = digitalRead(buttonPin);


  // Check for button press
  if (lastButtonState == HIGH && buttonState == LOW) {
    wheelMode++; // Increment mode
    if (wheelMode > 1) { // Wrap around after 2
      wheelMode = 0;
    }
  }

  // Action based on mode
  switch (wheelMode) {
    case 0:
      flashLED();
      startWheel();
      Serial.println("BUTTON: Started");
      break;
    case 1:
      stopLED();
      stopWheel();
      Serial.println("BUTTON: Stopped");
      digitalWrite(ledPin, LOW);  // turn the LED on
      break;
  }

  // Save current button state for next iteration
  lastButtonState = buttonState;

  delay(30); // Debounce delay
}

// FUNCTIONS
void flashLED() {
      digitalWrite(ledPin, HIGH);  // turn the LED on
  	  delay(250); 
      digitalWrite(ledPin, LOW);  // turn the LED on
  	  delay(250); 
}

void stopLED() {
	digitalWrite(ledPin, LOW);  // turn the LED on
}

void stopWheel() {
  wheelServo.writeMicroseconds(still);
  delay(30);
}

void startWheel() {
  wheelServo.writeMicroseconds(fullSpeed);
  delay(30);
}


