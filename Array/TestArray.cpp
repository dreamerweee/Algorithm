#include <iostream>
#include "DynamicArray.h"
#include "Array.h"

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

	cout << "========================" << endl;
	cin.clear();

	Array arr(10);
	arr.Delete(0);
	while (cin >> value) {
		arr.Insert(value);
	}
	arr.Update(0, 10);
	arr.Print();
	return 0;
}