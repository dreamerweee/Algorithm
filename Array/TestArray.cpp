#include "DynamicArray.h"
#include <iostream>

using namespace::std;

int main()
{
	DynamicArray da;
	int value;
	while (cin >> value) {
		da.Insert(da.GetSize(), value);
	}
	da.Print();
	while (da.GetSize()) {
		da.Delete(0);
		da.Print();
	}
	return 0;
}