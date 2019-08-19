#include "IrSwith.h"
extern IrSwith is;
void swith() {
	is.irSwith();
}
void IrSwith::irSwith() {
	Serial.println("irSwith");
	int irValue = digitalRead(this->pin);
	if (irValue == 1) {
		digitalWrite(ledPin, LOW);
	} else {
		digitalWrite(ledPin, HIGH);
	}
}
