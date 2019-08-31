#include <iostream>
#include "ListHashTable.h"

using namespace std;

int main()
{
	ListHashTable my_lht;
	my_lht.Print();

	int value;
	while (cin >> value)
		my_lht.Insert(value);
	cout << "ListHashTable value: ";
	my_lht.Print();
	cout << endl;

	cin.clear();
	while (cin >> value)
		my_lht.Delete(value);
	cout << "ListHashTable value: ";
	my_lht.Print();
	cout << endl;

	return 0;
}