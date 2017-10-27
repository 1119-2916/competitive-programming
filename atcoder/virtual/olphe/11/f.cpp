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

    int3(r, c, k); Int(n);
    vector<i_i> data(n);
    vi yui(r+1, 0), kyoko(c+1, 0);
    for (int i = 0; i < n; i++) {
        cin >> data[i].fir >> data[i].sec;
        yui[data[i].fir]++;
        kyoko[data[i].sec]++;
    }
    vi ol(100003, 0), phe(100003, 0);
    Rep(i, yui.size()) ol[yui[i]]++;
    Rep(i, kyoko.size()) phe[kyoko[i]]++;

    int ans = 0;
    rep(i, k+1) ans += ol[i] * phe[k-i];
    rep(i, n) {
        if (yui[data[i].fir] + kyoko[data[i].sec] == k) ans--;
        if (yui[data[i].fir] + kyoko[data[i].sec] == k+1) ans++;
    }
    std::cout << ans << std::endl;

    return 0;
}
