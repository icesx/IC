/*
 * struct.c
 *
 *  Created on: Feb 10, 2018
 *      Author: i
 */
#include "struct.h"
#include <stdio.h>
void struct_test() {
	attWriteReq_t req;
	char value[ATT_MTU_SIZE - 3] = { 'I', ' ', 'a', 'm', ' ', 'h', 'a', 'p',
			'p', 'y' };
	int i;
	for (i = 0; i < (ATT_MTU_SIZE - 3); i++) {
		req.value[i] = value[i];
	}
	printf("%s\n", req.value);
}

