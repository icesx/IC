/*
 * voiceSwith.c
 *
 *  Created on: 2015年8月28日
 *      Author: i
 */
#include <Arduino.h>
#include "../voice/voiceSwith.h"
#include "../IrSwith/IrSwith.h"
#include "../ultrasonic/Ultrasonic.h"
int irLed = 11;
int voiceLed = 10;
int ir = 2;
int vr = 0;
//extern IrSwith is;
//IrSwith is(ir, irLed);
//VoiceSwith vs(vr, voiceLed);
Ultrasonic us(2,3);
void setup() {
	Serial.begin(115200);
}
void loop() {
//	Serial.println(digitalRead(2));
//	vs.check();
	us.distance();
	delay(50);
}
