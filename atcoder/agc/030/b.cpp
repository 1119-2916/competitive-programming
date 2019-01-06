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

    int2(l, n);
    vector<int> data(n+2, 0);
    for (int i = 0; i < n; i++) {
        cin >> data[i+1];
    }
    data[n+1] = l;

    if (n > 2010) return 0;

    vector<vvi> dp(2, vvi(n+2, vi(n+2, 0)));
    //dp[1][0][n] = l - data[n];
    //dp[0][1][n+1] = data[1];

    rep(i, n+1) {
        for (int j = n+1; j > 0; j--) {
            dp[1][i][j-1] = max(dp[1][i][j-1], dp[0][i][j] 
                    + (data[i] + l - data[j-1]));
            dp[1][i][j-1] = max(dp[1][i][j-1], dp[1][i][j] 
                    + (data[j-1] - data[j]));

            dp[0][i+1][j] = max(dp[0][i+1][j], dp[1][i][j] 
                    + (data[i+1] + l - data[j]));
            dp[0][i+1][j] = max(dp[0][i+1][j], dp[0][i][j] 
                    + (data[i+1] - data[i]));
        }
    }
/*
    rep(i, n+2) {
        rep(j, n+2) {
            std::cout << dp[0][i][j] << " " << dp[1][i][j] << " ";
        }
        cout << endl;
    }
*/
    int ans = 0;
    rep(i, n+1) {
        ans = max(ans, dp[0][i][i+1]);
        ans = max(ans, dp[1][i][i+1]);
    }

    std::cout << ans << std::endl;


    return 0;
}
