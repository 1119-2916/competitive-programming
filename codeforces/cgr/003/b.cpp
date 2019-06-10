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

    int2(n, m);
    int3(ta, tb, k);

    vector<int> from(n);
    for (int i = 0; i < n; i++) {
        cin >> from[i];
        from[i] += ta;
    }
    
    vector<int> to;
    int cnt = 0;
    for (int i = 0; i < m; i++) {
        Int(tmp);
        if (tmp >= from[0]) {
            to.pb(tmp);
        }
    }

    rep(i, from.size()) cout << from[i] << " "; cout << endl;
    rep(i, to.size()) cout << to[i] << " "; cout << endl;

    int p = 0, ans = -1;
    {
        if (k >= to.size()) {
            std::cout << -1 << std::endl;
            return 0;
        }
        ans = max(ans, to[k] + tb);
        cout << ans << endl;
        if (k >= from.size()) {
            std::cout << -1 << std::endl;
            return 0;
        }
        int tmp = from[k];
        ans = max(ans, *lower_bound(all(to), tmp) + tb);
    }
    cout << ans << endl;
    rep(i, to.size()) {
        while (p < from.size() && from[p] <= to[i]) p++;
        cout << p << " " << ans << endl;
        if (i + p < k) {
            if (k - i - p + i + 1 >= to.size()) {
                std::cout << -1 << std::endl;
                return 0;
            }
            ans = max(ans, to[k - i - p + i + 1] + tb);
            if (k - i - p - 2 + p + 1 >= from.size()) {
                std::cout << -1 << std::endl;
                return 0;
            }
            int tmp = from[k - i - p - 2 + p + 1];
            ans = max(ans, *lower_bound(all(to), tmp) + tb);
        }
    }
    cout << p << " " << ans << endl;

    std::cout << ans << std::endl;

    return 0;
}
