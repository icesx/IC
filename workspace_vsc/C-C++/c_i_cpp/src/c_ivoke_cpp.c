//============================================================================
// Name        : Hello_Cpp.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <cpp_module.h>
extern "C" void cppsayhello();
void cppsayhello() {
	PrintMe pm;
	pm.printme();
}
int main() {
	cppsayhello();
	return 0;
}
