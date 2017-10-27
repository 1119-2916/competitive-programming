#include <stdio.h>

int main(void)
{
    int i;

    puts("100000");

    for (i = 0; i < 100000; i++) {
        printf("%d\n",100000 - i);
    }

    return 0;
}
