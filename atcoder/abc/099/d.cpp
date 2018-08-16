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

int dp[1000][30][30];

int calc(vi &src, vvi &rate, int targ)
{
    int ret = 0;
    rep(i, src.size()) {
        ret += rate[i][targ] * src[i];
    }
    return ret;
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int2(d, c);
    vvi data(c, vi(c));
    rep(i, c) rep(j, c) cin >> data[i][j];

    vvi table(d + d, vi(c, 0));
    rep(i, d) rep(j, d) {
        Int(tmp); tmp--;
        table[i + j][tmp]++;
    }

    memset(dp, 0x7f7f7f7f, sizeof(dp));
    rep(i, c) {
        rep(j, c) {
            if (i == j) continue;
            dp[1][i][j] = calc(table[0], data, i) + calc(table[1], data, j);
        }
    }

    for (int i = 2; i < d+d-1; i++) {
        rep(j, c) rep(k, c) {
            if (j == k) continue;
            rep(l, c) {
                if (l == j || l == k) continue;
                dp[i][k][l] = min(dp[i][k][l], dp[i-1][j][k] + 
                        calc(table[i], data, l));
            }
        }
    }

    int ans = INF;
    rep(i, c) rep(j, c) ans = min(ans, dp[d+d-2][i][j]);

    cout << ans << endl;

    return 0;
}
