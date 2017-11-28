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

//int dxy[5] = {0, 1, 0, -1, 0};
// // assign avl ncm dijkstra geo2 kruskal graph uf lca BIT
// matrix dinic next_combination topcoder lcm vi st gin

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

//単一始点最短経路(負閉路なし)
//Dijkstra O((|E|+|V|)log|V|)
//dist: 始点から各頂点までの最短距離, assignされるので安心して欲しい
void dijkstra(const Graph &g, int s, Array &dist) {
    int n = g.size();
    assert(s < n);
    vector<set<int>> cls(n, set<int>());
    dist.assign(n, INF); dist[s] = 0;
    //始点からの最短距離 鉄道会社 子 親
    typedef pair< int, i_i > State;
    priority_queue<State, vector<State>, greater<State> > pq;
    for (Edge i : g[s]) pq.push(State(1, i_i(i.w, i.d)));
    while (pq.size()) {
        Weight cost = pq.top().first; 
        int color = pq.top().second.first, pos = pq.top().second.second; 
        pq.pop();
        if (dist[pos] < cost) {
            continue;
        } else if (dist[pos] > cost) {
            dist[pos] = cost;
            cls[pos] = set<int>();
        } else if (cls[pos].find(color) != cls[pos].end()) {
            continue;
        }
        cls[pos].insert(color);
        for (Edge i : g[pos]) {
            if (i.w == color) pq.push(State(cost, i_i(i.w, i.d)));
            else pq.push(State(cost+1, i_i(i.w, i.d)));
        }
    }
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int2(n, m);
    Graph g(n);
    for (int i = 0; i < m; i++) {
        int tmpx, tmpy, color;
        cin >> tmpx >> tmpy >> color;
        tmpx--; tmpy--;
        addEdge(g, tmpx, tmpy, color);
    }
    //cout << "read" << endl;
    vi dist;
    dijkstra(g, 0, dist);
    if (dist[n-1] == INF) cout << -1 << endl;
    else cout << dist[n-1] << endl;

    return 0;
}
