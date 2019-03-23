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

struct SegmentTree {
	int n;
	vector<int> d;
	vector<int> timestamp;
	int time;
	RangeUpdateQuery(int m) {
		for (n = 1; n < m; n *= 2);
		d.assign(n * 2, INF);
		time = 0;
		timestamp.assign(n * 2, 0);
	}
	//[l, r)
	void update(int l, int r, int x) {
		time++;
		for (; l && l + (l&-l) <= r; l += l&-l) {
			d[(n + l) / (l&-l)] = x;
			timestamp[(n + l) / (l&-l)] = time;
		}
		for (; l < r; r -= r&-r) {
			d[(n + r) / (r&-r) - 1] = x;
			timestamp[(n + r) / (r&-r) - 1] = time;
		}
	}
	int get(int i) {
		int ret = d[n + i];
		int max_time = timestamp[n + i];
		for (int j = (n + i) / 2; j > 0; j >>= 1) {
			if (max_time > timestamp[j])continue;
			max_time = timestamp[j];
			ret = d[j];
		}
		return ret;
	}
};

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int3(n, m, k);
    vp data(m);
    rep(i, m) {
        cin >> data[i].fir >> data[i].sec;
    }

    vvi funami(n, vi(n, 0));
    rep(i, n) {
        int cnt = 0, le = i, ri = i;
        rep(j, m) {
            if (in(i, data[i].fir, data[i].sec)) {
                cnt++;
                le = min(le, data[i].fir);
                ri = max(ri, data[i].sec);
            }
        }
        funami[i] = {{le, ri}, cnt};
    }

    SegmentTree mmnmm(n);
    mmnmm.update(0, 1, 1);

    rep(i, k) {
        SegmentTree next(n);
        rep(j, n) {



    return 0;
}
