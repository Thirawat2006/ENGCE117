#include <stdio.h>
#include <string.h>

void reverse (char str1[], char str2[]);

int main() {
    char text[50] = "Hello World";
    char out[50];
    reverse(text, out);

    printf("%s\n", out);

    return 0;
}

void reverse (char *text, char *out) {
    int count = strlen(text);
    for (int i = 0; i < count; i++) {
        out[i] = text[count - 1 - i];
    }
    out[count] = '\0';
}
