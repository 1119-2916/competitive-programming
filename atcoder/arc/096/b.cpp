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

struct Monoid {
    using T = int;
    T operator()(const T &a, const T& b) { return max(a, b); }
    const T I = -INF;
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

    int2(n, c);
    vp data(n);
    rep(i, n) {
        cin >> data[i].fir >> data[i].sec;
    }

    vi rtable(n+1, 0);
    int sum = 0;
    Rep(i, rtable.size()) {
        sum += data[i-1].sec;
        rtable[i] = sum - data[i-1].fir;
    }

    vi ltable(n+1, 0);
    sum = 0;
    Rep(i, ltable.size()) {
        sum += data[data.size()-i].sec;
        ltable[i] = sum - (c - data[data.size()-i].fir);
    }

    SegmentTree le(n+1), ri(n+1);
    rep(i, n+1) {
        le.update(i, ltable[i]);
    }
    rep(i, n+1) {
        ri.update(i, rtable[i]);
    }

 //   rep(i, n+1) cout << rtable[i] << " "; cout << endl;
  //  Rep(i, n+1) cout << rtable[i] - data[i-1].fir << " "; cout << endl;
  //  rep(i, n+1) cout << ltable[i] << " "; cout << endl;
   // Rep(i, n+1) cout << ltable[i] - (c-data[n-i].fir) << " "; cout << endl;

    int ans = 0;

    ans = max(ans, le.query(0, n+1));
   // cout << ans << endl;
    Rep(i, n+1) {
        ans = max(ans, rtable[i]);
//    cout << rtable[i] << " " ;
        ans = max(ans, rtable[i] - data[i-1].fir + le.query(0, n+1-i));
 ////   cout << rtable[i] - data[i-1].fir << " " << le.query(0, n+1-i) << " : ";
   // cout << rtable[i] - data[i-1].fir + le.query(0, n+1-i) << endl;
    }

    ans = max(ans, ri.query(0, n+1));
  //  cout << ans << endl;
    Rep(i, n+1) {
        ans = max(ans, ltable[i]);
    //cout << ltable[i] << " " ;
        ans = max(ans, ltable[i] - (c-data[n-i].fir) + ri.query(0, n+1-i));
   // cout << ltable[i] - (c-data[n-i].fir) << " " << ri.query(0, n+1-i) << " : ";
   // cout << ltable[i] - data[n-i-1].fir + ri.query(0, n+1-i) << endl;
    }
    cout << ans << endl;


    return 0;
}




