#include <stdio.h>

int main(void)
{
    int i;

    printf("10 100 500 1 100\n");
    for (i = 0; i < 500; i++) {
        printf ("%d %d %d\n", i % 100 + 1, (i + 1) % 100 + 1, 10000);
    }
    return 0;
}
