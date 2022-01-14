//============================================================================
// Name        : Hello_Cpp.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <cpp_module.h>

#ifdef __cplusplus
extern "C" void cppsayhello();
void cppsayhello()
{
	PrintMe pm;
	pm.printme();
}
#endif
int main()
{
	cppsayhello();
	return 0;
}
