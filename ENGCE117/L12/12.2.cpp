#include <stdio.h>
#include <stdlib.h>

int *KnapsackGreedy( int *w, int *v, int n, int wx );

int main() {
    int n = 5, wx = 11; 
    int w[ 5 ] = { 1, 2, 5, 6, 7 }; 
    int v[ 5 ] = { 1, 6, 18, 22, 28 }; 
    
    int *x = KnapsackGreedy( w, v, n, wx );
    
    for( int i = 0; i < n; i++ ) printf( "%d ", x[ i ] );
    
    return 0;
}

int *KnapsackGreedy( int *w, int *v, int n, int wx ) {
    int *x = (int *)calloc(n, sizeof(int));
    int weight = 0;
    int order[] = {4, 3, 2, 1, 0}; 

    for (int j = 0; j < n; j++) {
        int i = order[j]; 
        if (weight + w[i] <= wx) {
            x[i] = 1; 
            weight = weight + w[i];
        }
    }
    return x;
}
