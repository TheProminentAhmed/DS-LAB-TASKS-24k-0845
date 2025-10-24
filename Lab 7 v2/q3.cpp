#include <iostream>
#include <string>
using namespace std;

struct Runner {
    string name;
    int time;
};

void merge(Runner arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    Runner L[10], R[10];
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i].time <= R[j].time)
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }
    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];
}

void mergeSort(Runner arr[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    Runner runners[10];
    cout << "Enter name and finish time in seconds for 10 participants:\n";
    for (int i = 0; i < 10; i++)
        cin >> runners[i].name >> runners[i].time;
    mergeSort(runners, 0, 9);
    cout << "\nTop 5 fastest runners:\n";
    for (int i = 0; i < 5; i++)
        cout << runners[i].name << " " << runners[i].time << "s\n";
    return 0;
}
