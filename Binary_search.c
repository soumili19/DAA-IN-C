#include <stdio.h>
//searching//
int binarysearch(int a[], int beg, int end, int val) {
    if (beg <= end) {
        int mid = (beg + end) / 2;
        if (a[mid] == val)
            return mid + 1;
        else if (a[mid] > val)
            return binarysearch(a, beg, mid - 1, val);
        else
            return binarysearch(a, mid + 1, end, val);
    }
    return -1;
}
//main//
int main() {
    int i, n, val;
    printf("Enter the number of elements:\n");
    scanf("%d", &n);
    int a[n];
    printf("Enter the elements in sorted order:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    printf("Enter the element to find:\n");
    scanf("%d", &val);
    int res = binarysearch(a, 0, n - 1, val);
    if (res == -1) {
        printf("Element not found\n");
    } else {
        printf("Element found at index %d\n", res);
    }
    return 0;
}
