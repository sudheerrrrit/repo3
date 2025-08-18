#include <bits/stdc++.h>
using namespace std;

int partition(vector<int>& arr, int left, int right) {
    int pivot = arr[left];
    int i = left + 1;
    int j = right;

    while (i <= j) {
        while (i <= right && arr[i] <= pivot) i++;
        while (arr[j] > pivot) j--;

        if (i < j) {
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[left], arr[j]); // place pivot in correct position
    return j; // pivot index
}

void quickSortHelper(vector<int>& arr, int left, int right) {
    if (left >= right) return;

    int pi = partition(arr, left, right);
    quickSortHelper(arr, left, pi - 1);
    quickSortHelper(arr, pi + 1, right);
}

vector<int> quickSort(vector<int> arr) {
    quickSortHelper(arr, 0, arr.size() - 1);
    return arr;
}
