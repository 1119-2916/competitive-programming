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
// // assign avl ncm dijkstra geo2 kruskal graph uf lca BIT
// matrix dinic next_combination topcoder lcm vi st gin
// cusum segtree

using Weight = int;
using Flow = int;
struct Edge {
    int s, d; Weight w; Flow c;
    Edge() {};
    Edge(int s, int d, Weight w) : s(s), d(d), w(w), c(w) {};
    Edge(int s, int d, Weight w, Flow c):s(s), d(d), w(w), c(c) {};
};
bool operator<(const Edge &e1, const Edge &e2) { return e1.w < e2.w; }
bool operator>(const Edge &e1, const Edge &e2) { return e2 < e1; }
inline ostream &operator<<(ostream &os, const Edge &e) { return (os << '(' << e.s << ", " << e.d << ", " << e.w << ')'); }

using Edges = vector<Edge>;
using Graph = vector<Edges>;
using Array = vector<Weight>;
using Matrix = vector<Array>;

void addArc(Graph &g, int s, int d, Weight w, Flow c) {
    g[s].emplace_back(s, d, w, c);
}
void addArc(Graph &g, int s, int d, Weight w) {
    g[s].emplace_back(s, d, w);
}
void addEdge(Graph &g, int a, int b, Weight w = 1, Flow c = 1) {
    addArc(g, a, b, w, c);
    addArc(g, b, a, w, c);
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

/* 
 * 必ずgraphも一緒にincludeすること
 */
struct Dinic {
    int n, s, t;
    vector<int> level, prog, que;
    vector< vector< Flow > > cap, flow;
    vector< vector < int > > g;
    Flow inf;
    Dinic(const Graph &graph)
        : n(graph.size()),
        cap(n, vector<Flow>(n)),
        flow(n, vector<Flow>(n)),
        g(n, vector<int>()),
        inf(numeric_limits<Flow>::max() / 8) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < graph[i].size(); j++) {
                    Edge e = graph[i][j];
                    int u = e.s, v = e.d;
                    Flow c = e.c;
                    cap[u][v] += c;
                    cap[v][u] += c;
                    flow[v][u] += c;
                    g[u].push_back(v);
                    g[v].push_back(u);
                }
            }
        }
    inline Flow residue(int u, int v) { return cap[u][v] - flow[u][v]; }
    Flow solve(int s_, int t_) {
        this->t = t_, this->s = s_;
        que.resize(n + 1);
        Flow res = 0;
        while (levelize()) {
            prog.assign(n, 0);
            res += augment(s, inf);
        }
        return res;
    }
    bool levelize() {
        int l = 0, r = 0;
        level.assign(n, -1);
        level[s] = 0;
        que[r++] = s;
        while (l != r) {
            int v = que[l++];
            if (v == t) break;
            for (int i = 0; i < g[v].size(); i++) {
                int d = g[v][i];
                if (level[d] == -1 && residue(v, d) != 0) {
                    level[d] = level[v] + 1;
                    que[r++] = d;
                }
            }
        }
        return level[t] != -1;
    }
    Flow augment(int v, Flow lim) {
        Flow res = 0;
        if (v == t) return lim;
        for (int &i = prog[v]; i < (int)g[v].size(); i++) {
            const int &d = g[v][i];
            if (residue(v, d) == 0 || level[v] >= level[d]) continue;
            const Flow aug = augment(d, min(lim, residue(v, d)));
            flow[v][d] += aug;
            flow[d][v] -= aug;
            res += aug;
            lim -= aug;
            if (lim == 0) break;
        }
        return res;
    }
};

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int2(n, m);
    int2(s, t);
    s--; t--;

    vector<pair<i_i, i_i>> input(m);
    rep(i, m) {
        int2(a, b); int2(c, d);
        a--; b--;
        input[i] = {{a, b}, {c, d}};
    }

    Graph g_st(n);
    for (int i = 0; i < m; i++) {
        addArc(g_st, input[i].ffir, input[i].fsec, 
                input[i].sfir, input[i].ssec);
    }

    Graph g_en(n);
    for (int i = 0; i < m; i++) {
        addArc(g_en, input[i].fsec,  input[i].ffir,
                input[i].sfir, input[i].ssec);
    }

    vi dist_st, dist_en;
    dijkstra(g_st, s, dist_st);
    dijkstra(g_en, t, dist_en);

    int min_cost = dist_st[t];

    Graph g(n);
    rep(i, m) {
        if (dist_st[input[i].ffir] + dist_en[input[i].fsec] + input[i].sfir
                == min_cost) {
            addArc(g, input[i].ffir, input[i].fsec, input[i].ssec);
        }
    }

    Dinic funami(g);
    cout << funami.solve(s, t) << endl;

    return 0;
}
