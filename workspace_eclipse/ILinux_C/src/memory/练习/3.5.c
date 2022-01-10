#include<stdlib.h>
#include<stdio.h>
main() {
	int *p;
	p = (int*) calloc(150, sizeof(char));
	if (p)
		printf("Memory Allocated at: %x", p);
	else
		printf("Not Enough Memory!\n");
	getchar();
	p = (int*) realloc(p, 100);
	if (p)
		printf("Memory Reallocated at: %x", p);
	else
		printf("Not Enough Memory!\n");
	free(p);
	getchar();
	return 0;
}
