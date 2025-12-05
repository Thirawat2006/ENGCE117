#include <stdio.h>

int main() {
    int N, i;

    if(scanf("%d",&N) != 1) {
        return 1;
    }

    for (i = 1; i <= N; i++)
    {
        printf("[%d]Hello Word!\n",i);
    }
    
}
