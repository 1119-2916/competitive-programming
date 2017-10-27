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
#define Int(x) int x; scanf("%lld", &x);
#define int2(x, y) int x, y; scanf("%lld %lld", &x, &y);
 
//int dxy[5] = {0, 1, 0, -1, 0};
// assign

signed main()
{
    int2(n, w);

    vi a[4];

    int2(c, b);
    a[0].pb(-b);

    Rep(i, n) {
        int2(d, e);
        a[d-c].pb(-e);
    }
    rep(i, 4) sort(all(a[i]));
    int ans = 0;
    int dp[a[0].size()+2][a[1].size()+2][a[2].size()+2][a[3].size()+2];
    memset(dp, 0, sizeof(dp));

    rep(i, a[0].size()+1) {
        rep(j, a[1].size()+1) {
            rep(k, a[2].size()+1) {
                rep(l, a[3].size()+1) {
                    if (a[0].size() != i) 
                        dp[i+1][j][k][l] = dp[i][j][k][l] - a[0][i];
                    if (a[1].size() != j) 
                        dp[i][j+1][k][l] = dp[i][j][k][l] - a[1][j];
                    if (a[2].size() != k) 
                        dp[i][j][k+1][l] = dp[i][j][k][l] - a[2][k];
                    if (a[3].size() != l) 
                        dp[i][j][k][l+1] = dp[i][j][k][l] - a[3][l];
                    if ( (i * c) + (j * (c+1)) + (k * (c+2)) + 
                            (l * (c+3)) <= w) {
                        ans = max(ans, dp[i][j][k][l]);
                    }
                }
            }
        }
    }

    cout << ans << endl;
    return 0;
}

