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

template <typename T, const T id>
class CHT {
	struct line {
		T a, b;
		line(T a_ = 0, T b_ = 0) : a(a_), b(b_) {}
		T get(T x) { return a * x + b; }
	};
	struct node {
		line l;
		node *lch, *rch;
		node(line l_) : l(l_), lch(nullptr), rch(nullptr) {}
		~node() {
			if (lch) delete lch;
			if (rch) delete rch;
		}
	};

private:
	const int n;
	const vector<T> pos;
	node *root;

public:
	CHT(const vector<T>& pos_) : n(pos_.size()), pos(pos_), root(nullptr) {}
	~CHT() {
		if (root) delete root;
	}
	void insert(T a, T b) {
		line l(a, b);
		root = modify(root, 0, n, l);
	}
	T get(T x) const {
		int t = lower_bound(pos.begin(), pos.end(), x) - pos.begin();
		assert(t < n && pos[t] == x);
		return sub(root, 0, n, t);
	}

private:
	node* modify(node *p, int lb, int ub, line& l) {
		if (!p) return new node(l);
		if (p->l.get(pos[lb]) >= l.get(pos[lb]) && p->l.get(pos[ub - 1]) >= l.get(pos[ub - 1])) return p;
		if (p->l.get(pos[lb]) <= l.get(pos[lb]) && p->l.get(pos[ub - 1]) <= l.get(pos[ub - 1])) {
			p->l = l;
			return p;
		}
		int c = (lb + ub) / 2;
		if (p->l.get(pos[c]) < l.get(pos[c])) swap(p->l, l);
		if (p->l.get(pos[lb]) <= l.get(pos[lb]))
			p->lch = modify(p->lch, lb, c, l);
		else
			p->rch = modify(p->rch, c, ub, l);
		return p;
	}
	T sub(node *p, int lb, int ub, int t) const {
		if (!p) return id;
		if (ub - lb == 1) return p->l.get(pos[t]);
		int c = (lb + ub) / 2;
		if (t < c) return max(p->l.get(pos[t]), sub(p->lch, lb, c, t));
		return max(p->l.get(pos[t]), sub(p->rch, c, ub, t));
	}
};

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int2(n, k);
    vector<int> data(n);
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }
    
    vi arr = data;
    sort(all(arr)); arr.erase(unique(all(arr)), arr.end());

    vvi dp(k+1, vi(n+1, INF));
    dp[0][0] = 0;
    rep(i, k) {
        CHT<int, -INF> funami(arr);
        rep(a, n) {
            funami.insert(2 * data[a], -(dp[i][a] + data[a] * data[a]));
            dp[i+1][a+1] = data[a] * data[a] - funami.get(data[a]);
        }
    }
    cout << dp[k][n] << endl;

    return 0;
}
