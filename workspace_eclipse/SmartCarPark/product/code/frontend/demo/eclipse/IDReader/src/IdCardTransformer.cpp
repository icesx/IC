/*
 * IdCardTransformer.cpp
 *
 *  Created on: 2015年8月12日
 *      Author: i
 */

#include <Arduino.h>
#include "../IDReader/IDReader.h"
#include <gprs/Sim900a.h>
#include "IdCardTransformer.h"
IDReader idReader(&Serial1, 115200);
HttpParam param;
Sim900a sim900a(&Serial2, 115200);
int led = 13;
void setup() {
	Serial.begin(115200);
	delay(1000);
	Serial.println("serial begin at 115200");
	delay(500);
	sim900a.prepareHttp();
	digitalWrite(led, HIGH);
}
void loop() {
	Serial.println("loop start!");
	char* info = idReader.heartbit();
	Serial.print("isreaded is ");
	if (info != NULL) {
		param.host = "114.247.216.6";
		param.port = 8900;
		param.url = ":8666/cas-webapp/app/equipment/equipmentMessage";
		param.code = info;
		param.length = strlen(info);
		sim900a.httpPost(&param);
	}
	delete info;
	delay(100);
}

