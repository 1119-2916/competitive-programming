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

    int3(n, k, m);
    int sum = 0;
    vi data(k);
    rep(i, k) {
        cin >> data[i];
        sum += data[i];
    }

    sort(all(data));
    Rep(i, k) {
        data[i] += data[i-1];
    }

    vvi dp(n, vi(3000, INF));
    dp[0][0] = 0;
    rep(i, k-1) {
        dp[0][i+1] = data[i];
    }
    dp[0][k+1] = data[k-1];
        
    Rep(i, n) {
        rep(j, k-1) {
            for (int l = dp[i].size()-50; l > 0; l--) {
                if (dp[i-1][l] != INF) {
                    dp[i][l+1+j] = min(dp[i][l+1+j], dp[i-1][l] + data[j]);
                }
            }
            dp[i][1+j] = min(dp[i][1+j], dp[i-1][0] + data[j]);
        }
        for (int l = dp[i].size()-3; l > 0; l--) {
            if (dp[i-1][l] != INF) {
                dp[i][l+1+k] = min(dp[i][l+1+k], dp[i-1][l] + data[k-1]);
            }
        }
        dp[i][k+1] = min(dp[i][k+1], dp[i-1][0] + data[k-1]);
        rep(l, dp[i].size()) {
            dp[i][l] = min(dp[i-1][l], dp[i][l]);
        }
    }

    /*
    rep(i, n) {
        rep(j, m+1) {
            std::cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    */

    for (int i = dp[n-1].size()-1; i >= 0; i--) {
        if (dp[n-1][i] <= m) {
            std::cout << i << std::endl;
            return 0;
        } 
    }
    std::cout << 0 << std::endl;
    return 0;
}





