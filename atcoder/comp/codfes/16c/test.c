#include <stdio.h>

int main(void)
{
    int i;

    printf("100000\n");

    for (i = 0; i < 200000; i++) {
        puts("1000000000");
    }
    return 0;
}
