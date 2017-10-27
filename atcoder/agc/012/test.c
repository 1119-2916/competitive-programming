#include <stdio.h>

int main(void)
{
    puts("100000 1000000000 1000000000");
    for (int i = 0; i < 100000; i++) {
       // printf("%d %d\n", i, i);
        printf("1 %d\n", i);
    }
    return 0;
}
