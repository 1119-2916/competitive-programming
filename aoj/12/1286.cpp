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
    int n, m, s;
    while (cin >> n >> m >> s, n) {
        double dp[n+1][n*m+1];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        rep(i, n) {
            rep(j, n*m+1) {
                if (dp[i][j] > EPS) {
                    Rep(k, m+1) {
                        dp[i+1][j+k] += dp[i][j] / m;
                    }
                }
            }
        }
        double ans = 0;
        rep(i, n*m+1) {
            ans += dp[n][i] * ((i - s > 0) ? i-s : 1);
        }
        printf("%.10lf\n", ans);
    }

    return 0;
}

