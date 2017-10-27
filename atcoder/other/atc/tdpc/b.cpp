#include <bits/stdc++.h>

using namespace std;

#define INF 1001000100010001000
#define MOD 1000000007
#define int long long
#define EPS 1e-10
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

int a, b;
int dp[2][1002][1002], l[1001], r[1001];

int solve(int n, int m, int pos)
{
    //std::cout << n << " " << m << " " << pos << std::endl;
    if (dp[pos][n][m]) {
        return dp[pos][n][m];
    }
    if (!n && !m) {
        return 0;
    }
    if (pos) {
        int tmp = -INF;
        if (n > 0) {
            tmp = max(tmp, solve(n-1, m, pos^1) + l[n-1]);
        }
        if (m > 0) {
            tmp = max(tmp, solve(n, m-1, pos^1) + r[m-1]);
        }
        return dp[pos][n][m] = tmp;
    } else {
        int tmp = INF;
        if (n > 0) {
            tmp = min(tmp, solve(n-1, m, pos^1));
        }
        if (m > 0) {
            tmp = min(tmp, solve(n, m-1, pos^1));
        }
        return dp[pos][n][m] = tmp;
    }
}



signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    cin >> a >> b;
    for (int i = 0; i < a; i++) cin >> l[a-i-1];
    for (int i = 0; i < b; i++) cin >> r[b-i-1];

    std::cout << solve(a, b, 1LL) << std::endl;

    return 0;
}
