/*
 Blink
 Turns on an LED on for one second, then off for one second, repeatedly.

 This example code is in the public domain.
 */

// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
#include <Arduino.h>
int led = 13;

void setup() {
	// initialize the digital pin as an output.
	pinMode(led, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
	Serial.println("start");
	digitalWrite(led, HIGH);
	delay(5000);
	digitalWrite(led, LOW);
	delay(5000);
}
