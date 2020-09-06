/*
 * BinaryInt.cpp
 *
 *  Created on: Nov 2, 2018
 *      Author: i
 */

#include "BinaryInt.h"
#include <stdio.h>
BinaryInt::BinaryInt() {
}

BinaryInt::~BinaryInt() {
}
int BinaryInt::getInt() {
	int i = value;
	this->reset();
	return i;
}
void BinaryInt::addChar(char c) {
	switch (c) {
	case 1:
		this->index++;
		this->value |= c << index;
		break;
	case 0:
		this->index++;
		break;
	default:
		printf("this char is not 0 or 1 %d", c);
	}

}
