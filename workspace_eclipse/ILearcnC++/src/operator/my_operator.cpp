/*
 * my_operator.cpp
 *
 *  Created on: Nov 9, 2019
 *      Author: i
 */
#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;
struct point {
	int elem;
	bool operator==(const point b) const {
		return this->elem == b.elem;
	}
	bool operator!=(const point b) const {
		return this->elem != b.elem;
	}
	bool operator<=(const point b) const {
		return this->elem <= b.elem;
	}
	bool operator<(const point b) const {
		return this->elem < b.elem;
	}
	bool operator>=(const point b) const {
		return this->elem >= b.elem;
	}
	bool operator>(const point b) const {
		return this->elem > b.elem;
	}
} now;

