#include <iostream>
using namespace std;

int heapArr[100];
int heapSize = 0;

void swap(int &a, int &b) {
    int t = a; a = b; b = t;
}

void heapifyUp(int i) {
    while (i > 0) {
        int p = (i - 1) / 2;
        if (heapArr[p] > heapArr[i]) {
            swap(heapArr[p], heapArr[i]);
            i = p;
        } else break;
    }
}

void heapifyDown(int i) {
    while (true) {
        int l = 2*i + 1;
        int r = 2*i + 2;
        int smallest = i;

        if (l < heapSize && heapArr[l] < heapArr[smallest]) smallest = l;
        if (r < heapSize && heapArr[r] < heapArr[smallest]) smallest = r;

        if (smallest != i) {
            swap(heapArr[i], heapArr[smallest]);
            i = smallest;
        } else break;
    }
}

void insertKey(int val) {
    heapArr[heapSize] = val;
    heapifyUp(heapSize);
    heapSize++;
}

void update_key(int i, int new_val) {
    int old = heapArr[i];
    heapArr[i] = new_val;

    if (new_val < old) heapifyUp(i);
    else heapifyDown(i);
}

void delete_index(int i) {
    heapArr[i] = heapArr[heapSize - 1];
    heapSize--;
    heapifyDown(i);
}

int main() {
    int a[5] = {8,7,6,5,4};
    for (int i = 0; i < 5; i++) insertKey(a[i]);

    update_key(2, 1);
    delete_index(2);

    for (int i = 0; i < heapSize; i++) cout << heapArr[i] << " ";
    return 0;
}

