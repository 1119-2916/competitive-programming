#include <stdio.h>

int main(void)
{
    int i, j;

    for (i = 0, j = 0; i < 12000; i++, j++) {
        if (j == 3600) {
            j = 0;
        } 
        printf("%d %d\n",i, j);
    }
    return 0;
}

