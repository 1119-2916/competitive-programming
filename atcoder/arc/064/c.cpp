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
#define vd vector<double>
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

using Weight = double;
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

double funami_yui(pair<i_i, int> a, pair<i_i, int> b)
{
    double tmp = pow((a.ffir - b.ffir), 2) + pow((a.fsec - b.fsec), 2);
    tmp = sqrt(tmp);
    return max(tmp - a.sec - b.sec, 0.0);
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int2(sx, sy); int2(gx, gy);
    Int(n);
    Graph g(n+2);
    vector<pair<i_i, int>> points(n+2);
    points[0] = mp(i_i(sx, sy), 0); points[n+1] = mp(i_i(gx, gy), 0);
    for (int i = 1; i <= n; i++) {
        cin >> points[i].ffir >> points[i].fsec >> points[i].sec;
    }
    rep(i, points.size()) {
        rep(j, i) {
            addEdge(g, i, j, funami_yui(points[i], points[j]));
        }
    }
    vd dist;
    dijkstra(g, 0, dist);
    cout << Decimal << dist[g.size()-1] << endl;

    return 0;
}
