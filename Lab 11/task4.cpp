#include <iostream>
using namespace std;

struct Pair {
    int a,b;
    bool filled;
};

int main() {
    int arr[] = {3,4,7,1,2,9,8};
    int n = 7;
    Pair sumTable[2000];
    for(int i=0;i<2000;i++) sumTable[i].filled=false;

    for(int i=0;i<n;i++) {
        for(int j=i+1;j<n;j++) {
            int s = arr[i] + arr[j];
            if(sumTable[s].filled) {
                cout<<"("<<sumTable[s].a<<","<<sumTable[s].b<<") and ("<<arr[i]<<","<<arr[j]<<")";
                return 0;
            }
            sumTable[s].a = arr[i];
            sumTable[s].b = arr[j];
            sumTable[s].filled = true;
        }
    }
    cout<<"No pairs found";
}
