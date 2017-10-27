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
// assign avl ncm dijkstra geo2 kruskal graph uf lca BIT
// matrix dinic

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

deque<int> solve(Graph &g)
{
    deque<int> ret;
    int st = 0, en = g[0][0].d;
    ret.pb(st); ret.pb(en);
    UnionFind uf(g.size());
    uf.unite(st, en);
//    rep(i, ret.size()) cout << ret[i] << " "; cout << endl;
    while (1) {
        bool stop = true;
        rep(i, g[st].size()) {
            if (!uf.same(g[st][i].d, st)) {
                uf.unite(st, g[st][i].d);
                st = g[st][i].d;
                stop = false;
                ret.push_front(st);
                break;
            }
        }
        if (stop) break;
 //   rep(i, ret.size()) cout << ret[i] << " "; cout << endl;
    }
    while (1) {
        bool stop = true;
        rep(i, g[en].size()) {
            if (!uf.same(g[en][i].d, en)) {
                uf.unite(en, g[en][i].d);
                en = g[en][i].d;
                stop = false;
                ret.pb(en);
                break;
            }
        }
        if (stop) break;
  //  rep(i, ret.size()) cout << ret[i] << " "; cout << endl;
    }
   // rep(i, ret.size()) cout << ret[i] << " "; cout << endl;
    return ret;
}

signed main()
{
    int2(n, m);
    Graph g(n);
    rep(i, m) {
        int2(a, b);
        a--; b--;
        addEdge(g, a, b);
    }

    deque<int> ans = solve(g);
    std::cout << ans.size() << std::endl;
    rep(i, ans.size()) {
        std::cout << ans[i]+1 << " ";
    }cout << endl;

    return 0;
}


