//============================================================================
// Name        : IMethodPoint.cpp
// Author      : i
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include<stdio.h>
float func1(float f, char a, char b) {
	printf("func1\n");
	return f * a / b;
}
float func2(float f, char a, char b) {
	printf("func2\n");
	return f * a * b;
}
class MyClass {
public:
	MyClass(float f) {
		factor = f;
	}
	float func1(float f, char a, char b) {
		printf("MyClass::func1\n");
		return f * a / b * factor;
	}
	float func2(float f, char a, char b) const {
		printf("MyClass::func2\n");
		return f * a * b * factor;
	}
private:
	float factor;
};
int main(int argc, char *argv[]) {
	float (*pFunction)(float, char, char)=NULL;
	float (MyClass::*pMemberFunction)(float, char, char)=NULL;
	float (MyClass::*pConstMemberFunction)(float, char, char) const=NULL;
	float f = 10.0;
	char a = 'a', b = 'b';
	float result;
	pFunction = func1;
	printf("pointer pFunction's address is:%x\n", pFunction);
	result = (*pFunction)(f, a, b);
	printf("result=%f\n", result);
	pFunction = &func2;
	printf("pointer pFunction's address is:%x\n", pFunction);
	result = pFunction(f, a, b);
	printf("result=%f\n", result);
	if (func1 != pFunction)
		printf("not equal.\n");
	pMemberFunction = &MyClass::func1;
	MyClass mc1(0.2);
	printf("pointer pMemberFunction's address is:%x\n", pMemberFunction);
	result = (mc1.*pMemberFunction)(f, a, b);
	printf("result=%f\n", result);
	pConstMemberFunction = &MyClass::func2;
	MyClass mc2(2);
	printf("pointer pConstMemberFunction's address is:%x\n",
			pConstMemberFunction);
	result = (mc2.*pConstMemberFunction)(f, a, b);
	printf("result=%f\n", result);
	return 0;
}
