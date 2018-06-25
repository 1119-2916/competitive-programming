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

struct UnionFind {
    vector<int> parent;
    int size;
    UnionFind(int n) :parent(n, -1), size(n) {}
    bool unite(int x, int y) {
        x = root(x); y = root(y);
        if (x == y)return false;
        if (sizeOf(x) < sizeOf(y))swap(x, y);
        parent[x] += parent[y]; parent[y] = x; size--;
        return true;
    }
    bool same(int x, int y) { return root(x) == root(y); }
    int root(int x) { return parent[x] < 0 ? x : parent[x] = root(parent[x]); }
    int sizeOf(int x) { return -parent[root(x)]; }
};

i_i solve(UnionFind &uf, vi &table, vb &used, int pos)
{
    i_i ret; ret.fir = 0; ret.sec = 0, cnt = 0;
    if (table[pos] == -1) ret.fir++;
    else ret.sec++;
    rep(i, table.size()) {
        if (i == pos) continue;
        if (!used[i] && uf.same(pos, i+table.size())) {
            table[i] = -table[pos];
            used[i] = true;
            solve(uf, table, used, i);
        }
    }
    if (table[pos] == -1) ret.fir++;
    else ret.sec++;



signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int2(n, m);
    vvb graph(n, vb(n, false));

    rep(i, m) {
        int2(s, t);
        s--; t--;
        graph[s][t] = graph[t][s] = true;
    }
    
    UnionFind uf(n * 2);
    rep(i, n) {
        for (int j = i + 1; j < n; j++) {
            if (!graph[i][j]) {
                uf.unite(i, j + n);
                uf.unite(i + n, j);
            } else {
                uf.unite(i, j);
                uf.unite(i+n, j+n);
            }
        }
    } 

    rep(i, n) {
        rep(j, n) {
            if (i == j) continue;
            if (uf.same(i, j) == uf.same(i, j+n)) {
                cout << -1 << endl;
                return 0;
            }
        }
    }

    vi table(n, 0);
    vb used(n, false);
    rep(i, n) {
        solve(uf, table, i);
        vi cnt;
        rep(j, n) {
            if (i == j) continue;
            if (uf.same(i, j+n)) {
                cnt.pb(j);
            }
        }
        if (cnt.size()) {
            int pos = 0;
            rep(j, cnt.size()) {
                if (!pos && table[cnt[j]]) pos = table[cnt[j]];
                else if (pos != table[cnt[j]]) {
                    cout << -1 << endl;
                    return 0;
                }
            }
            if (pos) table[i] = -pos;
            else {
                pos = 1;
                table[i] = -pos;
            }
            rep(j, cnt.size()) {
                table[cnt[j]] = pos;
            }
        }
    }

    int cnt = 0, yui = 0, kyoko = 0;
    rep(i, n) {
        if (!table[i]) cnt++;
        else if (table[i] == 1) yui++;
        else kyoko++;
    }

    while (cnt) {
        if (yui < kyoko) yui++;
        else kyoko++;
        cnt--;
    }

    cout << (yui * (yui - 1) / 2) + (kyoko * (kyoko - 1) / 2) << endl;

    return 0;
}



