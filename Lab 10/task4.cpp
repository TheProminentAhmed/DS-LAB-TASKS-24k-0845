#include <iostream>
using namespace std;

void swap(int &a, int &b) {
    int t=a; a=b; b=t;
}

void maxHeapify(int arr[], int n, int i) {
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < n && arr[l] > arr[largest]) largest = l;
    if (r < n && arr[r] > arr[largest]) largest = r;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        maxHeapify(arr, n, largest);
    }
}

void convertMinToMax(int arr[], int n) {
    for (int i = (n/2)-1; i >= 0; i--) maxHeapify(arr, n, i);
}

int main() {
    int arr[10] = {3,5,9,6,8,20,10,12,18,9};
    convertMinToMax(arr, 10);

    for (int i = 0; i < 10; i++) cout << arr[i] << " ";
}

