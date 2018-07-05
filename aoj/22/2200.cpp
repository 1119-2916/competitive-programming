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
#define eb emplace_back
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
#define Decimal fixed << setprecision(10)

//int dxy[5] = {0, 1, 0, -1, 0};
// cmd

int n, m;
int walk[200][200], swim[200][200];
int dp[1000][200];

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    cin >> n >> m;
    while (n || m) {
        rep(i, 200) rep(j, 200) walk[i][j] = swim[i][j] = INF;
        rep(i, m) {
            int3(x, y, t);
            string st;
            cin >> st;
            if (st[0] == 'L') {
                walk[y-1][x-1] = walk[x-1][y-1] = min(walk[x-1][y-1], t);
            } else {
                swim[y-1][x-1] = swim[x-1][y-1] = min(swim[x-1][y-1], t);
            }
        }
        Int(r);
        vector<int> data(r);
        for (int i = 0; i < r; i++) {
            cin >> data[i];
            data[i]--;
        }

        rep(i, n) walk[i][i] = swim[i][i] = 0;
        rep(k, n) rep(i, n) rep(j, n) {
            walk[i][j] = min(walk[i][j], walk[i][k] + walk[k][j]);
            swim[i][j] = min(swim[i][j], swim[i][k] + swim[k][j]);
        }
        rep(i, 1000) rep(j, 200) dp[i][j] = INF;
        dp[0][data[0]] = 0;

        rep(i, r-1) rep(j, n) rep(k, n) {
            if (j != k) 
            dp[i+1][k] = min(dp[i+1][k], dp[i][j] + walk[data[i]][j]
                    + swim[j][k] + walk[k][data[i+1]]);
            else 
            dp[i+1][k] = min(dp[i+1][k], 
                    dp[i][j] + walk[data[i]][data[i+1]]);
        }

        int ans = INF;
        rep(i, n) ans = min(ans, dp[r-1][i]);
        cout << ans << endl;
        cin >> n >> m;
    }
    return 0;
}




