#include <iostream>
#include <cmath>

using namespace std;

void Swap(int *a, int i, int j) {
    int t = a[i];
    a[i] = a[j];
    a[j] = t;
}

void Heapify(int *a, int k, int n) {
    int l = 2 * k;
    int r = 2 * k + 1;
    int smaller;
    if (r <= n) {
        if (a[l] < a[r]) {
            smaller = l;
        } else {
            smaller = r;
        }
    } else if (l <= n) {
        smaller = l;
    } else {
        return;
    }
    if (a[smaller] < a[k]) {
        Swap(a, smaller, k);
        Heapify(a, smaller, n);
    }
}

void BuildHeap(int *a, int n) {
    for (int i=floor(n/2); i>=1; --i) {
        Heapify(a, i, n);
    }
}

void HeapSort(int *a, int n) {
    BuildHeap(a, n);
    for (int i=n; i>=2; i--) {
        Swap(a, 1, i);
        Heapify(a, 1, i-1);
    }
}

void Print(int *a, int n) {
    for (int i=n; i>=1; i--) {
        cout << a[i] << " ";
    }
    cout << "\n";
}

int main() {
    int n=6;
    int a[] = {-1, 3, 6, 4, 8, 9, 7};
    HeapSort(a, n+1);
    Print(a, n);
    return 0;
}