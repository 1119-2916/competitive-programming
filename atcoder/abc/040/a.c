#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define min(a, b) a<b?a:b
#define max(a, b) a>b?a:b
#define INF 1010001000
#define eps 0.000000001
#define mod 1000000007
#define MAX_N 1001

int road[MAX_N][MAX_N], n, m;
int used[MAX_N];

void dfs(int pos, int year);

int main(void)
{
    int i, ans, j, pos, year, f, t, d, q;
    scanf("%d %d", &n, &m);
    if (n > 1005) { 
        return 0;
    }
    for (i = 0; i < m; i++) {
        scanf("%d %d %d", &f, &t, &d);
        road[f][t] = max(road[f][t], d);
        road[t][f] = max(road[t][f], d);
    }
    scanf("%d", &q);
    for (i = 0; i < q; i++) {
        for (j = 0; j <= n; j++) {
            used[j] = 0;
        }
        ans = 0;
        scanf("%d %d", &pos, &year);
        dfs(pos, year);
        for (j = 1; j <= n; j++) {
            ans += used[j];
        }
        printf("%d\n", ans);
    }
    return 0;
}

void dfs(int pos, int year)
{
    int i;
    used[pos] = 1;
    for (i = 1; i <= n; i++) {
        if (road[pos][i] > year && !used[i]) {
            dfs(i, year);
        }
    }
}
            


