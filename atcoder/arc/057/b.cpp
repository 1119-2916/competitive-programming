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

int calc(int a, int b, int c)
{
    if (a == 0 || b == 0) {
        return 1;
    }
    int ret = a * c / b + 1;
    //if (1LL <= ret && ret <= c) {
    if (ret <= c) {
        return ret;
    } else {
        return INF;
    }
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int2(n, k);
    vector<int> data(n);
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }
    vector<int> sum(n+1);
    sum[0] = 0;
    for (int i = 0; i < n; i++) {
        sum[i+1] = sum[i] + data[i];
    }
    if (sum[n] == k) {
        std::cout << 1 << std::endl;
        return 0;
    }

    vvi dp(n+1, vi(n+1, INF));
    dp[0][0] = 0;
    rep(i, n) {
        for (int j = 0; j <= i; j++) {
            if (dp[i][j] != INF) {
                dp[i+1][j] = min(dp[i+1][j], dp[i][j]);
                dp[i+1][j+1] = min(dp[i+1][j+1], 
                        calc(dp[i][j], sum[i], data[i]) + dp[i][j]);
            }
            //std::cout << data[i] << " " 
            //    << calc(dp[i][j], sum[i], data[i]) << std::endl;
        }
    }
    /*
    rep(i, n+1) {
        rep(j, n+1) {
            std::cout << dp[i][j] << " " ;
        }
        cout << endl;
    }
    */

    for (int i = dp[n].size()-1; i >= 0; i--) {
    //Rep(i, n+1) {
        if (dp[n][i] <= k) {
            std::cout << i << std::endl;
            return 0;
        }
    }
    std::cout << 0 << std::endl;


    return 0;
}
