#include <Arduino.h>
#include "blink/blink_lib.h"
void setup()
{
	blink_setup(13);
}

void loop()
{
	blink(1000l, 13);
}
