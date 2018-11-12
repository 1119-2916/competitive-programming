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
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vi >
#define vb vector<bool>
#define vvb vector<vb >
#define vp vector< pii >
#define all(a) (a).begin(), (a).end()
#define Int(x) int x; cin >> x;
#define int2(x, y) Int(x); Int(y);
#define int3(x, y, z) Int(x); int2(y, z);
#define in(x, a, b) ((a) <= (x) && (x) < (b))
#define fir first
#define sec second
#define ffir first.first
#define fsec first.second
#define sfir second.first
#define ssec second.second
#define Decimal fixed << setprecision(10)

//int dxy[5] = {0, 1, 0, -1, 0};
// 01Trie BIT CHT DFT FFT avl cmd cusum dijkstra dinic geo2 gin graph kruskal lca lcm matrix ncm next_combination ppuf segtree st tmp topcoder uf vi 

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

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int3(n, m, q);
    UnionFind funami(n+n);
    map<string, int> toshino;
    rep(i, n) {
        string st; cin >> st;
        toshino[st] = i;
    }

    rep(i, m) {
        Int(cmd);
        string a; cin >> a;
        string b; cin >> b;
        if (cmd == 1) {
            if (funami.same(toshino[a], toshino[b] + n)) {
                std::cout << "NO" << std::endl;
            } else {
                std::cout << "YES" << std::endl;
                funami.unite(toshino[a], toshino[b]);
                funami.unite(toshino[a] + n, toshino[b] + n);
            }
        } else {
            if (funami.same(toshino[a], toshino[b])) {
                std::cout << "NO" << std::endl;
            } else {
                std::cout << "YES" << std::endl;
                funami.unite(toshino[a] + n, toshino[b]);
                funami.unite(toshino[a], toshino[b] + n);
            }
        }
    }

    while (q--) {
        string a; cin >> a;
        string b; cin >> b;
        if (funami.same(toshino[a], toshino[b])) {
            std::cout << 1 << std::endl;
        } else if (funami.same(toshino[a], toshino[b] + n)) {
            std::cout << 2 << std::endl;
        } else {
            std::cout << 3 << std::endl;
        }
    }

    return 0;
}
