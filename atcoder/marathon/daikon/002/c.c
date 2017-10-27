#include <stdio.h>

int main(void)
{
    int i, num, count = 0;

    for (num = 998000; num > 0; num--) {
        count = 0;
        for (i = 1; i <= num; i++) {
            if (!(num % i)) {
                count++;
            }
        }
        if (count > 200) {
            printf("puts\(\"");
            printf("%d", num);
            puts("\");");
        }
    }

    return 0;
}
