#include <stdio.h>

int main(void)
{   int a, b, n, i;

    scanf("%d %d %d", &a, &b, &n);

    if (a == 5 && b == 5 && n == 7) {
        puts("YES");
    } else if (a == 5 && b == 7 && n == 5) {
        puts("YES");
    } else if (a == 7 && b == 5 && n == 5) {
        puts("YES");
    } else {
        puts("NO");
    }


    return 0;
}

