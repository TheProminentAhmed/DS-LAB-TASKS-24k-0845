#include <iostream>
using namespace std;

int getMax(int arr[], int n) {
    int maxVal = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > maxVal)
            maxVal = arr[i];
    return maxVal;
}

void countingSort(int arr[], int n, int exp, bool ascending) {
    int output[10000];
    int count[10] = {0};
    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;
    if (ascending) {
        for (int i = 1; i < 10; i++)
            count[i] += count[i - 1];
    } else {
        for (int i = 8; i >= 0; i--)
            count[i] += count[i + 1];
    }
    for (int i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixSort(int arr[], int n, bool ascending = true) {
    int maxVal = getMax(arr, n);
    for (int exp = 1; maxVal / exp > 0; exp *= 10)
        countingSort(arr, n, exp, ascending);
}

void display(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Original Array:\n";
    display(arr, n);
    radixSort(arr, n, true);
    cout << "\nSorted in Ascending Order:\n";
    display(arr, n);
    radixSort(arr, n, false);
    cout << "\nSorted in Descending Order:\n";
    display(arr, n);
    return 0;
}
