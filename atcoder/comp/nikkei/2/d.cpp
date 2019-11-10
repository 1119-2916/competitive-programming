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
// 01Trie BIT CHT DFT FFT avl cmd cusum dijkstra dinic geo2 gin graph kruskal lca lcm matrix ncm next_combination ppuf segtree st tmp topcoder uf vi 

struct RangeAddQuery {
	int n;
	vector<int> d;
	int time;
	RangeAddQuery(int m) {
		for (n = 1; n < m; n *= 2);
		d.assign(n * 2, INF);
	}
	//[l, r)
	void add(int l, int r, int x) {
		for (; l && l + (l&-l) <= r; l += l&-l)
			d[(n + l) / (l&-l)] = min(x, d[(n + l) / (l&-l)]);
		for (; l < r; r -= r&-r)
			d[(n + r) / (r&-r) - 1] = min(x, d[(n + r) / (r&-r) - 1]);
	}
	int get(int i) {
		int ret = d[n + i];
		for (int j = (n + i) / 2; j > 0; j >>= 1)
			ret = min(ret, d[j]);
		return ret;
	}
};

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int2(n, m);
    vector<pair<pii, int>> data(m);

    rep(i, data.size()) {
        cin >> data[i].ffir >> data[i].fsec >> data[i].sec;
    }

    sort(all(data));

    RangeAddQuery dp(n+1);
    dp.add(0, 1, 0);
    rep(i, data.size()) {
        dp.add(data[i].ffir-1, data[i].fsec, 
                dp.get(data[i].ffir-1) + data[i].sec);
    }

    /*
    rep(i, n) {
        cout << dp.get(i) << " ";
    }
    cout << endl;
    */
    cout << (dp.get(n-1) == INF ? -1 : dp.get(n-1)) << endl;


    return 0;
}
