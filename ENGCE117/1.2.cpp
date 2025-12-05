#include <stdio.h>

void Getset( int [] , int *N );

int main() {
    int *data, num;
    Getset ( data, &num );
    return 0;
}

void Getset( int Data[] , int *N ) {

    printf("Enter data ") ;
    scanf( "%d" , N );
    for ( int i = 0 ; i < *N ; i ++ ) {
        printf( "Enter number ");
        scanf("%d" , &Data[i] );
    }

    for(int i = 0 ; i < *N ; i++ ) {
        printf("%2d",Data[i] );
    }

}
