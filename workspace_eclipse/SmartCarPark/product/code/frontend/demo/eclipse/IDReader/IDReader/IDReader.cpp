/*
 * serial.cpp
 *
 *  Created on: 2015年8月11日
 *      Author: i
 */

#include "../IDReader/IDReader.h"

#include <HardwareSerial.h>
#include <base/util.h>
void IDReader::runCommand(byte* command, int len) {
	mySerial->write(command, len);
	Serial.print("run command:");
	for (int i = 0; i < len; i++) {
		Serial.print(" 0x");
		Serial.print(command[i], HEX);
	}
	Serial.println('\0');
}
char* IDReader::carRead() {
	Serial.println("carRead");
	memset(carInfo, 0xFF, sizeof(carInfo));
	int i = 0;
	long current = millis();
	int size = sizeof(carInfo);
	runCommand(commands.readCard2, sizeof(commands.readCard2));
	boolean isReaded = false;
	while (current + 2000 > millis() && i < size) {
		int a = mySerial->available();
		if (a > 0) {
			for (int j = 0; j < a; j++, i++) {
				carInfo[i] = mySerial->read();
				isReaded = true;
			}
		}
	}
	Serial.println("readed");
	if (isReaded == true) {
		char* buffer = new char[sizeof(carInfo) * 2];
		convertStrToHex(buffer, carInfo,CATINFO_LEN);
		return buffer;
	}
	return NULL;
}
int IDReader::readSerial() {
	while (mySerial->available() == 0) {
		Serial.print('.');
		delay(5);
	}
	Serial.println('\0');
	memset(commandResponse, 0, sizeof(commandResponse));
	int size = mySerial->available();
	Serial.print("to read avaliable is ");
	Serial.println(size);
	int i = 0;
	while (mySerial->available()) {
		byte b = mySerial->read();
		commandResponse[i] = b;
		Serial.print(" 0x");
		Serial.print(b, HEX);
	}
	Serial.println('\0');
	return size;
}

void IDReader::printId() {
	Serial.println('\0');
	for (int i = 0; i < sizeof(carInfo); i++) {
		Serial.print(carInfo[i], HEX);
		Serial.print(' ');
	}
	Serial.println('\0');
}

char* IDReader::readPrepary() {
	Serial.println("readPrepary");
	runCommand(commands.readCard, sizeof(commands.readCard));
	int length = readSerial();
	if (length == result.carReadyLength) {
		Serial.println("car is ready to read");
		return carRead();
	}
//	printId();
	return NULL;
}

char* IDReader::readHeartbit() {
	Serial.println("readHeartbit2");
	int length = readSerial();
	Serial.println();
	if (length == result.carTouchLength) {
		Serial.println("car touched so try to readCard");
		return readPrepary();
	}
	return NULL;
}
char* IDReader::heartbit() {
	Serial.println("heartbit");
	runCommand(commands.heartbit, sizeof(commands.heartbit));
	Serial.println("read hearbit");
	readSerial();
	delay(10);
	Serial.println("heartbit2");
	runCommand(commands.heartbit2, sizeof(commands.heartbit2));
	return readHeartbit();
}

