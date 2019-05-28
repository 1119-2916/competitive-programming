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
    vvi data(n, vi(n));
    rep(i, n) rep(j, n) cin >> data[i][j];

    vi dp(1 << n, 0);
    dp[0] = 1;

    rep(i, n) {
        rep(j, dp.size()) {
            if (__builtin_popcount(j) == i) {
                rep(k, n) {
                    if (data[i][k] && (j & (1 << k)) == 0) {
                        dp[j | (1 << k)] = (dp[j | (1 << k)] + dp[j]) % MOD;
                    }
                }
            }
        }
        /*
        rep(j, dp.size()) {
            cout << dp[j] << " ";
        }
        cout << endl;
        */
    }

    std::cout << dp.back() << std::endl;

    return 0;
}
