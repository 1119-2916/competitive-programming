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
#define eb emplece_back
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
// assign avl ncm dijkstra geo2 kruskal graph uf lca BIT
// matrix dinic next_combination topcoder lcm

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    Int(n);
    vi ans(n, 0);
    vector<i_i> data(n);
    for (int i = 0; i < n; i++) {
        int a, b, c, d;
        scanf("%lld:%lld:%lld.%lld", &a, &b, &c, &d);
        b += a * 60;
        c += b * 60;
        d += c * 1000;
        data[i].fir = d;
        scanf("%lld:%lld:%lld.%lld", &a, &b, &c, &d);
        b += a * 60;
        c += b * 60;
        d += c * 1000;
        data[i].sec = d;
    }

    int left = 0, right = INF;
    rep(i, n) {
        if (data[i].sec <= data[i].fir) {
            left = max(left, data[i].fir);
            right = min(right, data[i].sec + 1000);
            ans[i] = data[i].sec - data[i].fir + 1000;
        }
    }

    cout << left << " " << right << endl;

    rep(i, n) {
        if (!ans[i]) {
            if (right <= data[i].fir) {
                ans[i] = data[i].sec - data[i].fir;
            } else if (data[i].fir <= left && right <= data[i].sec) {
                ans[i] = data[i].sec - data[i].fir + 1000;
            } else if (data[i].sec + 1000 <= left) {
                ans[i] = data[i].sec - data[i].fir;
            } else {
                ans[i] = -1;
            }
        }
    }

    rep(i, n) {
        cout << ans[i] << endl;
    }

    return 0;
}
