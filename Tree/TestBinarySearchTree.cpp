#include "BinarySearchTree.h"

using namespace std;

int main()
{
	BinarySearchTree bst;
	bst.PreOrderPrint();
	bst.InOrderPrint();
	bst.PostOrderPrint();

	cout << "--------------------0" << endl;
	int value;
	while (cin >> value) {
		bst.Insert(value);
	}
	bst.PreOrderPrint();
	bst.InOrderPrint();
	bst.PostOrderPrint();

	cout << "--------------------1" << endl;
	for (int i = 0; i < 10; ++i) {
		BinarySearchTree::NodeType *search = bst.Search(i);
		if (search) {
			cout << "search value = " << i << endl;
		} else {
			cout << "not find value = " << i << endl;
		}
		if (i == 5) {
			bst.Delete(i);
			bst.PreOrderPrint();
		}
	}
	bst.PreOrderPrint();
	bst.InOrderPrint();
	bst.PostOrderPrint();

	return 0;
}