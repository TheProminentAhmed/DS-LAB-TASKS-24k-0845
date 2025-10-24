#include <iostream>
#include <ctime>
using namespace std;

int comparisons = 0;

void swapElements(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int partition(int arr[], int low, int high, int pivotIndex) {
    swapElements(arr[pivotIndex], arr[high]);
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        comparisons++;
        if (arr[j] <= pivot) {
            i++;
            swapElements(arr[i], arr[j]);
        }
    }
    swapElements(arr[i + 1], arr[high]);
    return i + 1;
}

int pivotFirst(int low, int high) {
    return low;
}

int pivotMiddle(int low, int high) {
    return (low + high) / 2;
}

int pivotPseudoRandom(int low, int high, int step) {
    int range = high - low + 1;
    int pseudo = (low + (step * 3 + 7)) % range;
    return low + pseudo;
}

int pivotMedian(int arr[], int low, int high) {
    int mid = (low + high) / 2;
    int a = arr[low], b = arr[mid], c = arr[high];
    if ((a <= b && b <= c) || (c <= b && b <= a))
        return mid;
    else if ((b <= a && a <= c) || (c <= a && a <= b))
        return low;
    else
        return high;
}

void quickSort(int arr[], int low, int high, int pivotType, int step = 1) {
    if (low < high) {
        int pivotIndex;
        switch (pivotType) {
            case 1: pivotIndex = pivotFirst(low, high); break;
            case 2: pivotIndex = pivotPseudoRandom(low, high, step); break;
            case 3: pivotIndex = pivotMiddle(low, high); break;
            case 4: pivotIndex = pivotMedian(arr, low, high); break;
            default: pivotIndex = pivotFirst(low, high);
        }
        int pi = partition(arr, low, high, pivotIndex);
        quickSort(arr, low, pi - 1, pivotType, step + 1);
        quickSort(arr, pi + 1, high, pivotType, step + 1);
    }
}

void copyArray(int src[], int dest[], int n) {
    for (int i = 0; i < n; i++)
        dest[i] = src[i];
}

void displayArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

