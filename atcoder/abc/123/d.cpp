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

    int3(x, y, z);
    Int(k);
    vector<int> a(x);
    for (int i = 0; i < x; i++) {
        cin >> a[i];
    }
    vector<int> b(y);
    for (int i = 0; i < y; i++) {
        cin >> b[i];
    }
    vector<int> c(z);
    for (int i = 0; i < z; i++) {
        cin >> c[i];
    }
    vector<int> ab(x * y);
    rep(i, x) {
        rep(j, y) {
            ab[i * y + j] = a[i] + b[j];
        }
    }

    sort(all(ab));
    reverse(all(ab));

    vi ans(min(k, (int)ab.size()) * z);
    rep(i, min(k, (int)ab.size())) {
        rep(j, z) {
            ans[i * z + j] = ab[i] + c[j];
        }
    }

    sort(all(ans));
    reverse(all(ans));

    rep(i, k) {
        std::cout << ans[i] << std::endl;
    }

    return 0;
}
