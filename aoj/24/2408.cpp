#include <iostream>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

#define UF uftree
#define MAX_UF 101000

int n, k;

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

int main()
{
    cin >> n >> k;
    n++;
    vector<vector<bool> > rub(n, vector<bool>(n, false));
    vector<bool> use(n, false);
    UF tree(n);
    int ans = 0;

    for (int i = 0; i < k; i++) {
        int m;
        cin >> m;
        int tmp;
        cin >> tmp;
        for (int j = 1; j < m; j++) {
            int t;
            cin >> t;
            tree.unite(tmp, t);
        }
    }

    int r;
    cin >> r;

    for (int i = 0; i < r; i++) {
        int a, b;
        cin >> a >> b;
        if (tree.same(a, b)) {
            if (!use[a]) {
                ans++;
                use[a] = true;
            }
            if (!use[b]) {
                ans++;
                use[b] = true;
            }
        }
    }

    cout << ans << endl;
    return 0;
}

