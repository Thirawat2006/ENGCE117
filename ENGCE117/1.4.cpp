#include <stdio.h>

int GetSet(int *array[]);

int main() {
    int *data, num, i;
    num = GetSet(&data);

    printf("\nelements: ");
    for (i = 0; i < num; i++) {
        printf("%d ", data[i]);
    }

    return 0;
}

int GetSet(int *array[]) {
    static int temp[100];
    int i, n;

    printf("Enter of elements: ");
    if (scanf("%d", &n) != 1) n = 0;

    if (n < 0) n = 0;
    if (n > 100) n = 100;

    for (i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        if (scanf("%d", &temp[i]) != 1) temp[i] = 0;
    }

    *array = temp;
    return n;
}
