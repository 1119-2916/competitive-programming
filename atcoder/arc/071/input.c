#include <stdio.h>

int main(void)
{
    puts("100000 100000");

    for (int i = -100000; i < 100000; i += 2) {
        printf("%d\n", i);
    }
    for (int i = -50000; i < 50000; i++) {
        printf("%d\n", i);
    }
    return 0;
}
