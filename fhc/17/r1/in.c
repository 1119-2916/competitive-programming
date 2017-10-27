#include <stdio.h>

int main(void)
{
    int i, j, k;
    puts("100");
    
    for (i = 0; i < 100; i++) {
        puts("100 5000 5000");
        for (j = 0; j < 5000; j++) {
            printf("%d %d %d\n", (j+i+j)%100 + 1, (j+1+i)%100 + 1, 1000);
        }
        for (j = 0; j < 5000; j++) {
            printf("%d %d\n", (j+i)%100 + 1, (j*j+i)%100 + 1);
        }
    }

    return 0;
}

