/*
 * integer.c
 *
 *  Created on: Nov 2, 2018
 *      Author: i
 */
#include "integer.h"
int binary_int(const char *str) {
	int i, j;
	int mask = 0;
	int size = (int) strlen(str);
	for (i = 0, j = 0; j < size; i++) {
		if (str[i] == '1') {
			mask |= (1 << (size - 1 - j));
			j++;
		} else if (str[i] == '0')
			j++;

	}
	return mask;
}
void intAnd(int i) {
	printf("and is %d\n", i & 63);
}

