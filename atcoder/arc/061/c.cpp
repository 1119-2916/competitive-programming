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

Graph g;

//単一始点最短経路(負閉路なし)
//Dijkstra O((|E|+|V|)log|V|)
//dist: 始点から各頂点までの最短距離, assignされるので安心して欲しい
//戻り値: 最短経路木の親頂点(根は-1)
vector<int> dijkstra(const Graph &g, int s, Array &dist) {
    int n = g.size();
    assert(s < n);
    enum { WHITE, GRAY, BLACK };
    vector<int> color(n, WHITE); color[s] = GRAY;
    vector<int> prev(n, -1);
    dist.assign(n, INF); dist[s] = 0;
    //始点からの最短距離 子 親
    typedef pair< int, pair < int, int > > State;
    priority_queue<State, vector<State>, greater<State> > pq;
    pq.push(State(0, i_i(s, -1)));
    while (pq.size()) {
        Weight d = pq.top().first; 
        int v = pq.top().second.first, u = pq.top().second.second; 
        pq.pop();
        if (dist[v] < d)continue;
        color[v] = BLACK; prev[v] = u;
        for (int i = 0; i < g[v].size(); i++) {
            Edge e = g[v][i];
            if (color[e.d] == BLACK)continue;
            if (dist[e.d] > dist[v] + e.w) {
                dist[e.d] = dist[v] + e.w;
                pq.push(State(dist[e.d], i_i(e.d, v)));
                color[e.d] = GRAY;
            }
        }
    }
    return prev;
}

map<i_i, int> id;
int ptr;

int getid(int a, int b)
{
    if (id.find(i_i(a, b)) == id.end()) {
        id.insert(mp(i_i(a, b), ptr));
        g.pb(Edges());
        return ptr++;
    } else {
        return id[i_i(a, b)];
    }
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int2(n, m);
    if (!m) {
        if (n == 1) cout << 0 << endl;
        else cout << -1 << endl;
        return 0;
    }
    vvi ec(n);
    for (int i = 0; i < m; i++) {
        int tmpx, tmpy, color;
        cin >> tmpx >> tmpy >> color;
        tmpx--; tmpy--;
        ec[tmpx].pb(color);
        ec[tmpy].pb(color);
        int a = getid(tmpx, color), b = getid(tmpy, color);
        addEdge(g, a, b, 0);
    }
    rep(i, n) {
        for (int j : ec[i]) {
            int from = getid(i, j), to = getid(i, -1);
            addArc(g, from, to, 0);
            addArc(g, to, from, 1);
        }
    }
    cout << g.size() << endl;
    vi dist;
    dijkstra(g, getid(0, -1), dist);
    if (dist[getid(n-1, -1)] == INF) cout << -1 << endl;
    else cout << dist[getid(n-1, -1)] << endl;

    return 0;
}
