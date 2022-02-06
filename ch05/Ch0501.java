package ch05;

public class Ch0501 {
    static void swap(int[] a, int i, int j) {
        int t = a[i];
        a[i] = a[j];
        a[j] = t;
    }
    static int partition(int[] a, int p, int r) {
        int x = a[r];
        int i = p - 1;
        for (int j=p; j<=r-1; j++) {
            if (a[j] <= x) {
                i++;
                swap(a, i, j);
            }
        }
        swap(a, i+1, r);
        return i+1;
    }

    static int select(int[] a, int p, int r, int i) {
        if (p == r) {
            return a[p];
        }
        int q = partition(a, p, r);
        int k = q-p+1;
        if (i < k) {
            return select(a, p, q-1, i);
        } else if (i == k) {
            return a[q];
        } else {
            return select(a, q+1, r, i);
        }
    }
    public static void main(String[] args) {
        int n = 10;
        int a[] = {31, 8, 48, 73, 11, 3, 20, 29, 65, 15};
        System.out.println(select(a, 0, n-1, 1));
    }
}
