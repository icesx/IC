#include "sharedlib.h"
#include "stdio.h"
#include "jadd.h"
#include "jsub.h"

int api_add(int a,int b){
	printf("sharedlib print: call add\n");
	return add(a,b);
}

int api_sub(int a,int b){
	printf("sharedlib print: call sub\n");
	return sub(a,b);
}
