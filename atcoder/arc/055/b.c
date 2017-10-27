#include <stdio.h>

int main(void)
{
    double ans = 0;
    int a, n, k, i;
    scanf("%d %d", &n, &k);
    a = n;
    for (i = 0; i < k; i++) {
        ans += (double)(1/((a-1)/2));
        a = (a-1)/2;
    }
    printf("%.10lf\n", ans);
    return 0;
}


