#include <stdio.h>

int main(void)
{
    puts("100");
    for (int i = 0; i < 100; i++) {
        puts("10000 10000 50000");
        for (int j = 0; j < 50000; j++) {
            printf("%d %d %d\n", (i+j) % 10000, (i+j+199) % 10000,
                    (10*j + i * j * 29) % 10000);
        }
    }
    return 0;
}

