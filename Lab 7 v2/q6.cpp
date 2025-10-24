#include <iostream>
using namespace std;

int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

void countingSort(int arr[], int n, int exp) {
    int output[20];
    int count[10] = {0};

    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixSort(int arr[], int n) {
    int max = getMax(arr, n);
    for (int exp = 1; max / exp > 0; exp *= 10)
        countingSort(arr, n, exp);
}

int main() {
    int arr1[10] = {23, 45, 12, 9, 87, 34, 76, 54, 21, 30};
    int arr2[10] = {10, 3, 67, 99, 25, 47, 15, 60, 89, 50};
    int combined[20];

    for (int i = 0; i < 10; i++)
        combined[i] = arr1[i];
    for (int i = 0; i < 10; i++)
        combined[10 + i] = arr2[i];

    int n = 20;

    radixSort(combined, n);

    cout << "Sorted Array using Radix Sort: ";
    for (int i = 0; i < n; i++)
        cout << combined[i] << " ";
    cout << endl;

    return 0;
}
