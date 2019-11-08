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
#include "lambda/lambda.h"
#include "list/list_me.h"
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
	test_list();
	test_lambada();
	test_list2();
	return EXIT_SUCCESS;
}

