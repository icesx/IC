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
} info;
info ivoke(int x);
info ivoke_2(info x);
int ivoke_base(int x);
#endif /* PYTHON_C_H_ */
