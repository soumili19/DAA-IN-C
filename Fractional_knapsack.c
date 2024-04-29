#include <stdio.h>

void knapsack(int num, float weight[], float profit[], float capacity) {
    float x[20], tp = 0;
    int i, u, n = num; 
    tp = 0;
    u = capacity;
    for (i = 0; i < n; i++) {
        x[i] = 0.0;
    }
    for (i = 0; i < n; i++) {
        if (weight[i] > u)
            break;
        else {
            x[i] = 1.0;
            tp = tp + profit[i];
            u = u - weight[i];
        }
    }
    if (i < num) { 
        x[i] = u / weight[i];
        tp = tp + (x[i] * profit[i]);
    }
    printf("\nThe present vector is:\n");
    for (i = 0; i < n; i++) {
        printf("%f\t", x[i]);
    }
    printf("\nThe maximum profit is %f", tp);
}

int main() {
    float weight[20], profit[20], capacity, ratio[20];
    int n, i, j, temp;
    printf("\nEnter the number of objects: ");
    scanf("%d", &n); 
    printf("\nEnter the weight and profit of those objects:\n");
    for (i = 0; i < n; i++) {
        scanf("%f %f", &weight[i], &profit[i]);
    }
    printf("\nEnter the capacity of the full knapsack: ");
    scanf("%f", &capacity); 

    for (i = 0; i < n; i++) {
        ratio[i] = profit[i] / weight[i];
    }
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) { 
            if (ratio[i] < ratio[j]) {
                temp = ratio[j];
                ratio[j] = ratio[i];
                ratio[i] = temp;

                temp = weight[j];
                weight[j] = weight[i];
                weight[i] = temp;

                temp = profit[j];
                profit[j] = profit[i];
                profit[i] = temp;
            }
        }
    }
    knapsack(n, weight, profit, capacity); 
    return 0;
}
