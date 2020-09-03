#include <Arduino.h>
#include <gprs/Sim900a.h>
#include <base/util.h>
int led = 13;
int swith = 12;
Sim900a sim900a(&Serial2, 115200);
HttpParam param;
void prepareGprs() {
	sim900a.prepareHttp();
	param.code = "FCMI";
	param.host = "182.92.228.78";
	param.length = 4;
	param.port = 80;
	param.url = "/zmhzx/app/fishing/send";
	Serial.println("setup ok!");
}
void setup() {
	Serial.begin(115200);
	pinMode(led, OUTPUT);
	pinMode(swith, INPUT_PULLUP);
	digitalWrite(led, LOW);
	delay(1000);
	prepareGprs();
	delay(5000);
}

void get() {
	Serial.println("loop start>>>");
	sim900a.httpGet(&param);
	Serial.println("loop finished<<<");
}
bool isGet = false;
// the loop routine runs over and over again forever:
void loop() {
	Serial.println("start");
	int swithV = digitalRead(swith);
	Serial.println("swith is " + swithV);
	if (swithV == HIGH) {
		digitalWrite(led, LOW);
	} else {
		digitalWrite(led, HIGH);
		if (!isGet) {
			Serial.println("swith on");
			isGet = true;
			get();
			isGet = false;
			delay(3000);
		}
		Serial.println("get finish");
	}
	delay(10);
}
