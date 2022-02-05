#include <iostream>

using namespace std;

void InsertionSort(int *a, int n) {
    for (int i=1; i<=n-1; i++) {
        int loc = i-1;
        int newItem = a[i];
        while (loc >= 0 && newItem < a[loc]) {
            a[loc+1] = a[loc];
            loc--;
        }
        a[loc+1] = newItem;
    }
}

void Print(int *a, int n) {
    for (int i=0; i<n; i++) {
        cout << a[i] << " ";
    }
    cout << "\n";
}

int main() {
    int n=10;
    int a[] = {3, 31, 48, 73, 8, 11, 20, 29, 65, 15};
    InsertionSort(a, n);
    Print(a, n);
    return 0;
}