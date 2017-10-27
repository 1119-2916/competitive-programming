#include <stdio.h>

int num[10], n, k;

int check(a)
int a;
{   int i, j, tmp;
    while (a) {
        tmp = a % 10;
        a /= 10;
        if (num[tmp]) {
            return 0;
        }
    }
    return 1;
}

int main(void)
{   int i, j, tmp;

    scanf("%d%d", &n, &k);
    for (i = 0; i < k; i++) {
        scanf("%d", &tmp);
        num[tmp] = 1;
    }

    for (i = n; i < 100000; i++) {
        if (check(i)) {
            printf("%d\n", i);
            return 0;
        }
    }
    return 0;
}

