#include <stdio.h>

void swap(int *p1, int *p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int partition(int arr[], int low, int high) {
	int j;
    int pivot = arr[high];
    int i = low - 1;

    for (j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]); 
        }
    }
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1);
}

void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); 
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

int main() {
    int n,i;

    printf("Enter the number of elements: \n");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the elements: \n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
  	
    quicksort(arr, 0, n - 1);

    printf("Sorted array: \n");
    for ( i = 0; i < n; i++) {
        printf("%d\n", arr[i]);
    }

    return 0;
}
