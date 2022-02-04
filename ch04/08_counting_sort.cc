#include <iostream>

using namespace std;

void CountingSort(int *a, int *b, int n, int k) {
    int c[k+1];
    for (int i=1; i<=k; i++) {
        c[i]=0;
    }
    for (int j=0; j<n; j++) {
        c[a[j]]++;
    }
    for (int i=2; i<=k; i++) {
        c[i] = c[i] + c[i-1];
    }
    for (int j=n-1; j>=0; j--) {
        b[c[a[j]]] = a[j];
        c[a[j]]--;
    }
}

void Print(int *a, int n) {
    for (int i=1; i<=n; i++) {
        cout << a[i] << " ";
    }
    cout << "\n";
}

int main() {
    int n=10;
    int k=5;
    int a[]={3, 1, 2, 4, 1, 2, 5, 1, 4, 2};
    int b[n+1];
    CountingSort(a, b, n, k);
    Print(b, n);
    return 0;
}