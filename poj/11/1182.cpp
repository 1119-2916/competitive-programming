#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
#include <stack>
#include <cstdlib>
#include <string>
#include <set>
#include <map>

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
#define Edge pair< int, i_i >
#define all(a) (a).begin(), (a).end()
#define Int(x) int x; scanf("%lld", &x);
#define int2(x, y) int x, y; scanf("%lld %lld", &x, &y);
#define fir first
#define sec second
#define ffir first.first
#define fsec first.second
#define sfir second.first
#define ssec second.second
 
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
            count[x] += count[y];
            count[y] = count[x];
        }
        bool same(int x, int y) {
            return find(x) == find(y);
        }
};


signed main()
{
    int2(n, k);
    int ans = 0;

    uftree uf(n*3);
    rep(i, k) {
        Int(tmp);
        int2(a, b);
        if (a <= 0 || n < a || b <= 0 || n < b) {
            ans++;
            continue;
        }
        a--; b--;
        if (tmp == 1) {
            if (uf.same(a, b+n) || uf.same(a, b+n*2)) {
                ans++;
                continue;
            } else {
                uf.unite(a, b);
                uf.unite(a+n, b+n);
                uf.unite(a+n*2, b+n*2);
            }
        } else {
            if (uf.same(a, b) || uf.same(a, b+n*2)) {
                ans++;
                continue;
            } else {
                uf.unite(a, b+n);
                uf.unite(a+n, b+n+n);
                uf.unite(a+n+n, b);
            }
        }
    }
    cout << ans << endl;

    return 0;
}

