/*
 * callback.c
 *
 *  Created on: Nov 4, 2018
 *      Author: i
 */
#include "callback.h"
void call(int x,void (*ck)()){
	(*ck)(x+1);
}


