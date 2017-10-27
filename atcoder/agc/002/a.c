#include <stdio.h>

int main(void)
{
    int a, b;

    scanf("%d %d", &a, &b);

    if (a > 0 && b > 0) {
        b++;
        puts("Positive");
    } else if (a < 0 && b < 0) {
        b++;
        ((b-a)%2)?puts("Negative"):puts("Positive");
    } else {
        puts("Zero");
    }

    return 0;
}

