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
#define fir first
#define sec second
#define ffir first.first
#define fsec first.second
#define sfir second.first
#define ssec second.second

//int dxy[5] = {0, 1, 0, -1, 0};
// assign avl ncm dij geo2 kruskal graph uf

typedef int Weight;
typedef int Flow;
struct Edge {
    int s, d; Weight w; Flow c;
    Edge() {};
    Edge(int s, int d, Weight w = 1) : s(s), d(d), w(w), c(w) {};
};
bool operator<(const Edge &e1, const Edge &e2) { return e1.w < e2.w; }
bool operator>(const Edge &e1, const Edge &e2) { return e2 < e1; }
inline ostream &operator<<(ostream &os, const Edge &e) { return (os << '(' << e.s << ", " << e.d << ", " << e.w << ')'); }

typedef vector<Edge> Edges;
typedef vector<Edges> Graph;
typedef vector<Weight> Array;
typedef vector<Array> Matrix;

void addArc(Graph &g, int s, int d, int w = 1) {
    g[s].push_back(Edge(s, d, w));
}
void addEdge(Graph &g, int a, int b, int w = 1) {
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

signed main()
{

    Int(n);
    vp x(n), y(n);
    rep(i, n) {
        cin >> x[i].fir;
        cin >> y[i].fir;
        x[i].sec = i;
        y[i].sec = i;
    }
    sort(all(x));
    sort(all(y));


    Graph g(n);
    rep(i, n-1) {
        addEdge(g, x[i].sec, x[i+1].sec, x[i+1].fir - x[i].fir);
    }
    rep(i, n-1) {
        addEdge(g, y[i].sec, y[i+1].sec, y[i+1].fir - y[i].fir);
    }

    cout << kruskal(g).fir << endl;

    return 0;
}
