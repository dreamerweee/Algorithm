#include <stdio.h>

void Swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int Partition(int *arr, int left, int right)
{
    int part_val = arr[right];
    int i = left;
    int j = left;
    for ( ; j < right; ++j) {
        if (arr[j] < part_val) {
            Swap(&arr[i], &arr[j]);
            ++i;
        }
    }
    Swap(&arr[i], &arr[j]);
    return i;
}

void QuickSort(int *arr, int left, int right)
{
    if (left >= right) {
        return;
    }
    int partition = Partition(arr, left, right);
    QuickSort(arr, left, partition - 1);
    QuickSort(arr, partition + 1, right);
}

int main(void)
{
    int arr[] = {7,6};
    QuickSort(arr, 0, 1);
    for (int i = 0; i < 2; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
