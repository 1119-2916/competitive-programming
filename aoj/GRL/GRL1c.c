#include <stdio.h>
#define min(a, b) a<b?a:b
#define INF 2110001000

int v, e;
int d[101][101];

int main(void)
{
    int i, j, k, s, t, c;
    scanf("%d %d", &v, &e);
    v;
    for (i = 0; i < v; i++) {
        for (j = 0; j < v; j++) {
            d[i][j] = INF;
        }
        d[i][i] = 0;
    }
    for (i = 0; i < e; i++) {
        scanf("%d %d %d", &s, &t, &c);
        d[s][t] = c;
    }
    for (k = 0; k < v; k++) {
        for (i = 0; i < v; i++) {
            for (j = 0; j < v; j++) {
                if (d[i][k] != INF && d[k][j] != INF) {
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                }
            }
        }
    }
    for (i = 0; i < v; i++) {
        if (d[i][i] < 0) {
            puts("NEGATIVE CYCLE");
            return 0;
        }
    }
    for (i = 0; i < v; i++) {
        if (d[i][0] != INF) {
            printf("%d", d[i][0]);
        } else {
            printf("INF");
        }
        for (j = 1; j < v; j++) {
            if (d[i][j] == INF) {
                printf(" INF");
            } else {
                printf(" %d", d[i][j]);
            }
        }
        puts("");
    }
    return 0;
}
