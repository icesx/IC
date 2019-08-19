/*
 * Ultrasonic.h
 *
 *  Created on: 2015年9月4日
 *      Author: i
 */
#include <Arduino.h>
#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_

class Ultrasonic {
public:
	Ultrasonic(int trigPin, int echoPin) {
		this->trigPin = trigPin;
		this->echoPin = echoPin;
	}
	int distance();
private:
	int trigPin;
	int echoPin;
};

#endif /* ULTRASONIC_H_ */
