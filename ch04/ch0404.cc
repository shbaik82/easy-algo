#include <iostream>
#include <cmath>

using namespace std;

void Merge(int *a, int p, int q, int r) {
    int i = p;
    int j = q+1;
    int t = 0;
    int *tmp = new int[r-p+1];
    while (i <= q && j <= r) {
        if (a[i] < a[j]) {
            tmp[t++] = a[i++];
        } else {
            tmp[t++] = a[j++];
        }
    }
    while (i <= q) {
        tmp[t++] = a[i++];
    }
    while (j <= r) {
        tmp[t++] = a[j++];
    }
    i=p;
    t=0;
    while (i<=r) {
        a[i++] = tmp[t++];
    }
    delete[] tmp;
}

void MergeSort(int *a, int p, int r) {
    if (p < r) {
        int q = floor((p+r)/2);
        MergeSort(a, p, q);
        MergeSort(a, q+1, r);
        Merge(a, p, q, r);
    }
}

void Print(int *a, int n) {
    for (int i=0; i<n; i++) {
        cout << a[i] << " ";
    }
    cout << "\n";
}

int main() {
    int n = 10;
    int a[] = {3, 8, 31, 65, 73, 11, 15, 20, 29, 48};
    MergeSort(a, 0, n-1);
    Print(a, n);
    return 0;
}