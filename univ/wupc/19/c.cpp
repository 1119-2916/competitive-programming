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

using Weight = int;
using Flow = int;
struct Edge {
    int s, d; Weight w; Flow c;
    Edge() {};
    Edge(int s, int d, Weight w = 1) : s(s), d(d), w(w), c(w) {};
};
bool operator<(const Edge &e1, const Edge &e2) { return e1.w < e2.w; }
bool operator>(const Edge &e1, const Edge &e2) { return e2 < e1; }
inline ostream &operator<<(ostream &os, const Edge &e) { return (os << '(' << e.s << ", " << e.d << ", " << e.w << ')'); }

using Edges = vector<Edge>;
using Graph = vector<Edges>;
using Array = vector<Weight>;
using Matrix = vector<Array>;

void addArc(Graph &g, int s, int d, Weight w = 1) {
    g[s].emplace_back(s, d, w);
}
void addEdge(Graph &g, int a, int b, Weight w = 1) {
    addArc(g, a, b, w);
    addArc(g, b, a, w);
}

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

//最小全域木 (Minimum Spanning Tree)
//Kruskal O(|E|log|E|)
//非連結グラフでは最小全域森
// ** 要include uf, graph ** 
pair<Weight, Edges> kruskal(const Graph &g) {
    int n = g.size();
    UnionFind uf(n);
    Edges es;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < g[i].size(); j++) {
            Edge e = g[i][j];
            //for (auto &e : g[i])
            es.push_back(e);
        }
    sort(es.begin(), es.end());
    Weight total = 0;
    Edges mst;
    for (int i = 0; i < es.size(); i++) {
        Edge e = es[i];
        //for (auto &e : es)
        if (!uf.same(e.s, e.d)) {
            uf.unite(e.s, e.d);
            mst.push_back(e);
            total += e.w;
        }
    }
    return make_pair(total, mst);
}

int mmnmm(Graph &g, vi &used, vi &ans, int p)
{
    vi funami;
    used[p] = 1;
    for (auto i : g[p]) {
        if (!used[i.d]) {
            int tmp = mmnmm(g, used, ans, i.d);
            if (tmp != -1) {
                funami.pb(tmp);
            }
        }
    }
    /*
    std::cout << "funami" << std::endl;
    rep(i, funami.size()) {
        std::cout << funami[i] << " ";
    }cout << endl;
    */
    if (!funami.size()) {
        return p;
    }
    if (funami.size() == 1) {
        ans[funami[0]] = p+1;
        ans[p] = funami[0]+1;
        return -1;
    }
    sort(all(funami));
    Rep(i, funami.size()) {
        ans[funami[i]] = funami[i-1]+1;
    }
    ans[funami[0]] = funami.back()+1;
    return p;
}


signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int2(n, m);
    Graph g(n);
    for (int i = 0; i < m; i++) {
        int2(tmpx, tmpy);
        tmpx--; tmpy--;
        addEdge(g, tmpx, tmpy);
    }

    auto ret = kruskal(g);
    Graph h(n);
    rep(i, ret.sec.size()) {
        addEdge(h, ret.sec[i].s, ret.sec[i].d);
    }
    /*
    std::cout << "ikiki" << std::endl;
    for (auto i : h) {
        for (auto j : i) {
            std::cout << j.d << " ";
        }
        cout << endl;
    }
    */
    vi used(n, 0), ans(n, 0);
    int p = 0;
    rep(i, n) {
        if (h[i].size() == 1) p = i;
    }
    mmnmm(h, used, ans, p);
    /*
    cout << "p : " << p << endl;
    rep(i, ans.size()) cout << ans[i] << " "; cout << endl;
    */
    if (!ans[p]) {
        ans[p] = p + 1;
        swap(ans[p], ans[h[p][0].d]);
    }

    rep(i, ans.size()) {
        std::cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}


