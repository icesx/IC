/*
 * labada.c
 *
 *  Created on: Nov 8, 2019
 *      Author: i
 */
#include "lambda.h"

#include <stdlib.h>
#include <stdio.h>
int run_lambada(const char *name, int (*callback)(const char *name, int age)) {
	return callback(name, 10);
}
void test_lambda() {
//没有捕获任何变量的Lambda表达式可以转换成与它的调用原型一致的函数指针
	auto f1 = [](const char *name, int age) {
		printf("lambda :name is %s,age is %d\n", name, age);
		return ++age;
	};
	int next_age = run_lambada("zhangsan", f1);
	printf("next age is %d\n", next_age);
}
int run_lambda2(const char *name, std::function<int(const char*, int)> func) {
	return func(name, 10);
}
typedef struct {
	int sex;
} person;
void test_lambda2() {
	person person;
	std::function<int(const char*, int)> func = [&person](const char *name,
			int age) {
		printf("function :name is %s,age is %d,sex=%d\n", name, age,
				person.sex);
		person.sex = 1;
		return ++age;
	};
	int next_age = run_lambda2("zhangsan", func);
	printf("next age is %d,person.sex=%d\n", next_age, person.sex);
}
