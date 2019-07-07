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

int solve(vi &a, vi &b)
{
    int p = 0;
    rep(i, a.size()) {
        p += (a[i] - b[i]) * (a[i] - b[i]);
    }

    rep(i, p+1) {
        if (i * i == p) {
            return 1;
        }
    }

    return 0;
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int2(n, d);
    vvi data(n, vi(d));
    rep(i, n) {
        rep(j, d) {
            cin >> data[i][j];
        }
    }

    int ans = 0;
    rep(i, n) {
        for (int j = i+1; j < n; j++) {
            ans += solve(data[i], data[j]);
        }
    }

    std::cout << ans << std::endl;

    return 0;
}
