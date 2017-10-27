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
#define Edge pair< i_i, int>
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
// assign
 
signed main()
{
    int2(r, g); Int(b);
    vvi dp(2001, vi(r+g+b+1, INF));
    int n = r + g + b;
    rep(i, 2001) dp[i][n] = 0;

    rep(i, 2000) {
        for (int j = n; j > max((int)0, n-i-1); j--) {
            dp[i+1][j] = min(dp[i+1][j], dp[i][j]); // 置かない
            if (j <= b) { // 青
                dp[i+1][j-1] = min(dp[i+1][j-1], 
                        dp[i][j] + abs(1100 - i));
            } else if (j <= b + g) {
                dp[i+1][j-1] = min(dp[i+1][j-1], 
                        dp[i][j] + abs(1000 - i));
            } else {
                dp[i+1][j-1] = min(dp[i+1][j-1], 
                        dp[i][j] + abs(900 - i));
            }
        }
    }
    int ans = INF;
    rep(i, 2001) {
        ans = min(ans, dp[i][0]);
    }
    cout << ans << endl;


    return 0;
}

