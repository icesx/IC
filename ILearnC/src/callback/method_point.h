/*
 * method_point.h
 *
 *  Created on: Oct 14, 2019
 *      Author: i
 */

#ifndef CALLBACK_METHOD_POINT_H_
#define CALLBACK_METHOD_POINT_H_

typedef int (FUNC1)(int);
typedef int (FUNC2)(int*, int*, int*);

void show(FUNC2 fun, int arg1, int*arg2);
int multi(int*a, int*b, int*c);

#endif /* CALLBACK_METHOD_POINT_H_ */
