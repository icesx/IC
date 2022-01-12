/*
 * speed.h
 *
 *  Created on: 2015年10月6日
 *      Author: i
 */

#ifndef STEPCOUNTER_H_
#define STEPCOUNTER_H_
#include <Arduino.h>
const int INTERRUPT_NUM_0 = 0;
const int INTERRUPT_NUM_1 = 1;
class StepCounter {
public:
	StepCounter(int interrupt_num) {
		step = 0;
		count = 0;
		callback = NULL;
		//void (*_stepcount)(void)=&StepCounter::stepcount;
		//attachInterrupt(interrupt_num,_stepcount, CHANGE);
	}
	int speed();
	void begin(int step);
	void end(void (*method)());
private:

	void stepcount();
	int step;
	int count;
	void (*callback)(void);
};

#endif /* STEPCOUNTER_H_ */
