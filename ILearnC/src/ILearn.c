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
#include "array/array.h"
#include "struct/struct.h"
#include "string/string.h"
#include "integer/integer.h"
#include "callback/callback.h"

#include "callback/method_point.h"
void print_back(int x) {
	printf("callback is %d", x);
}
int main(void) {
	array_cp();
	array_cp_system();
	attWriteReq_t req = struct_test();
	printf("return struct %s\n", req.value);
	string_test();
	int i = binary_int("110");
	printf("binary to int is %d\n", i);
	call(1, &print_back);
	printf("%d\n", i);
	intAnd(100);
	int a;
	show(multi, 10, &a);
	strcmp_test();
	return EXIT_SUCCESS;
}

