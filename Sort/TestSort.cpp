#include "Sort.h"
#include <iostream>

static void Print(vector<int> &arr, string str)
{
	cout << "===================: " << str << endl;
	for (auto e : arr)
		cout << e << " ";
	cout << endl;
}

int main()
{
	int val;
	vector<int> arr;
	while (cin >> val) {
		arr.push_back(val);
	}
	/*
	Print(arr, "before BubbleSort");
	BubbleSort(arr);
	Print(arr, "after BubbleSort");
	
	Print(arr, "before InsertSort");
	InsertSort(arr);
	Print(arr, "after InsertSort");
	
	Print(arr, "before SelectSort");
	SelectSort(arr);
	Print(arr, "after SelectSort");
	
	Print(arr, "before ShellSort");
	ShellSort(arr);
	Print(arr, "after ShellSort");
	
	Print(arr, "before MergeSort");
	MergeSort(arr);
	Print(arr, "after MergeSort");
	*/
	Print(arr, "before QuickSort");
	QuickSort(arr);
	Print(arr, "after QuickSort");

	return 0;
}