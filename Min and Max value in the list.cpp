#include <stdio.h>
struct Pair {
    int min;
    int max;
};
struct Pair findMinMax(int arr[], int low, int high) {
    struct Pair result, left, right;
    int mid;
    if (low == high) {
        result.min = arr[low];
        result.max = arr[low];
        return result;
    }
    if (high == low + 1) {
        if (arr[low] < arr[high]) {
            result.min = arr[low];
            result.max = arr[high];
        } else {
            result.min = arr[high];
            result.max = arr[low];
        }
        return result;
    }
    mid = (low + high) / 2;
    left = findMinMax(arr, low, mid);
    right = findMinMax(arr, mid + 1, high);
    if (left.min < right.min)
        result.min = left.min;
    else
        result.min = right.min;

    if (left.max > right.max)
        result.max = left.max;
    else
        result.max = right.max;

    return result;
}
int main() {
    int arr[] = {3, 1, 7, 9, 2, 4, 8, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    struct Pair result = findMinMax(arr, 0, n - 1);
    printf("Minimum value: %d\n", result.min);
    printf("Maximum value: %d\n", result.max);
    return 0;
}

