/*
 * labada.c
 *
 *  Created on: Nov 8, 2019
 *      Author: i
 */
#include "lambda.h"

#include <stdlib.h>
#include <stdio.h>
int run_lambada(int (*callback)(int age)) {
	return callback(10);
}
void test_lambada() {
	auto f1 = [](int age)  {
		printf("lambda :name is %s,age is %d\n", "name", age);
		return ++age;
	};
	int next_age = run_lambada(f1);
	printf("next age is %d\n", next_age);
}

