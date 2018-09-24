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
// BIT DiscreteFourierTransform FFT avl cmd cusum dijkstra dinic geo2 gin graph kruskal lca lcm matrix ncm next_combination ppuf segtree st tmp topcoder uf vi 

struct RangeAddQuery {
	int n;
	vector<int> d;
	int time;
	RangeAddQuery(int m) {
		for (n = 1; n < m; n *= 2);
		d.assign(n * 2, 0);
	}
	//[l, r)
	void add(int l, int r, int x) {
		for (; l && l + (l&-l) <= r; l += l&-l)
			d[(n + l) / (l&-l)] = (d[(n + l) / (l&-l)] + x) % MOD;
		for (; l < r; r -= r&-r)
			d[(n + r) / (r&-r) - 1] = (d[(n + r) / (r&-r) - 1] + x) % MOD;
	}
	int get(int i) {
		int ret = d[n + i];
		for (int j = (n + i) / 2; j > 0; j >>= 1)
			ret = (ret + d[j]) % MOD;
		return ret;
	}
};

int repow(int x, int n, int mod)
{
    if (n == 0) return 1;
    int res = repow(x * x % mod, n / 2, mod);
    if (n & 1) res = res * x % mod;
    return res;
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int2(d, f);
    int2(t, n);
    t = f - t;
    n++;
    vector<int> data(n, 0);
    for (int i = 1; i < n; i++) {
        cin >> data[i];
    }

    //cout << f << " " << t << " " << n << endl;
    data.pb(d);
    /*
    rep(i, data.size()) {
        cout << data[i] << " ";
    } cout << endl;
    rep(i, n) {
        cout << data[i] << " ";
    } cout << endl;
    */
    
    //vector<int> dp(n, 0);
    RangeAddQuery dp(n);
    dp.add(0, 1, 1);

    int ans = 0;
    rep(i, n) {
        //cout << "call : " << i << " " << data[i] << endl;
        int st = upper_bound(all(data), data[i] + t) - data.begin();
        int en = upper_bound(all(data), data[i] + f) - data.begin();
        int p = repow(2, st - i - 1, MOD);
        //cout << st << " " << en << " " << p << endl;
        if (data[i] + f >= data.back()) {
            ans = (ans + dp.get(i) * repow(2, n-i-1, MOD)) % MOD;
        } else {
            dp.add(st, en, p * dp.get(i) % MOD);
        }
    }
    cout << ans << endl;
    /*
    rep(i, data.size()) {
        cout << dp.get(i) << " ";
    }cout << endl;
    */

    return 0;
}
