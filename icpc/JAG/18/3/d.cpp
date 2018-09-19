#include<bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < n; i++)
#define int long long 
#define INF 1001000100010001000
#define fir first
#define sec second
#define all(a) (a).begin(), (a).end()

using Weight = int;
using Flow = int;
struct Edge { 
    int s, d; Weight w; Flow c;
    Edge() {};
    Edge(int s, int d, Weight w = 1) : s(s), d(d), w(w), c(w) {};
};
bool operator<(const Edge &e1, const Edge &e2) { return e1.w < e2.w; }
bool operator>(const Edge &e1, const Edge &e2) { return e2 < e1; }

using Edges = vector<Edge>;
using Graph = vector<Edges>;
using Array = vector<Weight>;
using Matrix = vector<Array>;

void addArc(Graph &g, int s, int d, Weight w = 1)
{
    g[s].emplace_back(s, d, w);
}

void addEdge(Graph &g, int a, int b, Weight w = 1)
{
    addArc(g, a, b, w);
    addArc(g, b, a, w);
}


vector<int> dijkstra(const Graph &g, int s, Array &dist)
{
    int n = g.size();
    assert(s < n);
    enum { WHITE, GRAY, BLACK};
    vector<int> color(n, WHITE); color[s] = GRAY;
    vector<int> prev(n, -1);
    dist.assign(n, INF); dist[s] = 0;
    using State = tuple<Weight, int, int>;
    priority_queue<State, vector<State>, greater<State>> pq;
    pq.emplace(0, s, -1);
    while (pq.size()) {
        Weight d; int v, u; tie(d, v, u) = pq.top(); pq.pop();
        if (dist[v] < d) continue;
        color[v] = BLACK; prev[v] = u;
        for (auto &e : g[v]) {
            if (color[e.d] == BLACK) continue;
            if (dist[e.d] > dist[v] + e.w) {
                dist[e.d] = dist[v] + e.w;
                pq.emplace(dist[e.d], e.d, v);
                color[e.d] = GRAY;
            }
        }
    }
    return prev;
}

int prime[201001];

void sieve(void)
{
    memset(prime, 0, sizeof(prime));

    prime[0] = prime[1] = 1;
    for (int i = 2; i * i <= 201000; i++) {
        if (!prime[i]) {
            for (int j = 2; i * j <= 201000; j++) {
                prime[i * j] = 1;
            }
        }
    }
}

int FunamiYui(int yui)
{
    for (int i = yui; i < 201000; i+=2) {
        if (!prime[i]) {
            return i;
        }
    }
    assert(0);
}

signed main()
{
    sieve();
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    s--; t--; s *= 2; t *= 2;

    Graph g(n * 2);
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        a--; b--; a *= 2; b *= 2;
        addEdge(g, a, b+1); // G, K
        addEdge(g, a+1, b);
    }

    vector<int> funami;
    dijkstra(g, s, funami);

    if (funami[t] == 2) {
        cout << 2 << endl;
    } else if (funami[t+1] == INF) {
        cout << -1 << endl;
    } else {
//        cout << "base : " << funami[t+1] << endl;
        cout << FunamiYui(funami[t+1]) << endl;
    }
    return 0;
}
