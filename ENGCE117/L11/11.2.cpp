#include <stdio.h>

void merge( int *u, int m, int *v, int n, int *t ) {
    int i = 0, j = 0; 
    for ( int k = 0; k < m + n; k++ ) { 
        if ( i >= m ) { 
            t[k] = v[j]; j++;
        } else if ( j >= n ) { 
            t[k] = u[i]; i++;
        } else if ( u[i] < v[j] ) { 
            t[k] = u[i]; i++;
        } else { 
            t[k] = v[j]; j++;
        }
    }
}

void mergesort( int t[], int k ) {
    if ( k > 1 ) { 
        int m = k / 2;
        int n = k - m;
        int u[m], v[n];
        
        for ( int i = 0; i < m; i++ ) u[i] = t[i];
        for ( int i = 0; i < n; i++ ) v[i] = t[m + i];
        
        mergesort( u, m ); 
        mergesort( v, n ); 
        merge( u, m, v, n, t ); 
    }
}

int main() {
    int data[ 7 ] = { 4, 6, 1, 2, 5, 1, 8 };
    int n = 7;
    mergesort( data, n );
    for ( int i = 0; i < n; i++ ) printf("%d ", data[i]); 
    return 0;
}
