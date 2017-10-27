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
        i_i dfs(int a,int b,int k,int l,int r)
        {
            //* 要求範囲を含まないレンジの探索.
            if (r <= a || b <= l) {
                return mp(INF, -1);
            }
            //* 木のレンジが要求範囲以下になる時.
            if (a <= l && r <= b) {
                return tree[k];
            }
            int m = (l+r)/2;
            return min(dfs(a, b, k*2+1, l, m), dfs(a, b, k*2+2, m, r));
        }

        i_i min(i_i a, i_i b)
        {
            if (a.first < b.first) {
                return a;
            } else if (a.first > b.first) {
                return b;
            } else if (a.second < b.second) {
                return a;
            } else {
                return b;
            }
        }

    public:
        int size;
        int dist;
        i_i *tree;

        segtree(int tree_size, int c) {
            size = tree_size*2;
            tree = (i_i *)malloc(sizeof(i_i)*size);
            dist = getMin(0, 1).second;
            for (int i = 0; i < size; i++) {
                tree[i] = mp(c, i);
            }
        }

        i_i getMin(int right, int left)
        {
            return dfs(right, left, 0, 0, size/2);
        }

        void update(int pos, int value)
        {
            pos += (size/2 -1);
            tree[pos].first = value;
            while (pos) {
                pos = (pos-1)/2;
                tree[pos] = min(tree[pos*2+1], tree[pos*2+2]);
            }
        }
};


signed main()
{
    int a, b, c;
    cin >> a >> b >> c;
    vi input(a, 0);
    segtree ma(b, -INF);
    cout << ma.dist << endl;

    rep(i, a) {
        cin >> input[i];
        ma.update(i, -input[i]);
    }

    int ans = 0;
    i_i ret;

    rep(i, a) {
        i_i e = ma.getMin(i, min(i+b+1, a));
        //cout << d.second << " " << e.second << endl;
        if (ans < -e.first - input[i]) {
            ans = -e.first - input[i];
            ret.first = i;
            ret.second = e.second;
        }
    }
    if (ans) {
    cout << ans * c << endl;
    cout << ret.first << " " 
        << ret.second - ma.dist << endl;
    } else {
        cout << 0 << endl;
    }
    
    return 0;
}

