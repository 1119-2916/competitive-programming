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

pair<int, pii> mmnmm(pair<int, pii> a, pair<int, pii> b, int ned, int man)
{
    if (a.fir > b.fir + man) {
        return a;
    } else if (a.fir < b.fir + man) {
        b.fir += man;
        if (b.sfir > ned) {
            b.sfir = ned; b.ssec = man;
        }
        return b;
    } else {
        if (a.sfir < min(b.sfir, ned)) {
            return a;
        } else {
            b.fir += man;
            if (b.sfir > ned) {
                b.sfir = ned; b.ssec = man;
            }
            return b;
        }
    }
}


signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int2(n, p);

    if (n == 1) {
        int2(a, b); cout << b << endl; return 0;
    }

    vector<pair<int, pii>> dp(p+201);
    dp[0].fir = 0; dp[0].sfir = INF; dp[0].ssec = 0;
    rep(i, n) {
        int2(ned, man);
        for (int i = p + 100; i > 0; i--) {
            if (in(i + ned, 0, p+200) && dp[i].fir && 
                    i + ned - min(dp[i].sfir, ned) < p+1) {
                dp[i+ned] = mmnmm(dp[i+ned], dp[i], ned, man);
            }
        }
        dp[ned] = mmnmm(dp[ned], dp[0], ned, man);
    }

    /*
    rep(i, p+50) {
        cout << i << " : " << dp[i].fir << " "
            << dp[i].sfir << " " << dp[i].ssec
            << endl;
    }
    */

    int ans = 0;
    rep(i, dp.size()) {
        if (in(i - dp[i].sfir, 0, p+1))
            ans = max(ans, dp[i].fir);
    }
    cout << ans << endl;

    return 0;
}
