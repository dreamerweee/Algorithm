#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void Merge(vector<int> &arr, vector<int> &tmp, int left, int mid, int right)
{
    int l = left;
    int r = mid + 1;
    int i = left;
    while (l <= mid && r <= right) {
        if (arr[l] <= arr[r]) {
            tmp[i++] = arr[l++];
        } else {
            tmp[i++] = arr[r++];
        }
    }
    while (l <= mid) {
        tmp[i++] = arr[l++];
    }
    while (r <= right) {
        tmp[i++] = arr[r++];
    }
    for (i = left; i <= right; ++i) {
        arr[i] = tmp[i];
    }
}

void MergeSort(vector<int> &arr, vector<int> &tmp, int left, int right)
{
    if (left >= right) {
        return ;
    }
    int mid = (left + right) / 2;
    MergeSort(arr, tmp, left, mid);
    MergeSort(arr, tmp, mid + 1, right);
    Merge(arr, tmp, left, mid, right);
}

int main(void)
{
    vector<int> arr;
    int val;
    while (cin >> val) {
        arr.push_back(val);
    }
    size_t len = arr.size();
    if (len > 1) {
        vector<int> tmp(len);
        MergeSort(arr, tmp, 0, len - 1);
    }

    // 输出结果
    for_each(arr.cbegin(), arr.cend(), [](const int val){ cout << val << " ";});
    cout << endl;

    return 0;
}