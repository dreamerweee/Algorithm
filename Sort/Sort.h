#ifndef SORT_H
#define SORT_H

#include <vector>

using namespace std;

typedef vector<int>::size_type s_type;

static void Swap(int &x, int &y)
{
	int temp = x;
	x = y;
	y = temp;
}

// 冒泡排序
void BubbleSort(vector<int> &arr)
{
	s_type len = arr.size();
	if (len < 2)
		return;

	for (s_type i = 1; i < len; ++i) {
		for (s_type j = 0; j < len - i; ++j) {
			if (arr[j] > arr[j + 1])
				Swap(arr[j], arr[j + 1]);
		}
	}
}

// 插入排序
void InsertSort(vector<int> &arr)
{
	s_type len = arr.size();
	if (len < 2)
		return;

	for (s_type i = 1; i < len; ++i) {
		int curr = arr[i];
		s_type j = i;
		while (j > 0 && curr < arr[j - 1]) {
			arr[j] = arr[j - 1];
			--j;
		}
		arr[j] = curr;
	}
}

// 选择排序
void SelectSort(vector<int> &arr)
{
	s_type len = arr.size();
	if (len < 2)
		return;

	for (s_type i = 0; i < len - 1; ++i) {
		s_type min_idx = i;
		for (s_type j = i + 1; j < len; ++j) {
			if (arr[j] < arr[min_idx])
				min_idx = j;
		}
		if (i != min_idx)
			Swap(arr[i], arr[min_idx]);
	}
}

// 希尔排序
void ShellSort(vector<int> &arr)
{
	s_type len = arr.size();
	if (len < 2)
		return;

	s_type gap = len / 2; // 希尔增量
	while (gap >= 1) {
		for (s_type i = gap; i < len; ++i) {
			s_type j = i;
			int curr = arr[i];
			while (j >= gap && curr < arr[j - gap]) {
				arr[j] = arr[j - gap];
				j -= gap;
			}
			arr[j] = curr;
		}
		gap = gap / 2;
	}
}

// 归并排序  begin
static void MergeSort(vector<int> &arr, vector<int> &temp, s_type left, s_type right)
{
	if (left >= right)
		return;
	s_type mid = (left + right) / 2;
	MergeSort(arr, temp, left, mid);
	MergeSort(arr, temp, mid + 1, right);
	s_type i = left, j = mid + 1;
	s_type t_idx = left;
	while (i <= mid || j <= right) {
		if (i <= mid && j <= right) {
			if (arr[i] <= arr[j]) {
				temp[t_idx] = arr[i];
				++i;
			} else {
				temp[t_idx] = arr[j];
				++j;
			}
			++t_idx;
		} else if (i <= mid) {
			temp[t_idx++] = arr[i++];
		} else {
			temp[t_idx++] = arr[j++];
		}
	}
	for (i = left; i <= right; ++i) {
		arr[i] = temp[i];
	}
}

void MergeSort(vector<int> &arr)
{
	s_type len = arr.size();
	if (len < 2)
		return;
	vector<int> temp(len);
	MergeSort(arr, temp, 0, len - 1);
}
// 归并排序  end

// 快速排序 begin

void QuickSort(vector<int> &arr, s_type left, s_type right)
{
	if (left >= right)
		return;

	int pivot_val = arr[left];  // 最左边的元素作为分区点
	s_type i = left;
	s_type j = right;
	while (i < j) {
		while (j > i && arr[j] >= pivot_val)
			--j;
		arr[i] = arr[j];
		while (i < j && arr[i] <= pivot_val)
			++i;
		arr[j] = arr[i];
	}
	arr[i] = pivot_val;

	QuickSort(arr, left, i);
	QuickSort(arr, i + 1, right);
}

void QuickSort(vector<int> &arr)
{
	s_type len = arr.size();
	if (len < 2)
		return;
	QuickSort(arr, 0, len - 1);
}

// 快速排序 end

#endif //SORT_H