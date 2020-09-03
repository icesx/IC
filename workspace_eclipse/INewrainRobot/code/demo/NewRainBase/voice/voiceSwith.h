/*
 * voicSwith.h
 *
 *  Created on: 2015年9月4日
 *      Author: i
 */

#ifndef VOICESWITH_H_
#define VOICESWITH_H_
#include <Arduino.h>
class VoiceSwith {
public:
	VoiceSwith(int analogPin, int ledPin) {
		pinMode(ledPin,OUTPUT);
		digitalWrite(ledPin,LOW);
		this->ledPin = ledPin;
		this->analogPin = analogPin;
	}
	void check();
private:
	int analogPin;
	int ledPin;
};

#endif /* VOICESWITH_H_ */
