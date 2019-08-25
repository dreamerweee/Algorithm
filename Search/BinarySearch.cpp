#include <iostream>
#include <vector>

using namespace std;

static bool BinarySearch(vector<int> &arr, size_t left, size_t right, int key)
{
	if (left >= right) {
		if (key != arr[left])
			return false;
		else
			return true;
	}

	size_t mid = (left + right) / 2;
	if (key < arr[mid]) {
		return BinarySearch(arr, left, mid - 1, key);
	} else if (key > arr[mid]) {
		return BinarySearch(arr, mid + 1, right, key);
	} else {
		return true;
	}
}

static bool BinarySearch(vector<int> &arr, int key)
{
	return BinarySearch(arr, 0, arr.size() - 1, key);
}

int main()
{
	vector<int> arr{0,1,3};

	int key;
	cin >> key;
	bool res = BinarySearch(arr, key);
	cout << "BinarySearch result: " << boolalpha << res << endl;
	return 0;
}