#include <stdio.h> 
#include <stdlib.h>

int *Getset( int * ) ;

int main() {
    int *data , num ;
    data = Getset(&num) ;
    if( data == NULL ) {
        return 1 ;
    }
    printf( "number collect: \n" ) ;
    for(int i = 0 ; i < num ; i++ ) {
        printf( "%d " , data[i] ) ;
    }

    free ( data ) ;

    return 0 ;
}

int *Getset( int *N ) {
    int *Arr ;
    int i ;
    printf( "Enter Data size \n" ) ;
    scanf("%d", N) ;
    Arr = ( int * ) malloc ( *N * sizeof(int) ) ;
    if (Arr == NULL ) {
        exit(0) ;
    }

    for(i = 0 ; i < *N ; i ++ ) {
        if(scanf("%d" , &Arr[i] ) != 1 ) {
            free( Arr ) ;
            return NULL ;
        }
    }

    return Arr ;
}
