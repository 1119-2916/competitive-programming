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

//int dxy[5] = {0, 1, 0, -1, 0};
// cmd

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    Int(n);
    vector<pair<int, i_i> > data(n);
    for (int i = 0; i < n; i++) {
        cin >> data[i].sfir >> data[i].ssec;
        data[i].fir = data[i].sfir + data[i].ssec;
    }
    sort(all(data));

    vvi dp(n+1, vi(n+1, INF));
    dp[0][0] = 0;
    rep(i, n) {
        rep(j, i+1) {
            dp[i+1][j] = min(dp[i+1][j], dp[i][j]);
            if (dp[i][j] <= data[i].sfir) {
                dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j] + data[i].ssec);
            }
        }
    }

    for (int i = n; i >= 0; i--) {
        if (dp[n][i] != INF) {
            cout << i << endl;
            return 0;
        }
    }
    cout << 0 << endl;

    return 0;
}
