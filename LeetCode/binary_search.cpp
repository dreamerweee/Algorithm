#include <iostream>
#include <vector>

using namespace std;

bool BinarySearch(const vector<int> &arr, int key)
{
    int len = arr.size();
    int left = 0, right = len - 1;
    int mid;
    while (left <= right) {
        mid = (left + right) / 2;
        if (arr[mid] > key) {
            right = mid - 1;
        } else if (arr[mid] < key) {
            left = mid + 1;
        } else {
            return true;
        }
    }
    return false;
}

int main(void)
{
    vector<int> arr{0,1};
    if (BinarySearch(arr, 2)) {
        cout << "exist." << endl;
    } else {
        cout << "not find." << endl;
    }
    return 0;
}