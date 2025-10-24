#include <iostream>
#include <string>
using namespace std;

class Product {
public:
    string name;
    double price;
    string description;
    bool available;
};

int partition(Product arr[], int low, int high) {
    double pivot = arr[high].price;
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j].price < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(Product arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    Product products[3] = {
        {"Product 1", 10.99, "This is product 1.", true},
        {"Product 2", 5.99, "This is product 2.", false},
        {"Product 3", 2.99, "This is product 3.", true}
    };
    quickSort(products, 0, 2);
    cout << "Products sorted by price:\n";
    for (int i = 0; i < 3; i++)
        cout << products[i].name << " - $" << products[i].price << endl;
    return 0;
}
