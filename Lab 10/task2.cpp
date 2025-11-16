
#include <iostream>
using namespace std;

bool isMinHeap(int arr[], int n) {
    for (int i = 0; i <= (n-2)/2; i++) {
        int l = 2*i + 1;
        int r = 2*i + 2;
        if (l < n && arr[i] > arr[l]) return false;
        if (r < n && arr[i] > arr[r]) return false;
    }
    return true;
}

void heapify(int arr[], int n, int i) {
    int smallest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < n && arr[l] < arr[smallest]) smallest = l;
    if (r < n && arr[r] < arr[smallest]) smallest = r;

    if (smallest != i) {
        int t = arr[i]; arr[i] = arr[smallest]; arr[smallest] = t;
        heapify(arr, n, smallest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = (n/2)-1; i >= 0; i--) heapify(arr, n, i);

    for (int i = n-1; i >= 0; i--) {
        int t = arr[0]; arr[0] = arr[i]; arr[i] = t;
        heapify(arr, i, 0);
    }
}

int main() {
    int arr[5] = {8,7,6,5,4};
    int n = 5;

    if (isMinHeap(arr,n)) cout << "Valid min heap\n";
    else cout << "Not a heap\n";

    heapSort(arr,n);

    for (int i=0;i<n;i++) cout << arr[i] << " ";
}
