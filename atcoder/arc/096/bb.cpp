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
// BIT avl cmd cusum dijkstra dinic geo2 gin graph kruskal lca lcm matrix ncm next_combination segtree st tmp topcoder uf vi 

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int2(n, c);
    vp data(n+1);
    data[0] = {0, 0};
    Rep(i, n+1) {
        cin >> data[i].fir >> data[i].sec;
    }

    vi ri(n+1, 0), le(n+1, 0);
    int sum = 0;
    Rep(i, n+1) {
        sum += data[i].sec;
        ri[i] = max(ri[i-1], sum - data[i].fir);
    }
    sum = 0;
    Rep(i, n+1) {
        sum += data[n-i+1].sec;
        le[i] = max(le[i-1], sum - data[n-i+1].fir);
    }

    rep(i, n+1) cout << ri[i] << " "; cout << endl;
    rep(i, n+1) cout << le[i] << " "; cout << endl;

    int ans = 0;
    rep(i, n+1) {
        ans = max(ans, ri[i]);
        ans = max(ans, ri[i] + le[n-i+1] - data[i].fir);
    }
    rep(i, n+1) {
        ans = max(ans, le[i]);
        ans = max(ans, le[i] + ri[n-i+1] - data[i].fir);
    }

    cout << ans << endl;

    return 0;
}


