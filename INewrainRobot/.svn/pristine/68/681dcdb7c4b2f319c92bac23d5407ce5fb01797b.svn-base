/*
 * IRSwith.h
 *
 *  Created on: 2015年9月4日
 *      Author: i
 */

#ifndef IRSWITH_H_
#define IRSWITH_H_
#include <Arduino.h>
void swith();
class IrSwith {
public:
	IrSwith(int pin, int ledPin) {
		pinMode(ledPin, OUTPUT);
		digitalWrite(ledPin, LOW);
		this->ledPin = ledPin;
		this->pin = pin;
		pinMode(pin, INPUT_PULLUP);
		attachInterrupt(digitalPinToInterrupt(pin), swith, CHANGE);
	}
	void irSwith();
private:
	int ledPin;
	int pin;
};

#endif /* IRSWITH_H_ */
