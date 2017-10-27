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
#define Int(x) int x; scanf("%lld", &x);
#define int2(x, y) int x, y; scanf("%lld %lld", &x, &y);
#define fir first
#define sec second
#define ffir first.first
#define fsec first.second
#define sfir second.first
#define ssec second.second

//int dxy[5] = {0, 1, 0, -1, 0};
// assign avl ncm dijkstra geo2 kruskal graph uf lca BIT
// matrix dinic

int dp[51][51][10001];

signed main()
{
    Int(w);
    int2(n, m);
    vi g(n), v(n);
    rep(i, n) {
        cin >> g[i] >> v[i];
    }

    rep(i, n) {
        for (int j = 0; j < min(i+1, m); j++) {
            for (int k = w; k > 0; k--) {
                dp[i+1][j][k] = max(dp[i+1][j][k], dp[i][j][k]);
                if (dp[i][j][k] != 0 && k + g[i] <= w) {
                    dp[i+1][j+1][k + g[i]] = 
                        max(dp[i+1][j+1][k + g[i]], dp[i][j][k] + v[i]);
                }
            }
            dp[i+1][1][g[i]] = max(dp[i+1][1][g[i]], v[i]);
        }
    }
    
    int ret = 0;
    
    rep(i, n+1) {
//        std::cout << "cnt : " << i << std::endl;
        rep(j, m+1) {
            rep(k, w+1) {
 //               std::cout << dp[i][j][k] << " ";
                ret = max(ret, dp[i][j][k]);
            } // cout << endl;
        }
    }

    /*
    rep(i, w+1) {
        ret = max(ret, dp[n][m][i]);
    }
    */

    std::cout << ret << std::endl;

    return 0;
}
