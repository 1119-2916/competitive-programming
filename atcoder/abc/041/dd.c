#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define INF 1010001000
#define min(a, b) a>b?b:a
#define max(a, b) a>b?a:b

int usa[16];
int graph[16][16];
int dp[1<<16];
int n, m;

int main(void)
{
    int i, j, a, b;
    scanf("%d %d", &n, &m);
    for (i = 0; i < n; i++) {
        usa[i] = n-2;
        ans += (i);
    }
    for (i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        graph[a-1][b-1]= 1;
    }
    dp[0] = 1;
    for (i = 0; i < n; i++) {

    printf("%lld - %lld\n", ans, less);
    return 0;
}
