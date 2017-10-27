#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <map>

using namespace std;

#define UF uftree
#define MAX_UF 101000
#define rep(i, n) for (int i = 0; i < n; i++)

typedef pair<int, int> i_i;

int n, k, l;

class uftree 
{
    public:
        int size;
        vector<int> par, rank;
        uftree(int n) : size(n), par(n), rank(n) {
            for (int i = 0; i < size; i++) {
                par[i] =  i;
                rank[i] = 0;
            }
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
        }
        bool same(int x, int y) {
            return find(x) == find(y);
        }
};

signed main()
{
    cin >> n >> k >> l;

    UF road(n);
    rep(i, k) {
        int a, b;
        cin >> a >> b;
        road.unite(a-1, b-1);
    }
    UF line(n);
    rep(i, l) {
        int a, b;
        cin >> a >> b;
        line.unite(a-1, b-1);
    }
    map<i_i, int> ans;
    rep(i, n) {
        ans[i_i(road.find(i), line.find(i))]++;
    }
    rep(i, n) {
        cout << (i ? " " : "") << ans[i_i(road.find(i), line.find(i))];
    }
}

