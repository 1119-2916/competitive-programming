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
#define Decimal fixed << setprecision(10)

//int dxy[5] = {0, 1, 0, -1, 0};
// // assign avl ncm dijkstra geo2 kruskal graph uf lca BIT
// matrix dinic next_combination topcoder lcm vi st gin

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int2(n, m);
    vi table(n+2, 0);
    vector<i_i> paint(m);
    for (int i = 0; i < m; i++) {
        cin >> paint[i].fir >> paint[i].sec;
        table[paint[i].fir]++; table[paint[i].sec+1]--;
    }

    Rep(i, table.size()) {
        table[i] += table[i-1];
    }
    int toshino = 0;
    vi ans(0);
    Rep(i, n+1) {
        if (table[i] == 1) {
            ans.pb(i);
        } else if (!table[i]) {
            toshino++;
        }
    }

    rep(i, m) {
        auto funami = lower_bound(all(ans), paint[i].fir);
        auto kyoko = upper_bound(all(ans), paint[i].sec);
        cout << kyoko - funami + toshino << endl;
    }

    return 0;
}
