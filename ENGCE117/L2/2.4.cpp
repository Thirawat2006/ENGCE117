#include <stdio.h>
#include <string.h>

void explode(char str1[], char splitter, char str2[][10], int *count);

int main() {
    char out[20][10]; //up to 20 tokens, each up to 9 chars + '\0'
    int num;
    explode("I/Love/You", '/', out, &num);

    for (int i = 0; i < num; i++) {
        printf("%s\n", out[i]);
    }

    printf("Count: %d\n", num);

    return 0;
}

void explode(char str1[], char splitter, char str2[][10], int *count) {
    int j = 0;
    int i = 0;
    *count = 0;

    while (str1[i] != '\0') {
        if(str1[i] == splitter) {
            str2[*count][j] = '\0';
            (*count)++;
            j = 0;
        } else {
           if (j < 9) {
             str2[*count][j++] = str1[i];
           }
        }
        i++;
    }
    str2[*count][j] = '\0';
    (*count)++;
}
