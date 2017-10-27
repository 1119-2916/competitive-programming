#include <stdio.h>
#define INF 1010001000
#define min(a, b) a<b?a:b

int n, m, s, g1, g2;
int gp[100][100];

int main(void)
{
    int i, j, k, f, t, d;
    scanf("%d %d %d %d %d", &n, &m, &s, &g1, &g2);
    while (n) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                gp[i][j] = INF;
            }
            gp[i][j] = 0;
        }
        for (i = 0; i < m; i++) {
            scanf("%d %d %d", &f, &t, &d);
            gp[f-1][t-1] = d;
        }
        for (k = 0; k < n; k++) {
            for (i = 0; i < n; i++) {
                for (j = 0; j < n; j++) {
                    gp[i][j] = min(gp[i][j], gp[i][k] + gp[k][j]);
                }
            }
        }
        int ans = INF;
        for (k = 0; k < n; k++) {
            ans = min(ans, gp[s-1][k] + gp[k][g1-1] + gp[k][g2-1]);
        }
        printf("%d\n", ans);
        scanf("%d %d %d %d %d", &n, &m, &s, &g1, &g2);
    }
    return 0;
}
