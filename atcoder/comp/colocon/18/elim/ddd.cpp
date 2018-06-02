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

int dp[5050][5050];

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    memset(dp, 0, sizeof(dp));

    int2(n, x);
    vector<int> data(n+1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> data[i];
    }

    vi yui(n+1, -1);
    yui[0] = 1;
    Rep(i, n+1) {
        int tmp = 0;
        for (int j = i+1; j <= n; j++) {
            if (data[j] - data[i] >= x) {
                yui[i] = j;
                break;
            }
        }
    }

    //rep(i, yui.size()) cout << yui[i] << " "; cout << endl;

    for (int i = 0; i < n; i++) {
        int ret = 0;
        for (int j = 0; j < n; j++) {
            if (yui[j] != -1) {
                dp[i+1][yui[j]] = max(dp[i+1][yui[j]], dp[i][j] + x);
                ret = max(ret, dp[i+1][yui[j]]);
                dp[i+1][yui[j]-1] = max(dp[i+1][yui[j]-1], 
                        dp[i][j] + data[yui[j]-1] - data[j]);
                ret = max(ret, dp[i+1][yui[j]-1]);
            } else {
                dp[i+1][n] = max(dp[i+1][n], 
                        dp[i][j] + data[n] - data[j]);
                ret = max(ret, dp[i+1][n]);
            }
        }
        //cout << dp[i+1][n] << endl;
        cout << ret << endl;
    }

    rep(i, n+1) {
        rep(j, n+1) {
            //cout << dp[i][j] << " ";
        } //cout << endl;
    }

    return 0;
}
