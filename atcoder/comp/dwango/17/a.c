#include <stdio.h>

int main(void)
{
    int a, b, c;

    scanf("%d %d %d", &a, &b, &c);

    printf("%d\n", (b+c-a > 0) ? b+c-a : 0);

    return 0;
}
