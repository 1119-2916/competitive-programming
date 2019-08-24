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

    int3(k, x, y);

    int px = 0, py = 0;
    int tmp = (x + y) % k;
    if (tmp % 2) {
        std::cout << -1 << std::endl;
        return 0;
    }
    if (x + y <= k) {
        if (x + y == k) {
            cout << 1 << endl;
            cout << x << " " << y << endl;
            return 0;
        }
        int a = k - (k - x) - y;
        cout << 2 << endl;
        cout << k - a / 2 << " " << a / 2 << endl;
        cout << x << " " << y << endl;
        return 0;
    }

    vp ans;
    for (int i = k; i <= x; i += k) {
        px = i;
        ans.pb({px, py});
    }

    if (px != x) {
        ans.pb({x, k - (x - px)});
        py = k - (x - px);
        px = x;
    }

    for (int i = py + k; i <= y; i += k) {
        py = i;
        ans.pb({px, py});
    }

    if (ans.size() > 1) {
        int ptr = ans.size()-2;
        ans[ptr].first += tmp / 2;
        ans[ptr].second -= tmp / 2;
        ans[ptr+1].first = x;
        ans[ptr+1].second = y;
    }

    cout << ans.size() << endl;
    rep(i, ans.size()) {
        cout << ans[i].first << " " << ans[i].second << endl;
    }

    return 0;
}
