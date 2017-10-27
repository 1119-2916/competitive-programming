#include <stdio.h>
#define MAX_SHOP 50
#define MAX_DP 49951

typedef struct pair{
    int mai;
    int pri;
}pair;

int n, shop[MAX_SHOP];
pair dp[MAX_DP][MAX_SHOP+1];

void solve(int a);
void max(int a, int b, int ot, int i);
pair max_st(pair a, pair b);

int main(void)
{
    int i, j, max_i, max_5, max_p;
    scanf("%d",&n);

    while (n) {
        for (i = 0; i < n; i++) {
            scanf("%d",&shop[i]);
        }

        for (i = 0; i < MAX_DP; i++) {
            for (j = 0; j < MAX_SHOP; j++) {
                dp[i][j].mai = 0;
                dp[i][j].pri = 0;
            }
        }

        for (i = 0; i < n; i++) {
            solve(i);
        }

        max_i = 0;
        max_5 = dp[0][n].mai;
        max_p = dp[0][n].pri;
        for (i = 1; i < MAX_DP; i++) {
            if (max_5 < dp[i][n].mai) {
                max_i = i;
            } else if (max_5 == dp[i][n].mai && max_p > dp[i][n].pri) {
                max_i = i;
            }
        }

        printf("%d %d\n",dp[max_i][n].mai, dp[max_i][n].pri);

        scanf("%d",&n);
    }
    return 0;
}

void solve(int a)
{
    int i, j, otsuri;
    otsuri = 1000 - ((shop[a]) % 1000);
    if (otsuri == 1000) {
        otsuri = 0;
    }

    for (i = 0; i < MAX_DP; i++) {
        if (dp[i][a].pri) {
            dp[i][a+1] = max_st(dp[i][a], dp[i][a+1]);
            max(i+otsuri, i, 0, a);
            if (i >= 500 - otsuri) {
                max(i-500+otsuri, i, 1, a);
            }
        }
    }
}

void max(int a, int b, int m, int i)
{
    if (dp[a][i].mai < dp[b][i].mai+m) {
        dp[a][i+1].mai = dp[b][i].mai + m;
        dp[a][i+1].pri = dp[b][i].pri + shop[i];
    } else if (dp[a][i].mai == dp[b][i].mai + m) {
        if (dp[a][i].pri > dp[b][i].pri + shop[i] || dp[a][i].pri == 0) {
            dp[a][i+1].mai = dp[b][i].mai + m;
            dp[a][i+1].pri = dp[b][i].pri + shop[i];
        }
    }
}

pair max_st(pair a, pair b) 
{
    if (!a.mai && !a.pri) {
        return b;
    } else if (!b.mai && !b.pri) {
        return a;
    }
    if (a.mai < b.mai) {
        return b;
    } else if (a.mai > b.mai) {
        return a;
    } else if (a.pri < b.pri) {
        return a;
    } else {
        return b;
    }
}
