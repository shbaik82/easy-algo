#include <iostream>

using namespace std;

void Swap(int *a, int i, int j) {
    int t = a[i];
    a[i] = a[j];
    a[j] = t;
}

int Partition(int *a, int p, int r) {
    int x = a[r];
    int i = p-1;
    for (int j=p; j<=r-1; j++) {
        if (a[j] <= x) {
            Swap(a, ++i, j);
        }
    }
    Swap(a, ++i, r);
    return i;
}

void Print(int *a, int n) {
    for (int i=0; i<n; i++) {
        cout << a[i] << " ";
    }
    cout << "\n";
}

void QuickSort(int *a, int p, int r) {
    if (p < r) {
        int q = Partition(a, p, r);
        QuickSort(a, p, q-1);
        QuickSort(a, q+1, r);
    }
}

int main() {
    int n = 10;
    int a[] = {31, 8, 48, 73, 11, 3, 20, 29, 65, 15};
    QuickSort(a, 0, n-1);
    Print(a, n);
}