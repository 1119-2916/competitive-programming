#include <stdio.h>
#include <stdlib.h>

int data[101];

int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int main(void)
{
    int i, n, ans = 0;

    scanf("%d", &n);
    for (i = 0; i < 2*n; i++) {
        scanf("%d", &data[i]);
    }

    qsort(data, n*2, sizeof(int), cmp);

    for (i = 0; i < 2*n; i+=2) {
        ans += data[i];
    }

    printf("%d\n", ans);

    return 0;
}


