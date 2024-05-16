#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int matrixchain(int p[], int n) {
    int i, j, k, d, q, min;
    int m[n][n];
    int s[n][n];
    
    for(i = 0; i < n; i++) {
        m[i][i] = 0;
        s[i][i] = 0;
    }

    for(d = 1; d < n - 1; d++) {
        for(i = 1; i < n - d; i++) {
            j = i + d;
            min = INT_MAX;
            for(k = i; k <j; k++) {
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if(q < min) {
                    min = q;
                    s[i][j] = k;
                }
            }
            m[i][j] = min;
        }
    }
    
    return m[1][n - 1];
}

int main() {
    int i, n;
    printf("Enter the number of matrices: ");
    scanf("%d", &n);
    int *p = (int*)malloc((n + 1) * sizeof(int));
    printf("Enter the dimensions of the matrices: ");
    for(i = 0; i <= n; i++) {
        scanf("%d", &p[i]);
    }
    printf("The minimum number of scalar multiplications is %d\n", matrixchain(p, n + 1));
    free(p);
    return 0;
}
 
