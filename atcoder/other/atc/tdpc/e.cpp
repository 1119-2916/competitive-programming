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

    static int dp[2][101][10001];
    Int(d);
    string n;
    cin >> n;
    memset(dp, 0, sizeof(dp));

    dp[1][n[0]-'0'][0] = 1;
    for (int i = 0; i < n[0]-'0'; i++) 
        dp[0][i][0] = 1;

    for (int i = 1; i < n.size(); i++) {
        for (int j = 0; j < d; j++) {
            dp[1][(j+(n[i]-'0'))%d][i] += dp[1][j][i-1];
            dp[1][(j+(n[i]-'0'))%d][i] %= MOD;
            for (int k = 0; k < n[i]-'0'; k++) {
                dp[0][(j+k)%d][i] += dp[1][j][i-1];
                dp[0][(j+k)%d][i] %= MOD;
            }
            for (int k = 0; k < 10; k++) {
                dp[0][(j+k)%d][i] += dp[0][j][i-1];
                dp[0][(j+k)%d][i] %= MOD;
            }
        }
    }

    std::cout << (dp[1][0][n.size()-1] + dp[0][0][n.size()-1] - 1) % MOD 
        << std::endl;


    return 0;
}
