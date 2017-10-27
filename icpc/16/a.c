#include <stdio.h>
#include <stdlib.h>
#define min(a, b) a<b?a:b
#define INF 1010001000

int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int main(void)
{
    int i, n, a[1003], ans;
    scanf("%d", &n);
    while (n) {
        ans = INF;
        for (i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        qsort(a, n, sizeof(int), cmp);
        for (i = 1; i < n; i++) {
            ans = min(ans, a[i]-a[i-1]);
        }
        printf("%d\n", ans);
        scanf("%d", &n);
    }
    return 0;
}


