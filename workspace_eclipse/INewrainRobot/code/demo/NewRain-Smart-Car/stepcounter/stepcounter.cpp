/*
 * speed.c
 *
 *  Created on: 2015年10月6日
 *      Author: i
 */
#include <Arduino.h>
#include"stepcounter.h"

void StepCounter::begin(int step) {
	this->step = step;
	this->count = 0;
}
void StepCounter::end(void (*method)()) {
	this->callback = *method;
}
extern "C" {
}
void StepCounter::stepcount() {
	this->count++;
	if (this->count == this->step) {
		this->callback();
	}
}
int StepCounter::speed() {
	return this->count;
}
