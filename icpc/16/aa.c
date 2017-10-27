#include <stdio.h>
#include <stdlib.h>
#define min(a, b) a>b?b:a
#define INF 1010001000
int cmp(const void *a, const void *b) 
{
    return *(int *)a-*(int *)b;
}

int data[1001];

int main(void)
{
    int i, j, n, ans;

    scanf("%d", &n);
    while (n) {
        for (i = 0; i < n; i++) {
            scanf("%d", &data[i]);
        }
        ans = INF;
        qsort(data, n, sizeof(int), cmp);
        for (i = 1; i < n; i++) {
            ans = min(ans, data[i] - data[i-1]);
        }
        printf("%d\n", ans);
        scanf("%d", &n);
    }
    return 0;
}




