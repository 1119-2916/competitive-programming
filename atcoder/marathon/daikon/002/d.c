#include <stdio.h>

int main(void)
{
    int i, num, count;

    for (num = 2; num < 1000; num++) {
        count = 0;
        for (i = 1; i < num; i++) {
            if (!(num % i)) {
                count++;
            }
        }
        if (count > 20) {
            printf("%d %d\n", num, count);
        }
    }

    return 0;
}
