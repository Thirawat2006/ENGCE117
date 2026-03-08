#include <stdio.h>
#include <stdlib.h>

int KnapsackBT(int *w, int *v, int n, int wx, int i, int *x);

int main() {

    int n = 5, wx = 11;
    int w[5] = {1, 2, 5, 6, 7};
    int v[5] = {1, 6, 18, 22, 28};
    int *x, vx;

    x = (int *)malloc(n * sizeof(int));
    
    vx = KnapsackBT(w, v, n, wx, 0, x);

    printf("Value = %d\n", vx); 
    for (int i = 0; i < n; i++) {
        printf("%d ", x[i]);
    }

    free(x);
    return 0;
}

int KnapsackBT(int *w, int *v, int n, int wx, int i, int *x) {
    int b = 0; 
    int y[n];  
    
    for (int k = 0; k < n; k++) x[k] = 0;

    for (int k = i; k < n; k++) {
        if (w[k] <= wx) {
            int a = v[k] + KnapsackBT(w, v, n, wx - w[k], k + 1, y);
            
            if (a > b) {
                b = a; 
                
                for (int j = 0; j < n; j++) x[j] = y[j];
                x[k] = 1; 
            }
        }
    }

    return b;
}
