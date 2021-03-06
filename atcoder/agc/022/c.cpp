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

int n;
int a[50], b[50];

bool solve(int mask, int targ)
{
    vvi dp(n+1, vi(51, 0));
    rep(i, n) {
        dp[i][a[i]] = 1;
    }

    for (int i = 50; i > 0; i--) {
        if ((1ll << i) & mask || i <= targ) {
            rep(j, n) {
                rep(k, 51) {
                    if (dp[j][k]) dp[j][k % i] = 1;
                }
            }
        }
    }

    rep(i, n) {
        if (!dp[i][b[i]]) return false;
    }
    return true;
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    cin >> n;
    rep(i, n) {
        cin >> a[i];
    }
    rep(i, n) {
        cin >> b[i];
    }

    if (!solve(0, 50)) {
        std::cout << -1 << std::endl;
        return 0;
    }

    int mmn = 0;
    for (int i = 50; i > 0; i--) {
        if (!solve(mmn, i-1)) {
            mmn |= 1ll << i;
        }
    }

    int ans = 0;
    rep(i, 50) {
        ans += mmn & (1ll << i);
    }

    std::cout << ans << std::endl;

    return 0;
}
