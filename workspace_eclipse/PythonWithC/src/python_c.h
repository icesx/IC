/*
 * python_c.h
 *
 *  Created on: Sep 27, 2019
 *      Author: i
 */

#ifndef PYTHON_C_H_
#define PYTHON_C_H_
typedef struct {
	long id;
	char *name;
	int age;
	void (*callback)(int age);
} info;
info ivoke(int x,char*);
info ivoke_2(info x,void(*callback)());
int ivoke_base(int x);
#endif /* PYTHON_C_H_ */
