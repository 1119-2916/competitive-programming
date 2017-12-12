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
// // assign avl ncm dijkstra geo2 kruskal graph uf lca BIT
// matrix dinic next_combination topcoder lcm vi st gin

class segtree
{
    private:
        int dfs(int a,int b,int k,int l,int r)
        {
            //* 要求範囲を含まないレンジの探索.
            if (r <= a || b <= l) {
                return INF;
            }
            //* 木のレンジが要求範囲以下になる時.
            if (a <= l && r <= b) {
                return tree[k];
            }
            int m = (l+r)/2;
            return min(dfs(a, b, k*2+1, l, m), dfs(a, b, k*2+2, m, r));
        }
    public:
        int size;
        vi tree;

        segtree(int _size, int _firstnum){
            size = 1;
            while (size < _size) size *= 2;
            size <<= 1;
            tree = vi(size, 0);
            if (_firstnum) {
                rep(i, tree.size()) tree[i] = _firstnum;
            }
        }
        segtree(int _size){
            size = 1;
            while (size < _size) size *= 2;
            size <<= 1;
            tree = vi(size, 0);
        }
        int getMin(int left, int right)
        {
            return dfs(left, right, 0, 0, size/2);
        }
        void update(int pos, int value)
        {
            pos += (size/2 -1);
            tree[pos] = value;
            while (pos) {
                pos = (pos-1)/2;
                tree[pos] = min(tree[pos*2+1], tree[pos*2+2]);
            }
        }
        int get_allmin()
        {
            return tree[0];
        }
};

template< class T >
struct BinaryIndexedTree
{
    vector< T > data;

    BinaryIndexedTree(int sz)
    {
        data.assign(++sz, 0);
    }

    T sum(int k)
    {
        T ret = 0;
        for(++k; k > 0; k -= k & -k) ret += data[k];
        return (ret);
    }

    void add(int k, T x)
    {
        for(++k; k < data.size(); k += k & -k) data[k] += x;
    }
};

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    Int(n);
    vector<int> data(n);
    segtree seg(n);
    for (int i = 0; i < n; i++) {
        cin >> data[i];
        seg.update(i, -data[i]);
    }

    vb record(n+1, false);
    int yui = 0;
    rep(i, n) {
        record[data[i]] = data[i] > yui;
        yui = max(yui, data[i]);
    }

    vi cnt(n+1, 0);
    BinaryIndexedTree<int> funami(n+1);
    rep(i, n) {
        if (funami.sum(data[i]) == i - 1) {
            cnt[-seg.getMin(0, i)]++;
        }
        funami.add(data[i], 1);
    }

    int ans = 0;
    Rep(i, n+1) {
        if (cnt[ans] < cnt[i]) {
            ans = i;
        }
    }

    if (ans && cnt[ans] > 1) {
        cout << ans << endl;
        return 0;
    } else {
        Rep(i, n+1) {
            if (!record[i]) {
                cout << i << endl;
                return 0;
            }
        }
    }
    cout << 1 << endl;

    return 0;
}



