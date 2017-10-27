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

struct RangeAddQuery {
	int n;
	vector<double> d;
	double time;
	RangeAddQuery(int m) {
		for (n = 1; n < m; n *= 2);
		d.assign(n * 2, 0.0);
	}
	//[l, r)
	void add(int l, int r, double x) {
		for (; l && l + (l&-l) <= r; l += l&-l)
			d[(n + l) / (l&-l)] += x;
		for (; l < r; r -= r&-r)
			d[(n + r) / (r&-r) - 1] += x;
	}
	double get(int i) {
		double ret = d[n + i];
		for (int j = (n + i) / 2; j > 0; j >>= 1)
			ret += d[j];
		return ret;
	}
};


vector<double> ans;
RangeAddQuery tree(0);
int n, cnt;

void solve(int l, int r)
{
    cout << l << " " << r << endl;
    if (l >= r || l < 0 || n < r) return ;
    if (l+1 == r) {
        //tree.add(l, r, 1.0);
        return ;
    }

    //cout << l << " " << r << endl;
    tree.add(l, r, (double)(r-l)/2.0f);
    
    rep(i, n) {
        printf("%.7lf ", tree.get(i));
    }
    cout << endl;
    
    if ((l+r)%2) {
        solve(l, (l+r)/2);
        solve((l+r)/2, r);
        solve(l, (l+r)/2+1);
        solve((l+r)/2+1, r);
    } else {
        solve(l, (l+r)/2);
        solve((l+r)/2, r);
    }

}

signed main()
{
    cin >> n;
    ans = vector<double>(n, 0.00);
    tree = RangeAddQuery(n);
    solve(0, n);
    //if (n != 1) 
        tree.add(0, n, (double)n);
    rep(i, n) {
        printf("%.7lf ", tree.get(i));
    }
    cout << endl;

    return 0;
}
