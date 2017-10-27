#include <bits/stdc++.h>

using namespace std;

#define INF 1001000100010001000
#define MOD 1000000007
#define EPS 1e-10
#define int long long
#define rep(i, N) for (int i = 0; i < N; i++)
#define Rep(i, N) for (int i = 1; i < N; i++)
#define For(i, a, b) for (int i = (a); i < (b); i++)
#define pb push_back
#define eb emplece_back
#define mp make_pair
#define i_i pair<int, int>
#define vi vector<int>
#define vvi vector<vi >
#define vb vector<bool>
#define vvb vector<vb >
#define vp vector< i_i >
#define all(a) (a).begin(), (a).end()
#define Int(x) int x; cin >> x;
#define int2(x, y) Int(x); Int(y);
#define int3(x, y, z) Int(x); int2(y, z);
#define fir first
#define sec second
#define ffir first.first
#define fsec first.second
#define sfir second.first
#define ssec second.second

//int dxy[5] = {0, 1, 0, -1, 0};
// assign avl ncm dijkstra geo2 kruskal graph uf lca BIT
// matrix dinic next_combination topcoder lcm

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int2(n, d);
    static double dp[101][65][65][65];
    memset(dp, 0.0, sizeof(dp));
    dp[0][0][0][0] = 1;
    int ni = 0, san = 0, go = 0;
    while (d % 2 == 0) {
        ni++;
        d /= 2;
    }
    while (d % 3 == 0) {
        san++;
        d /= 3;
    }
    while (d % 5 == 0) {
        go++;
        d /= 5;
    }
    if (d != 1) {
        std::cout << 0.00000000000 << std::endl;
        return 0;
    }

    rep(lp, n) {
        rep(i, ni+1) {
            rep(j, san+1) {
                rep(k, go+1) {
                    if (dp[lp][i][j][k] > EPS) {
                        double tmp = dp[lp][i][j][k] / 6.0;;
                        dp[lp+1][i][j][k] += tmp;
                        dp[lp+1][min(i+1, ni)][j][k] += tmp;
                        dp[lp+1][i][min(j+1, san)][k] += tmp;
                        dp[lp+1][min(i+2, ni)][j][k] += tmp;
                        dp[lp+1][i][j][min(k+1, go)] += tmp;
                        dp[lp+1][min(i+1, ni)][min(j+1, san)][k] += tmp;
                    }
                }
            }
        }
    }

    printf("%.10lf\n", dp[n][ni][san][go]);

    return 0;
}
