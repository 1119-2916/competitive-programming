#include <stdio.h>

int main(void)
{
    int r, c, n, i, j, x, y, z;
    scanf("%d %d %d", &r, &c, &n);

    for (i = 0; i < n ;i++) {
        scanf("%d %d %d", &x, &y, &z);
    }


    if (x < 10000 && y < 10000) {
        puts("Yes");
    } else {
        puts("No");
    }
    return 0;
}
