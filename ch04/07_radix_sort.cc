#include <iostream>
#include <queue>

using namespace std;

void RadixSort(int *a, int n, int k) {
    queue<int> q[10];
    for (int i=0; i<k; i++) {
        for (int j=0; j<n; j++) {
            int d=pow(10, i);
            int r;
            if (a[j] < d) {
                r=0;
            } else {
                r = (a[j] / d) % 10;
            }
            q[r].push(a[j]);
        }
        int j=0;
        for (int r=0; r<10; r++) {
            while (!q[r].empty()) {
                a[j]=q[r].front();
                q[r].pop();
                j++;
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
    int n=8;
    int k=4;
    int a[]={123, 2154, 222, 4, 283, 1560, 1061, 2150};
    RadixSort(a, n, k);
    Print(a, n);
    return 0;
}