#include <stdio.h>

int main(void)
{
    int i, a = 1, b = 1, c = 3;

    for (i = 0; i < 20; i++) {
        printf("%8d  %8d\n",b, a);
        a = a * 2 + 1;
        b *= 2;
        c *= 2;
    }
    return 0;
}
