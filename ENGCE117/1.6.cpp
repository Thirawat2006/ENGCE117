#include <stdio.h>

int *GetMat( int *row, int *col );

int main() {
    int *data;
    int  m , n;
    data = GetMat(&m , &n );
    for ( int i = 0 ; i < m ; i ++ ) {
        for ( int a = 0 ; a < n ; a ++ ) {
            printf("%d " , data[ i * n + a]);
        }
        printf("\n");
    }
    delete[] data;
    return 0;
}

int *GetMat( int *row, int *col ) {
    int *arr;
    int i = 0 , a = 0;
    scanf( "%d %d" , row , col );
    arr = new int[ *row * *col ];
    for ( i = 0 ; i < *row ; i ++ ){
        for (a = 0 ; a < *col ; a ++ ) {
            scanf( "%d" , &arr[ i * *col + a] );
        }
    }
    return arr;
}
