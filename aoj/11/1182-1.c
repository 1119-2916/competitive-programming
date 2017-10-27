#include <stdio.h>
#define INF 1010001000

int d[101][101][21];
int ans[101][101];
int p[21], q[51][21], r[51][21];
int n, m, s, g, cl;

void init(void);
int calc(int val, int col);
int min(int a, int b);

int main(void)
{
    int i, j, k, l, z, x;
    int fr, to, c, val;
    scanf("%d %d %d %d %d", &n, &m, &cl, &s, &g);
    while (n != 0) {
        init();
        if (n != 0) {
            for (i = 0; i < m; i++) {
                scanf("%d %d %d %d", &fr, &to, &val, &c);
                d[fr][to][c] = min(d[fr][to][c], val);
                d[to][fr][c] = min(d[to][fr][c], val);
            }
        }
        for (i = 1; i <= cl; i++) {
            scanf("%d", &p[i]);
        }
        for (i = 1; i <= cl; i++) {
            q[0][i] = 0;
            for (j = 1; j < p[i]; j++) {
                scanf("%d", &q[j][i]);
            }
            for (j = 0; j < p[i]; j++) {
                scanf("%d", &r[j][i]);
            }
        }
        for (l = 1; l <= cl; l++) {
            for (k = 1; k <= n; k++) {
                for (i = 1; i <= n; i++) {
                    for (j = 1; j <= n; j++) {
                        d[i][j][l] = min(d[i][j][l], 
                                d[i][k][l] + d[k][j][l]);
                    }
                }
            }
        }
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                for (k = 1; k <= cl; k++) {
                    d[i][j][k] = calc(d[i][j][k], k);
                }
            }
        }
        for (k = 1; k <= n; k++) {
            for (i = 1; i <= n; i++) {
                for (j = 1; j <= n; j++) {
                    for (l = 1; l <= cl; l++) {
                        for (z = 1; z <= cl; z++) {
                            ans[i][j] = min(ans[i][j],
                                    min(ans[i][k] + d[k][j][z],
                                        min(d[i][k][l] + ans[k][j],
                                            d[i][k][l] + d[k][j][z])));
                        }
                    }
                }
            }
        }

        if (ans[s][g] == INF) { 
            puts("-1");
        } else {
            printf("%d\n", ans[s][g]);
        }
        scanf("%d %d %d %d %d", &n, &m, &cl, &s, &g);
    }
    return 0;
}



int calc(int val, int col)
{
    int ans = 0, i;
    if (val == INF) {
        return INF;
    }
    if (p[col] != 1) {
        for (i = 1; i < p[col]; i++) {
            if (q[i][col] > val) {
                ans += ((val-q[i-1][col]) * r[i-1][col]);
                return ans;
            } else {
                ans += (q[i][col] - q[i-1][col]) * r[i-1][col];
            }
        }
    } else {
        i = 1;
    }
    if (q[i-1][col] < val) {
        ans += (val - q[i-1][col]) * r[i-1][col];
    }
    //printf("%d %d %d\n", val, col, ans);
    return ans;
}

int min(int a, int b)
{
    return a<b?a:b;
}

void init(void)
{
    int i, j, k;
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= n; j++) {
            ans[i][j] = INF;
            for (k = 1; k <= cl; k++) {
                d[i][j][k] = INF;
            }
        }
        ans[i][i] = 0;
        for (k = 1; k <= cl; k++) {
            d[i][i][k] = 0;
        }
    }
}


