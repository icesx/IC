#include "SmartCarPark.h"
#include <Arduino.h>
#include <ethernet/http.h>
#include <gprs/Sim900a.h>
#include <sdcard/SdCard.h>
SoftwareSerial softSerial(2, 3);
SdCard sdcard;
//HttpClient w5100;
void pownon() {
	pinMode(SIM900A_PIN, OUTPUT);
	digitalWrite(SIM900A_PIN, LOW);
	delay(1000);
	digitalWrite(SIM900A_PIN, HIGH);
	delay(2000);
	digitalWrite(SIM900A_PIN, LOW);
	delay(3000);
	Serial.println("pownon");
	pinMode(10, OUTPUT);             // set the SS pin as an output (necessary!)
	digitalWrite(10, HIGH);
}
void setup() {
	Serial.begin(115200);
	startSim900a();
	delay(2000);
	sdcard.play();
	sdcard.checkSdCard();
//	startW5100();
}
void startSim900a() {
	Serial.println("Calling through GSM Modem");
	pownon();
	softSerial.begin(9600);
	delay(2000);
}
void startW5100() {
//	w5100.httpGet("42.96.142.145", "/index.htm", 5000);
}
void loop() {
	delay(10000);
//	char* response = mySim900a.transform();
//	sdcard.writeFile(file, response);
//	sdcard.readFile(file);
}
