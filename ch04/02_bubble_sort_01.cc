#include <iostream>

using namespace std;

void Swap(int *a, int i, int j) {
    int t = a[i];
    a[i] = a[j];
    a[j] = t;
}

void BubbleSort(int *a, int n) {
    for (int last=n-1; last>=1; last--) {
        for (int i=0; i<=last-1; i++) {
            if (a[i] > a[i+1]) {
                Swap(a, i, i+1);
            }
        }
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
    BubbleSort(a, n);
    Print(a, n);
}