#include <stdio.h>
#include <string.h>

char* reverse(char str1[]);

int main() {
    char text[50] = "Hello World";
    char *out;
    out = reverse(text);
    printf("%s\n", out);

    delete[] out;
    return 0;
}

char *reverse (char *text) {
    int count = strlen(text);
    char *out = new char[count + 1];

    for (int i = 0; i < count; i++) {
        out[i] = text[count - 1 - i];
    }
    out[count] = '\0';

    return out;
}
