#include <iostream>
#include "DynamicArray.h"
#include "Array.h"
#include <array>

using namespace::std;

static void MergeArray(const Array &arr1, const Array &arr2)
{
	size_t len1 = arr1.GetSize();
	size_t len2 = arr2.GetSize();

	if (len1 == 0 && len2 == 0) {
		cout << "two empty array." << endl;
	} else if (len1 == 0) {
		arr2.Print();
	} else if (len2 == 0) {
		arr1.Print();
	} else {
		auto new_arr = new int[len1+len2];
		size_t i = 0, j = 0, new_idx = 0;
		while (i < len1 && j < len2) {
			if (arr1[i] < arr2[j]) {
				new_arr[new_idx] = arr1[i];
				++i;
			} else {
				new_arr[new_idx] = arr2[j];
				++j;
			}
			++new_idx;
		}
		while (i < len1) {
			new_arr[new_idx++] = arr1[i++];
		}
		while (j < len2) {
			new_arr[new_idx++] = arr2[j++];
		}

		cout << "new array elements:";
		for (size_t k = 0; k < len1+len2; ++k)
			cout << new_arr[k] << " ";
		cout << endl;
		delete [] new_arr;
	}
}

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

	cout << "========================" << endl;
	cin.clear();

	Array arr1(5);
	while (cin >> value) {
		arr1.Insert(value);
	}
	cin.clear();
	Array arr2(8);
	while (cin >> value) {
		arr2.Insert(value);
	}
	MergeArray(arr1, arr2);

	return 0;
}