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

    string st;
    cin >> st;
    
    vector<vvi> dp(110, vvi(110, vi(110, INF)));

    dp[0][0][0] = 0;

    rep(i, st.size()) {
        rep(j, i+1) {
            rep(k, dp[i][j].size()) {
                if (dp[i][j][k] != INF) { // 到達可能
                    int nxt = k;
                    if (st[i] == '(') {
                        nxt++;
                        if (nxt >= 0) { // 遷移可能
                            dp[i+1][j][nxt] = min(dp[i][j][k], dp[i+1][j][nxt]);
                        }
                        nxt -= 2;
                        if (nxt >= 0) {
                            dp[i+1][i][nxt] = min(dp[i][j][k] + (i - j) + 1, dp[i+1][i][nxt]);
                        }
                    } else {
                        nxt--;
                        if (nxt >= 0) { // 遷移可能
                            dp[i+1][j][nxt] = min(dp[i][j][k], dp[i+1][j][nxt]);
                        }
                        nxt += 2;
                        if (nxt >= 0) {
                            dp[i+1][i][nxt] = min(dp[i][j][k] + (i - j) + 1, dp[i+1][i][nxt]);
                        }
                    }
                }
            }
        }
    }

    /*
    rep(i, st.size()+1) {
        rep(j, i+1) {
            rep(k, i+1) {
                cout << dp[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    */

    int ans = INF;
    rep(i, 110) {
        ans = min(ans, dp[st.size()][i][0]);
    }
    cout << ans << endl;


    return 0;
}
