﻿#include "stdio.h"
main() {
	int i, s = 0;
	for (i = 1; i <= 100; i++)
		s = s + i;
	printf("1+2+..100=%d\n", s);
}
