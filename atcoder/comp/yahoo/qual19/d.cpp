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

    Int(n);
    vector<int> data(n);
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }
    
    vector<int> funami(1, 0);
    vector<int> toshino(1, 0);
    int p = 0, bef = 0;
    rep(i, data.size()) {
        if (data[i]) {
            if (bef) {
                p++;
                funami.pb(0);
                toshino.pb(0);
            }
            funami[p] += data[i];
            toshino[p] += (data[i]+1) % 2;
            bef = 0;
        } else {
            funami.pb(0);
            toshino.pb(0);
            bef = 1;
            p++;
        }
    }

    vp yui;
    int sum = 0;
    rep(i, funami.size()) {
        if (funami[i]) {
            if (sum) {
                yui.pb({sum, 0});
                sum = 0;
            }
            yui.pb({toshino[i], funami[i]});
        } else {
            sum++;
        }
    }
    if (sum) {
        yui.pb({sum, 0});
    }

    rep(i, yui.size()) {
        std::cout << yui[i].fir << " " << yui[i].sec << std::endl;
    }

    vvi dp(yui.size()+1, vi(3, INF));
    dp[0][0] = 0; dp[0][1] = 0; dp[0][2] = 0;
    rep(i, yui.size()) {
        dp[i+1][0] = min(dp[i+1][0], dp[i][0] + yui[i].fir);
        dp[i+1][1] = min(dp[i+1][1], dp[i][0] + yui[i].sec);
        dp[i+1][1] = min(dp[i+1][1], dp[i][1] + yui[i].sec);
        dp[i+1][2] = min(dp[i+1][2], dp[i][0] + yui[i].sec);
        dp[i+1][2] = min(dp[i+1][2], dp[i][1] + yui[i].sec);
        dp[i+1][2] = min(dp[i+1][2], dp[i][2] + yui[i].fir);
    }

    std::cout << min({dp[yui.size()][0], dp[yui.size()][1], 
            dp[yui.size()][2]})  << std::endl;

    return 0;
}
