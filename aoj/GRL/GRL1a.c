#include <stdio.h>
#include <stdlib.h>
#define MAX_E 500000
#define MAX_V 100000
#define INF 1010001000

typedef struct edge{
    int from, to, cost;
}edge;

edge es[MAX_E];
int d[MAX_V];
int v, e;

int main(void)
{
    int i, j, r, fl;
    scanf("%d%d%d", &v, &e, &r);

    for (i = 0; i < v; i++) {
        d[i] = INF;
    }

    for (i = 0; i < e; i++) {
        scanf("%d %d %d", &es[i].from, &es[i].to, &es[i].cost);
    }
    d[r] = 0;
    for (j = 0; j < v; j++) {
        fl = 1;
        for (i = 0; i < e; i++) {
            if (d[es[i].from] != INF &&
                    d[es[i].to] > d[es[i].from] + es[i].cost) {
                d[es[i].to] = d[es[i].from] + es[i].cost;
                fl = 0;
            }
        }
        if (fl) {
            break;
        } else if (j == v-1) {
            puts("NEGATIVE CYCLE");
            return 0;
        }
    }
    for (i = 0; i < v; i++) {
        if (d[i] == INF) {
            puts("INF");
        } else {
            printf("%d\n", d[i]);
        }
    }
    return 0;
}

