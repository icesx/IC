/*
 * python_c.c
 *
 *  Created on: Feb 10, 2018
 *      Author: i
 */
#include "python_c.h"
struct info ivoke(int x) {
	struct info i;
	i.name = "name";
	i.age = x + 2;
	i.id=0001111l;
	return i;
}

