#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 堆化操作
void CreateHeap(vector<int> &arr, int len)
{
    int mid = (len - 1) / 2;
    for (; mid >= 0; --mid) {
        int max_idx = mid;
        int l_child = 2 * mid + 1;
        int r_child = 2 * mid + 2;
        if (l_child < len && arr[max_idx] < arr[l_child]) {
            max_idx = l_child;
        }
        if (r_child < len && arr[max_idx] < arr[r_child]) {
            max_idx = r_child;
        }
        swap(arr[mid], arr[max_idx]);
    }
}

void HeapSort(vector<int> &arr)
{
    int len = arr.size();
    for (int i = len - 1; i > 0; --i) {
        swap(arr[i], arr[0]);
        CreateHeap(arr, i);
    }
}

int main(void)
{
    vector<int> arr;
    int val;
    while (cin >> val) {
        arr.push_back(val);
    }
    
    if (arr.size() > 1) {
        CreateHeap(arr, arr.size());
        HeapSort(arr);
    }
    
    for_each(arr.cbegin(), arr.cend(), [](int val) { cout << val << " ";});
    cout << endl;

    return 0;
}
