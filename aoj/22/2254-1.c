#include <stdio.h>
#define INF 1010001000
#define min(a, b) a<b?a:b
#define MAX_V 10001

int cost[MAX_V][MAX_V];
int used[MAX_V], mincost[MAX_V];
int V;

int prim(void);

int main(void)
{
    int i, j, f, t, d, min, st1, st2;
    scanf("%d", &V);
    while (V) {
        min = INF;
        st1 = 0;
        st2 = 1;
        for (i = 0; i <= V; i++) {
            cost[0][i] = INF;
        }
        for (i = 1; i <= V; i++) {
            for (j = 0; j <= V; j++) {
                scanf("%d", &cost[j][i]);
                if (cost[j][i] < min) {
                    min = cost[j][i];
                    st1 = j;
                    st2 = i;
            }
        }
        printf("%d\n", prim());
        scanf("%d", &V);
    }
    return 0;
}

int prim(void)
{
    int i, j, res, p;
    for (i = 0; i <= V; i++) {
        mincost[i] = INF;
        used[i] = 0;
    }
    mincost[0] = 0;
    res = 0;

    while (1) {
        p = -1;
        for (i = 0; i <= V; i++) {
            if (!used[i] && (p == -1 || mincost[i] < mincost[p])) {
                p = i;
            }
        }
        if (p == -1) {
            break;
        }
        used[p] = 1;
        printf("add:%d\n", mincost[p]);
        res += mincost[p];

        for (i = 0; i <= V; i++) {
            mincost[i] = min(mincost[i], cost[p][i]);
        }
    }
    return res;
}



