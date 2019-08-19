/*
 * Ultrasonic.cpp
 *
 *  Created on: 2015年9月4日
 *      Author: i
 */
#include <Arduino.h>
#include "Ultrasonic.h"
int Ultrasonic::distance() {
	digitalWrite(trigPin, LOW); //低高低电平发一个短时间脉冲去TrigPin
	delayMicroseconds(2);
	digitalWrite(trigPin, HIGH);
	delayMicroseconds(10);
	digitalWrite(trigPin, LOW);
	int cm = pulseIn(echoPin, HIGH) / 58.0; //将回波时间换算成cm
	cm = (int(cm * 100.0)) / 100.0; //保留两位小数
	cm = (cm < 0) ? 256 : cm;
	return cm;
}

