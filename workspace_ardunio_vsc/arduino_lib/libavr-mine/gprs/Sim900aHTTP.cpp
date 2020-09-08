/*
 * Sim900.c
 *
 *  Created on: 2015年8月6日
 *      Author: i
 */
#include "Sim900a.h"

#include <Arduino.h>
#include <HardwareSerial.h>
#include <base/util.h>
void Sim900a::prepare() {
	Serial.println("sim900a prepare >>>");
	this->mySerial->begin(this->band);
	this->poweron();
	delay(500);
	sendATcommandTimeout("AT", defaultOk, 3000, true);
	delay(2000);
	sendATcommandTimeout("AT+CIPSHUT", defaultOk, 3000, true);
	delay(2000);
	sendATcommandTimeout("AT+CIPMUX=0", defaultOk, 15000, true);
	delay(2000);
	sendATcommandTimeout("AT+CGATT=1", defaultOk, 15000, true);
	delay(3000);
	sendATcommandTimeout("AT+CSTT=\"www.scp\",\"\",\"\"", defaultOk, 15000,
	true);
	delay(2000);
	sendATcommandTimeout("AT+CIPSPRT=1", defaultOk, 15000, true);
	delay(2000);
	sendATcommandTimeout("AT+CIICR", defaultOk, 25000, true);
	delay(2000);
	sendATcommandTimeout("AT+CIFSR", ".", 15000, true);

	Serial.println("sim900a prepared <<<");
}
void Sim900a::prepareHttp() {
	prepare();
	delay(1000);
	sendATcommandTimeout("AT+SAPBR=3,1,\"CONTYPE\",\"GPRS\"", defaultOk, 15000,
	true);
	delay(1000);
	sendATcommandTimeout("AT+SAPBR =1,1", defaultOk, 15000,
	true);
	sendATcommandTimeout("AT+HTTPTERM", defaultOk, 1000, false);
	sendATcommandTimeout("AT+HTTPINIT", defaultOk, 15000, true);
}
void Sim900a::poweron() {
	Serial.println("sim900a poweron");
	pinMode(SIM900A_PIN, OUTPUT);
	digitalWrite(SIM900A_PIN, HIGH);
}
void Sim900a::runCommand(char* ATcommand) {
	this->mySerial->println(ATcommand);
	this->mySerial->flush();
	Serial.print("try:");
	Serial.print(ATcommand);
	Serial.println();
}
void Sim900a::sendATcommandTimeout(char* ATcommand, char* okFlag, long timeout,
		boolean retry) {
	runCommand(ATcommand);
	boolean isOk = readFromMySerial(timeout, okFlag);
	Serial.println();
	if (isOk) {
		return;
	} else {
		if (retry == true) {
			delay(2000);
			Serial.print("retrytimeout:");
			Serial.println(ATcommand);
			sendATcommandTimeout(ATcommand, okFlag, timeout, retry);
		}
	}
	Serial.println();
}
boolean Sim900a::readFromMySerial(long timeout, char* okFlag) {
	memset(serialResponse, 0xFF, SERIAL_RESPONSE_SIZE);
	int x = 0;
	boolean isOk = false;
	previous = millis();
	long usedTime = 0;
	Serial.print("back:");
	while (usedTime < timeout) {
		usedTime = (millis() - previous);
		if (x >= SERIAL_RESPONSE_SIZE) {
			Serial.println("serialResponse is full");
			break;
		}
		int i = this->mySerial->read();
		if (i == 0xFFFFFFFF) {
			Serial.print(".");
			delay(2);
			continue;
		} else {
			serialResponse[x] = i;
			Serial.print(serialResponse[x]);
			x++;
		}
		if (strstr(serialResponse, okFlag)) {
			Serial.println(" is OK! ");
			isOk = true;
			break;
		}
	};
	if (isOk == false) {
		Serial.print("readFromMySerial timeout,use time :");
		Serial.println(usedTime);
	}
	Serial.println();
	return isOk;
}
void Sim900a::reconnect(char* host, int port) {
	String command = strAppendChar("AT+CIPSTART=\"TCP\",\"", host);
	command = strAppendStr(command, strAppendInt("\",", port));
	char* _command;
	command.toCharArray(_command, command.length());
	sendATcommandTimeout(_command, "CONNECT OK", 15000, true);
}
void Sim900a::close_connect() {
	Serial.println("close_connect >>>");
	sendATcommandTimeout("AT+CIPCLOSE", "CLOSE OK", 15000, false);
	Serial.println("close_connect >>>");
}
char* Sim900a::tcp(char *code) {
	sendATcommandTimeout("AT+CIPSEND=512", ">", 15000, false);
	this->mySerial->println(code);
	readFromServer(15000, "scp");
	Serial.println();
	return serialResponse;
}
void Sim900a::readFromServer(long timeout, char* okFlag) {
	Serial.println("readFromServer");
	while (this->mySerial->available()) {
		char c = this->mySerial->read();
		Serial.print(c);
	}
}
char* Sim900a::httpGet(HttpParam* param) {
	Serial.println("http Get >>>");
	return requestOnHttp(param->code, HTTP_METHOD_GET, param);
}
char* Sim900a::httpPost(HttpParam* param) {
	Serial.println("http Post >>>");
	return requestOnHttp(param->code, HTTP_METHOD_POST, param);
}

void Sim900a::runHttpPara(HttpParam* param) {
	String httpPara = "AT+HTTPPARA=\"URL\",\"";
	httpPara = strAppendStr(httpPara, param->host);
	httpPara = strAppendStr(httpPara, param->url);
	httpPara = strAppendStr(httpPara, "\"");
	char charHttpPara[httpPara.length()];
	strToChar(httpPara, charHttpPara);
	Serial.println(charHttpPara);
	sendATcommandTimeout(
			charHttpPara,
			defaultOk, 15000, true);
}

void Sim900a::runHttpData(HttpParam* param) {
	String httpDataCommand = strAppendInt("AT+HTTPDATA=", param->length);
	Serial.println(httpDataCommand);
	httpDataCommand = strAppendStr(httpDataCommand, ",15000");
	Serial.println(httpDataCommand);
	char charHttpData[httpDataCommand.length()];
	strToChar(httpDataCommand, charHttpData);
	Serial.println(charHttpData);
	sendATcommandTimeout("AT+HTTPDATA=2600,15000", "DOWNLOAD", 15000, true);
}

char* Sim900a::requestOnHttp(char* code, char* method, HttpParam* param) {
	sendATcommandTimeout("AT+HTTPPARA=\"CID\",1", defaultOk, 15000, true);
	runHttpPara(param);
	delay(10);
	runHttpData(param);
	sendATcommandTimeout(code, defaultOk, 1000, true);
	sendATcommandTimeout("AT+HTTPACTION=1", "+HTTPACTION:", 15000, true);
	readFromServer(15000, "scp");
	return serialResponse;
}
void Sim900a::sendCode(char* code) {
	Serial.print(code);
	this->mySerial->print(code);
}
void Sim900a::sendCodeln(char*code) {
	Serial.println(code);
	this->mySerial->println(code);
}
void Sim900a::sendCodeln(int i) {
	Serial.println(i);
	this->mySerial->println(i);
}
void Sim900a::sendCode(int i) {
	Serial.print(i);
	this->mySerial->print(i);
}

char* Sim900a::requestOnTcp(char* code, char* method, HttpParam* param) {
	reconnect(param->host, param->port);
	sendATcommandTimeout("AT+CIPSEND=512", ">", 15000, false);
	sendCode(method);
	sendCode(" ");
	sendCode(param->url);
	sendCodeln(HTTP_VERSION);
	sendCode("HOST: ");
	sendCodeln(param->host);
	sendCode("Content-Type:");
	sendCodeln(HTTP_CONTENTYPE);
	sendCode("Content-Length: ");
	sendCode(param->length);
	sendCodeln(HTTP_NEW_LINE);
	sendCode(code);
	sendCode(SEND_FLAG);
	sendCodeln(HTTP_NEW_LINE);
	readFromServer(10000, "scp");
	Serial.println();
	delay(1000);
	close_connect();
	Serial.println("request >>>");
	return serialResponse;
}

