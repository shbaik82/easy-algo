package ch05;

import java.util.Arrays;

public class Ch0502 {
    static void swap(int a[], int i, int j) {
        int t = a[i];
        a[i] = a[j];
        a[j] = t;
    }

    static int partition(int[] a, int p, int r, int m) {
        swap(a, r, m);
        int x = a[r];
        int i = p-1;
        for (int j=p; j<=r-1; j++) {
            if (a[j]<=x) {
                i++;
                swap(a, i, j);
            }
        }
        swap(a, i+1, r);
        return i+1;
    }

    static void sort(int[] a, int p, int r) {

    }

    static int select(int[] a, int p, int r, int i) {
        if (r-p+1 <= 5) {
            Arrays.sort(a);
            return a[i-1];
        }
        int g = (int)Math.ceil((r-p+1)/5.0);
        int m = ((g/2)-1)*5; 
        int q = partition(a, p, r, m);
        int k = q-p+1;
        if (i<=k) {
            return select(a, p, q-1, i);
        } else {
            return select(a, q+1, r, i);
        }
    }

    public static void main(String[] args) {
        int n = 19;
        int a[] = {81, 31, 83, 8, 97, 48, 100, 73, 105, 11, 107, 3, 20, 121, 29, 65, 142, 15, 135};
        System.out.println(select(a, 0, n-1, 3));
    }
}
