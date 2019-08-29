#include <iostream>
#include "HashTable.h"

using namespace std;

int main()
{
	HashTable my_ht1;
	int value;
	std::cout << "Insert value:" << std::endl;
	bool res = false;
	while (cin >> value) {
		res = my_ht1.Insert(value);
		if (!res) {
			break;
		}
	}

	cout << "Find value:" << endl;
	while (cin >> value) {
		res = my_ht1.Find(value);
		cout << "Find value: " << value << ", resule: " << boolalpha << res << endl;
	}

	cin.clear();
	cout << "Delete value:" << endl;
	while (cin >> value) {
		res = my_ht1.Remove(value);
		cout << "Remove value: " << value << ", resule: " << boolalpha << res << endl;
	}

	return 0;
}