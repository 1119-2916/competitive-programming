#include <stdio.h>

int main(void)
{
    int i, j;

    for (i = 1000; i < 3000; i++) {
        for (j = 1000; j < 2000; j++) {
            printf("%d %d\n",i,j);
        }
    }
    return 0;
}

