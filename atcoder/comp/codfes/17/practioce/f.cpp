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
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    Int(n);
    vector<i_i> data(n);
    for (int i = 0; i < n; i++) {
        cin >> data[i].fir;
        data[i].sec = i;
    }
    sort(all(data));
    reverse(all(data));
    
    segtree funami_yui(n+1, 0);

    vi toshino_kyoko;
    vi ans(n, 0);
    int bef = data[0].fir;
    rep(i, n) {
        //cout << "#" << i << endl;
        if (bef == data[i].fir) {
            toshino_kyoko.pb(data[i].sec);
            int l = 0, r = data[i].sec;
            while (l + 1 < r) {
                int mid = (l + r) / 2;
                if (funami_yui.getMin(mid, data[i].sec+1) == -1) {
                    l = mid;
                } else {
                    r = mid;
                }
            }
            int yui = r;
            if (funami_yui.getMin(l, data[i].sec+1) != -1) {
                yui = l;
            }
            l = data[i].sec; r = n;
            while (l + 1 < r) {
                int mid = (l + r) / 2;
                if (funami_yui.getMin(data[i].sec, mid+1) == -1) {
                    r = mid;
                } else {
                    l = mid;
                }
            }
            //cout << yui << " " << l << endl;
            ans[data[i].sec] = l - data[i].sec + data[i].sec - yui;
        } else {
            rep(j, toshino_kyoko.size()) {
                funami_yui.update(toshino_kyoko[j], -1);
            }
            toshino_kyoko = vi();
            bef = data[i].fir;
            i--;
        }
    }

    rep(i, n) {
        cout << ans[i] << endl;
    }


    return 0;
}


