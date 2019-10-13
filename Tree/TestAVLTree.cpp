#include "AVLTree.h"
#include <iostream>

using namespace std;


// 3,2,1,4,5,6,7,16,15,14,13,12,11,10,8,9
int main()
{
	AvlTree avl_tree;
	cout << "input elements: ";
	int val;
	while (cin >> val && val != -1) {
		bool ret = avl_tree.Insert(val);
		if (ret) {
			cout << "insert success." << endl;
		} else {
			cout << "insert failed." << endl;
		}
	}
	avl_tree.Print();
	cout << "avl_tree height = " << avl_tree.GetHeight() << endl;

	while (cin >> val) {
		avl_tree.Delete(val);
		avl_tree.Print();
	}
	return 0;
}