/*
 ============================================================================
 Name        : ILearn.c
 Author      : icesx
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "clazz/child.h"
#include "integer/BinaryInt.h"
int main(void) {
	BinaryInt bi;
	bi.addChar(1);
	bi.addChar(1);
	bi.addChar(0);
	bi.addChar(1);
	printf("binary to int is %d", bi.getInt());
	Driver driver;
	Child doing;
	driver.doSome(doing);
	return EXIT_SUCCESS;
}

