/*
 * voiceSwith.cpp
 *
 *  Created on: 2015年9月4日
 *      Author: i
 */

#include "voiceSwith.h"
void VoiceSwith::check() {
	int voice = analogRead(this->analogPin);
	Serial.print("voice:");
	Serial.println(voice);
	if (voice > 100) {
		digitalWrite(this->ledPin, HIGH);
	}else{
		digitalWrite(this->ledPin,LOW);
	}
}
