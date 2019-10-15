/*
 Blink
 Turns on an LED on for one second, then off for one second, repeatedly.

 This example code is in the public domain.
 */

// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
#include <Arduino.h>

void setup() {
	Serial.begin(115200);
}
String append(String f, char*s) {
	return f + s;
}

// the loop routine runs over and over again forever:
void loop() {
	char* x = "adafd";
	String y = "1234567890";
	int i = 890;
	char buf[4];
	y.toCharArray(buf, 4);
	Serial.println(buf);
	sprintf(buf, "%d", i);
	delay(5000);
}
