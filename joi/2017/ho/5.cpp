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
// BIT DiscreteFourierTransform FFT PPuf avl cmd cusum dijkstra dinic geo2 gin graph kruskal lca lcm matrix ncm next_combination segtree st tmp topcoder uf vi 

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

//単一始点最短経路(負閉路なし)
//Dijkstra O((|E|+|V|)log|V|)
//dist: 始点から各頂点までの最短距離
//戻り値: 最短経路木の親頂点(根は-1)
vector<int> dijkstra(const Graph &g, int s, Array &dist) {
    int n = g.size();
    assert(s < n);
    enum { WHITE, GRAY, BLACK };
    vector<int> color(n, WHITE); color[s] = GRAY;
    vector<int> prev(n, -1);
    dist.assign(n, INF); dist[s] = 0;
    using State = tuple<Weight, int, int>; //始点からの最短距離 子 親
    priority_queue<State, vector<State>, greater<State>> pq; pq.emplace(0, s, -1);
    while (pq.size()) {
        Weight d; int v, u; tie(d, v, u) = pq.top(); pq.pop();
        if (dist[v] < d)continue;
        color[v] = BLACK; prev[v] = u;
        for (auto &e : g[v]) {
            if (color[e.d] == BLACK)continue;
            if (dist[e.d] > dist[v] + e.w) {
                dist[e.d] = dist[v] + e.w;
                pq.emplace(dist[e.d], e.d, v);
                color[e.d] = GRAY;
            }
        }
    }
    return prev;
}

/**
 * parent : size を負で持つ。負値でなければ参照する親のindexを持つ
 * timestamp : uniteされた時間を持つ
 * history : uniteされる寸前のtimeとsizeを持つ
 */
struct PartiallyPersistentUnionFind
{
    using data_type = int;
    vector<data_type> parent, timestamp;
    vector< vector< pair< data_type, data_type > > > history;

    PartiallyPersistentUnionFind() {}

    PartiallyPersistentUnionFind(int sz)
        : parent(sz, (data_type)-1), timestamp(sz, INF), history(sz)
    {
        for (auto &vs : history) vs.emplace_back((data_type)-1, (data_type)-1);
    }

    bool unite(int t, int x, int y)
    {
        x = find(t, x);
        y = find(t, y);
        if (x == y) return false;
        if (parent[x] > parent[y]) swap(x, y);
        parent[x] += parent[y];
        history[x].emplace_back(t, parent[x]);
        parent[y] = x;
        timestamp[y] = t;
        return true;
    }
    int find(int t, int x)
    {
        if (t < timestamp[x]) return x;
        return find(t, parent[x]);
    }

    int size(int t, int x)
    {
        x = find(t, x);
        return -prev(lower_bound(begin(history[x]), end(history[x]), 
                    make_pair(t, (data_type)0)))->second;
    }
    bool same(int t, int x, int y)
    {
        return find(t, x) == find(t, y);
    }
};

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int2(n, m);
    int2(k, q);

    Graph g(n+1);
    vp toshino(m);
    for (int i = 0; i < m; i++) {
        int2(tmpx, tmpy);
        Int(tmpz);
        addEdge(g, tmpx, tmpy, tmpz);
        toshino[i].fir = tmpx;
        toshino[i].sec = tmpy;
    }
    rep(i, k) {
        Int(tmp);
        addEdge(g, 0, tmp, 0);
    }

    vi funami;
    dijkstra(g, 0, funami);
    PartiallyPersistentUnionFind uf(n+1);
    vector<pair<int, pii>> yui(m);
    rep(i, m) {
        yui[i].fir = 
            210001000 - min(funami[toshino[i].fir], funami[toshino[i].sec]);
        yui[i].sfir = toshino[i].fir;
        yui[i].ssec = toshino[i].sec;
    }
    sort(all(yui));
    rep(i, yui.size()) {
        uf.unite(yui[i].fir, yui[i].sfir, yui[i].ssec);
    }
    while (q--) {
        int2(s, t);
        int left = 0, right = 210001001;
        while (right - left > 1) {
            int mid = (right + left) / 2;
            if (uf.same(mid, s, t)) {
                right = mid;
            } else {
                left = mid;
            }
        }
        if (right == 210001001) cout << 0 << endl;
        else cout << 210001000 - right << endl;
    }

    return 0;
}
