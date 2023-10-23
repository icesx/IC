#include <iostream>
#include "sharedlib.h"
using namespace std;

int main()
{
	cout<<"exe :"<<endl;
	cout<<"exe print: "<< api_add(1,2) << endl;
	cout<<"exe print: "<< api_sub(9,1) << endl;
	return 0;
}
