#include <stdio.h>

int main(void)
{
    puts("100000");
    for (int i = 1; i < 100001; i++) {
        if (i == 50000) {
            puts("11155");
        }
        printf("%d\n", i);
    }
    return 0;
}

