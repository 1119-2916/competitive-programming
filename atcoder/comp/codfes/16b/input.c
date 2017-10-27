#include <stdio.h>

int main(void)
{
    int i, j;

    puts("100000 100000");

    for (i = 0; i < 100000; i++) {
        puts("100000000");
    }
    for (i = 0; i < 100000; i++) {
        puts("100000000");
    }

    return 0;
}
