/*
 * python_c.c
 *
 *  Created on: Feb 10, 2018
 *      Author: i
 */
#include "python_c.h"
#include <stdio.h>
info ivoke(int x) {
	info i;
	i.name = "name";
	i.age = x + 2;
	i.id = 0001111l;
	return i;
}
info ivoke_2(info x) {
	printf("name=%s,age=%d,id=%ld\n",x.name,x.age,x.id);
	x.age=10;
	return x;
}
int ivoke_base(int x) {
	return x + 1;
}
