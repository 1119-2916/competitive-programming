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
#define Int(x) int x; scanf("%lld", &x);
#define int2(x, y) int x, y; scanf("%lld %lld", &x, &y);
 
//int dxy[5] = {0, 1, 0, -1, 0};
// assign


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


signed main()
{
    Int(n);
    rep(i, n);

    vp data;
    rep(i, n) {
        int2(a, b);
        data.pb(i_i(a, -b));
    }
    sort(all(data));
    segtree st(100100);
    rep(i, n) {
        int tmp = st.getMin(0, -data[i].second) - 1;
        st.update(-data[i].second, tmp);
    }
    cout << -st.get_allmin() << endl; 
    return 0;
}

