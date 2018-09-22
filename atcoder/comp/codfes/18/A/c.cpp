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

int calc(int a)
{
    int cnt = 0;
    if (!a) return 0;
    while (a) {
        a /= 2;
        cnt++;
    }
    return cnt;
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int2(n, k);
    vector<int> input(n);
    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    vector<int> data(n);
    int s = 0;
    for (int i = 0; i < n; i++) {
        data[i] = calc(input[i]);
        s += data[i];
    }
    s = min(s, k);

    //rep(i, data.size()) cout << data[i] << " "; cout << endl;
    //cout << s << endl;

    vector<vvi> dp(n+1, vvi(s+2, vi(2, 0)));
    dp[0][0][0] = 1;

    rep(i, n) {
        rep(j, s+1) {
            rep(l, min(data[i]+1, s-j+1)) {
                //cout << s + l << " ";
                if (l == data[i]) {
                    dp[i+1][j+l][1] = (dp[i+1][j+l][1] + dp[i][j][0] +
                            dp[i][j][1]) % MOD;
                } else {
                    dp[i+1][j+l][0] = (dp[i+1][j+l][0] + dp[i][j][0]) % MOD;
                    dp[i+1][j+l][1] = (dp[i+1][j+l][1] + dp[i][j][1]) % MOD;
                }
            }
            //cout << endl;
        }
    }

    /*
    rep(i, dp.size()) {
        rep(j, dp[i].size()) {
            cout << dp[i][j][0] << " ";
        }
        cout << endl;
    }
    cout << endl;
    rep(i, dp.size()) {
        rep(j, dp[i].size()) {
            cout << dp[i][j][1] << " ";
        }
        cout << endl;
    }
    */

    int ans = dp[n][s][0] % MOD;
    rep(i, dp[n].size()) {
        ans = (ans + dp[n][i][1]) % MOD;
    }
    cout << ans << endl;


    //cout << dp[n][k] << endl;

    return 0;
}
