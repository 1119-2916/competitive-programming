#include <stdio.h>
#include <stdlib.h>
#define INF 1010001000
#define min(a, b) a<b?a:b
#define MAX_V 20

int prim(void);
int cost[MAX_V][MAX_V];
int used[MAX_V], mincost[MAX_V];
int e;
int V, cost[20][20];

int main(void)
{
    int i, j, k, s, t, ans;
    scanf("%d", &V);
    while (V) {
        for (i = 0; i <= V; i++) {
            cost[i][0] = INF;
        }
        for (i = 1; i <= V; i++) {
            for (j = 0; j <= V; j++) {
                scanf("%d", &cost[j][i]);
            }
        }
        for (i = 0; i <= V; i++) { 
            for (j = 0; j <= V; j++) {
                printf("%d  ", cost[i][j]);
            }
            puts("");
        }
        printf("%d\n", prim());
        scanf("%d", &V);
    }
    return 0;
}

int prim(void)
{
    int i, j, res, p;
    for (i = 0; i < V; i++) {
        mincost[i] = INF;
        used[i] = 0;
    }
    mincost[0] = 0;
    res = 0;

    while (1) {
        p = -1;
        for (i = 0; i < V; i++) {
            if (!used[i] && (p == -1 || mincost[i] < mincost[p])) {
                p = i;
            }
        }
        if (p == -1) {
            break;
        }
        printf("%d\n", p);
        used[p] = 1;
        res += mincost[p];

        for (i = 0; i < V; i++) {
            mincost[i] = min(mincost[i], cost[p][i]);
        }
    }
    return res;
}



