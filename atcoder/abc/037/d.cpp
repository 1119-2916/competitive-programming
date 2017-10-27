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
 
int dxy[5] = {0, 1, 0, -1, 0};
// assign

void solve(int x, int y);

vvi dp, grid;
int h, w;

signed main()
{
    cin >> h >> w;
    grid.assign(h, vi(w));
    dp.assign(h, vi(w, -1));

    rep(i, h) {
        rep(j, w) {
            cin >> grid[i][j];
        }
    }

    int ret = 0;
    rep(i, h) {
        rep(j, w) {
            solve(i, j);
            ret += dp[i][j];
            ret % MOD;
        }
    }
    cout << (ret + (h * w))%MOD << endl;

    return 0;
}

void solve(int x, int y)
{
    if (dp[x][y] != -1) {
        return ;
    } else {
        int ans = 0;
        rep(i, 4) {
            int a = x + dxy[i], b = y + dxy[i+1];
            if (0 <= a && a < h && 0 <= b && b < w) {
                if (grid[x][y] < grid[a][b]) {
                    solve(a, b);
                    ans += dp[a][b] + 1;
                }
            }
        }
        dp[x][y] = ans % MOD;
    }
}

