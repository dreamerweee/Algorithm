#include "SkipList.h"
#include <iostream>

using namespace std;

int main(void)
{
	SkipList sl;
	cout << "------------------0:" << endl;
	sl.PrintSkipList();
	for (int i = 1; i <= 5; ++i) {
		sl.Insert(i, i * 2);
	}
	cout << "------------------1:" << endl;
	sl.PrintSkipList();

	SkipListNode *pres;
	for (int i = 1; i <= 5; ++i) {
		pres = sl.Search(i, i * 2);
		if (pres) {
			cout << "find k = " << pres->m_key << ", value = " << pres->m_data << endl;
		} else {
			cout << "not find k = " << i << endl;
		}
		if (i % 2 == 0) {
			if (sl.Delete(i, i * 2)) {
				cout << "delete k = " << i << endl;
				sl.PrintSkipList();
			} else {
				cout << "delete k = " << i << " failed." << endl;
			}
		}
	}
	cout << "------------------2:" << endl;
	sl.PrintSkipList();

	return 0;
}