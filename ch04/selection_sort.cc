#include <iostream>

using namespace std;

void Swap(int *a, int i, int j) {
    int t = a[i];
    a[i] = a[j];
    a[j] = t;
}

int FindLargest(int * a, int last) {
    int largest = 0;
    for (int i=1; i<=last; i++) {
        if (a[i] > a[largest]) {
            largest = i;
        }
    }
    return largest;
}

void SelectionSort(int * a, int n) {
    for (int last=n-1; last>=1; last--) {
        int k = FindLargest(a, last);
        Swap(a, k, last);
    }
}

void Print(int *a, int n) {
    for (int i=0; i<n; i++) {
        cout << a[i] << " ";
    }
}

int main() {
    int n = 10;
    int a[] = {8, 31, 48, 73, 3, 65, 20, 29, 11, 15};
    SelectionSort(a, n);
    Print(a, n);
}

