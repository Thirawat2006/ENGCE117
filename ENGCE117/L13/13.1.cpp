#include <stdio.h>
#include <stdlib.h>

int *KnapsackDP(int *w, int *v, int n, int wx);

int main() {
    
    int n = 5, wx = 11;
    int w[5] = {1, 2, 5, 6, 7};
    int v[5] = {1, 6, 18, 22, 28};
    int *x;

    x = KnapsackDP(w, v, n, wx);

    for (int i = 0; i < n; i++) {
        printf("%d ", x[i]);
    }

    free(x); 
    return 0;
}


int *KnapsackDP(int *w, int *v, int n, int wx) {
    
    int u[n][wx + 1];
    int y[n][wx + 1][n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= wx; j++) {
            for (int k = 0; k < n; k++) y[i][j][k] = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= wx; j++) {
            
            int a = (i - 1 < 0) ? 0 : u[i - 1][j];
            int b;
            if (j - w[i] < 0) {
                b = -1; 
            } else if (i - 1 < 0) {
                b = v[i];
            } else {
                b = u[i - 1][j - w[i]] + v[i]; 
            }

            if (a > b) {
                u[i][j] = a;
                if (i > 0) {
                    for (int k = 0; k < n; k++) y[i][j][k] = y[i - 1][j][k];
                }
            } else {
                u[i][j] = b;
                if (i > 0 && j - w[i] >= 0) {
                    for (int k = 0; k < n; k++) y[i][j][k] = y[i - 1][j - w[i]][k];
                }
                y[i][j][i] = 1;
            }
        }
    }
    int *result = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        result[i] = y[n - 1][wx][i];
    }
    
    return result;
}
