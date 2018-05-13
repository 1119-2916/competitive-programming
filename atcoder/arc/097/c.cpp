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
// BIT avl cusum dijkstra dinic geo2 gin graph kruskal lca lcm matrix ncm next_combination segtree st tmp topcoder uf vi 

struct Monoid {
    using T = int;
    T operator()(const T &a, const T& b) { return a + b; }
    const T I = 0;
};
struct SegmentTree {
    using T = Monoid::T;
    Monoid op;
    int n;
    vector<T> d;
    SegmentTree(int m) {
        for (n = 1; n < m; n *= 2);
        d.assign(2 * n - 1, op.I);
    }
    void update(int k, T x) {
        k += n - 1;
        d[k] = x;
        while (k > 0) {
            k = (k - 1) / 2;
            d[k] = op(d[2 * k + 1], d[2 * k + 2]);
        }
    }
    T query(int a, int b, int k, int l, int r) {
        if (r <= a || b <= l)return op.I;
        if (a <= l&&r <= b)return d[k];
        T xl = query(a, b, 2 * k + 1, l, (l + r) / 2);
        T xr = query(a, b, 2 * k + 2, (l + r) / 2, r);
        return op(xl, xr);
    }
    T query(int a, int b) {
        return query(a, b, 0, 0, n);
    }
};

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    Int(n);
    vector<i_i> data(n * 2);
    vector<int> blac(n, 0), whit(n, 0);
    for (int i = 0; i < n * 2; i++) {
        char tmp; cin >> tmp;
        data[i].fir = (tmp == 'B') ? 1 : 0;
        cin >> data[i].sec;
        if (data[i].fir) {
            blac[data[i].sec] = i;
        } else {
            whit[data[i].sec] = i;
        }
    }
 
    int ans = 0, bl = 0, wh = 0;
    cout << data.size() << endl;
    vb used(data.size(), false);
    cout << "ho" << endl;
    SegmentTree seg(data.size());
    cout << "ho" << endl;
    rep(i, data.size()) seg.update(i, 1);
    cout << "ho" << endl;

    rep(i, data.size()) {
        if (!used[i]) {
            if (data[i].fir) { // black
                for (int j = bl; j < data[i].sec; j++) {
                    ans += seg.query(i, blac[j]);
                    used[blac[j]] = true;
                    seg.update(blac[j], 0);
                }
            } else {
                for (int j = wh; j < data[i].sec; j++) {
                    ans += seg.query(i, whit[j]);
                    used[whit[j]] = true;
                    seg.update(whit[j], 0);
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}


