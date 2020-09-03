
//============================================================================
// Name        : Hello_Cpp.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

extern "C" {
// tell compiler this is c code
#include "module.h"
}
int main() {
	printme();
	return 0;
}
