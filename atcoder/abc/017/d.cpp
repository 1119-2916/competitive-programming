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
#define Int(x) int x; scanf("%lld", &x);
#define int2(x, y) int x, y; scanf("%lld %lld", &x, &y);
#define fir first
#define sec second
#define ffir first.first
#define fsec first.second
#define sfir second.first
#define ssec second.second

//int dxy[5] = {0, 1, 0, -1, 0};
// assign avl ncm dijkstra geo2 kruskal graph uf lca BIT
// matrix dinic

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
		for (; l && l + (l&-l) <= r; l += l&-l) {
			d[(n + l) / (l&-l)] += x;
            d[(n + l) / (l&-l)] %= MOD;
        }
		for (; l < r; r -= r&-r) {
			d[(n + r) / (r&-r) - 1] += x;
			d[(n + r) / (r&-r) - 1] %= MOD;
        }
	}
	int get(int i) {
		int ret = d[n + i];
		for (int j = (n + i) / 2; j > 0; j >>= 1)
			ret += d[j];
		return ret;
	}
};

signed main()
{
    int2(n, m);
    vi data(n);
    rep(i, n) {
        cin >> data[i];
    }

    RangeAddQuery dp(n+1);
    dp.add(0, 1, 1);

    int right = 0;
    vb used(m+1, false);
    rep(i, n) {
        while (right < n && !used[data[right]]) {
            used[data[right]] = true;
            right++;
        }
      //  cout << i+1 << " " << right << " " << dp.get(i) << endl;
        dp.add(i+1, right+1, dp.get(i));
        used[data[i]] = false;
    }

    std::cout << dp.get(n) << std::endl;

    return 0;
}



