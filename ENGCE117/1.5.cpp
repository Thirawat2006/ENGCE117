#include <stdio.h>
#include <stdlib.h>

void GetMatrix(int *value[], int *row, int *col);

int main() {
    int *data, m, n;
    GetMatrix(&data, &m, &n);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", data[i * n + j]);
        }
        printf("\n");
    }

    //free allocated memory
    free(data);
    data = NULL;

    return 0;
}

void GetMatrix(int *value[], int *row, int *col) {
    
    scanf("%d %d", row, col);
    *value = (int *)malloc((*row) * (*col) * sizeof(int));
    
    if (*value == NULL) {
        printf("Allocation FAILED.\n");
        exit(0);
    }

    for (int i = 0; i < *row; i++) {
        for (int j = 0; j < * col; j++) {
            scanf("%d", &(*value)[i * (*col) + j]);
        }
    }
}
