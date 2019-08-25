#include <iostream>
#include <vector>

using namespace std;

static size_t Partition(vector<int> &arr, size_t left, size_t right)
{
	int pivot_val = arr[right];
	size_t i = left, j = right;
	while (i < j) {
		while (i < j && arr[i] >= pivot_val)
			++i;
		arr[j] = arr[i];
		while (j > i && arr[j] <= pivot_val)
			--j;
		arr[i] = arr[j];
	}
	arr[j] = pivot_val;
	return j;
}

static int FindKValue(vector<int> &arr, int key)
{
	int k_val = -1;
	size_t len = arr.size();
	if (key <= 0 || key > len)
		return k_val;

	size_t left = 0, right = len - 1;
	while (true) {
		size_t pivot_pos = Partition(arr, left, right);
		if (pivot_pos == -1)
			break;
		if (key == pivot_pos + 1) {
			k_val = arr[pivot_pos];
			break;
		} else if (key < pivot_pos + 1) {
			right = pivot_pos - 1;
		} else {
			left = pivot_pos + 1;
		}
	}
	return k_val;
}

int main()
{
	int val;
	vector<int> arr;
	while (cin >> val)
		arr.push_back(val);

	cin.clear();
	cout << "Input need find key max value:";
	int key;
	cin >> key;

	int k_val = FindKValue(arr, key);
	cout << key << " max value is:" << k_val << endl;
	return 0;
}