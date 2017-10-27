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
 
//int dxy[5] = {0, 1, 0, -1, 0};
// assign


class uftree 
{
    public:
        int size;
        vector<int> par, rank, count;
        uftree(int n) : size(n), par(n), rank(n), count(n) {
            for (int i = 0; i < size; i++) {
                par[i] =  i;
                rank[i] = 0;
                count[i] = 1;
            }
        }
        int number(int x) {
            return count[find(x)];
        }
        int find(int x) {
            if (par[x] == x) {
                return x;
            } else {
                return par[x] = find(par[x]);
            }
        }
        void unite(int x, int y) {
            x = find(x);
            y = find(y);
            if (x == y) {
                return ;
            }

            if (rank[x] < rank[y]) {
                par[x] = y;
            } else {
                par[y] = x;
                if (rank[x] == rank[y]) {
                    rank[x]++;
                }
            }
            int tmp = count[x] + count[y];
            count[x] = count[y] = tmp;
        }
        bool same(int x, int y) {
            return find(x) == find(y);
        }
};


signed main()
{
    int2(n, m);
    vector<pair<int, i_i> > g(m);
    rep(i, m) {
        int2(a, b); Int(tmp);
        g[i].first = tmp;
        g[i].second = i_i(a-1, b-1);
    }
    sort(all(g));
    reverse(all(g));
    Int(q);
    vector<pair<i_i, int> > data(q);
    rep(i, q) {
        int2(a, b);
        data[i].first = i_i(b, a-1);
        data[i].second = i;
    }
    sort(all(data));
    reverse(all(data));

    int pt = 0;
    uftree uf(n);
    vi ans(q, 0);
    rep(i, q) {
        while (pt < m && g[pt].first > data[i].first.first) {
            uf.unite(g[pt].second.first, g[pt].second.second);
            pt++;
        }
        ans[data[i].second] = uf.number(data[i].first.second);
    }
    for (int i : ans) {
        cout << i << endl;
    }

    return 0;
}

