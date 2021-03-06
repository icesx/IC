#include <Arduino.h>
#include <gprs/Sim900a.h>
#include <base/util.h>
#include <HardwareSerial.h>
Sim900a sim900a(&Serial2, 115200);
HttpParam param;
void setup() {
	Serial.begin(115200);
	delay(100);
	sim900a.prepare();
	param.code = "test post!";
	param.host = "42.96.142.145";
	param.length = 10;
	param.port = 80;
	param.url = "/catchers/55e4f62ef89ff7030000149a";
	Serial.println("setup ok!");
}

void loop() {
	Serial.println("loop start>>>");
	sim900a.httpPost(&param);
	Serial.println("loop finished<<<");
	delay(5000);
}
