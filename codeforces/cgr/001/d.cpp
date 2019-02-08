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
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vi >
#define vb vector<bool>
#define vvb vector<vb >
#define vp vector< pii >
#define all(a) (a).begin(), (a).end()
#define Int(x) int x; cin >> x;
#define int2(x, y) Int(x); Int(y);
#define int3(x, y, z) Int(x); int2(y, z);
#define in(x, a, b) ((a) <= (x) && (x) < (b))
#define fir first
#define sec second
#define ffir first.first
#define fsec first.second
#define sfir second.first
#define ssec second.second
#define Decimal fixed << setprecision(10)

//int dxy[5] = {0, 1, 0, -1, 0};
// cmd

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int2(n, m);
    vector<int> data(m+1, 0);
    for (int i = 0; i < n; i++) {
        Int(tmp);
        data[tmp-1]++;
    }

    /*
    rep(i, m) {
        std::cout << data[i] << " ";
    }cout << endl;
    */

    vector<vvi> dp(m+10, vvi(3, vi(3, -1)));

    dp[0][0][0] = dp[1][0][0] = dp[2][0][0] = dp[3][0][0] = 0;

    for (int i = 3; i <= m + 4; i++) {
        int p = i - 3;
        for (int r = 0; r < 3; r++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {

                    if (data[p] >= r + j + k &&
                            dp[i][j][k] != -1) {
                dp[i+1][r][j] = max(dp[i+1][r][j], 
                        dp[i][j][k] + (data[p] - r - j - k)/3 + k);
                    }
                }
            }
        }
    }

    /*
    rep(i, m+4) {
        cout << i << " : " << endl;
        rep(j, 3) {
            rep(k, 3) {
                cout << dp[i][j][k] << " ";
            }cout << endl;
        }
    }
    */

    int ans = 0;
    rep(i, 3) rep(j, 3) ans = max(ans, dp[m+3][i][j]);

    std::cout << ans << std::endl;

    return 0;
}
