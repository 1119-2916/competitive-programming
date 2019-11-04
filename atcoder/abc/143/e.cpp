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

//単一始点最短経路(負閉路なし)
//Dijkstra O((|E|+|V|)log|V|)
//dist: 始点から各頂点までの最短距離
//戻り値: 最短経路木の親頂点(根は-1)
void dijkstra(const Graph &g, int s, Array &ans, int L) {
    int n = g.size();
    assert(s < n);
    enum { WHITE, GRAY, BLACK };
    ans.assign(n, INF); ans[s] = 0;
    vi dist(n * (n+1), INF); dist[s * (n+1)] = 0;
    using State = tuple<Weight, int, int, int>; //始点からの最短距離 子 親
    priority_queue<State, vector<State>, greater<State>> pq; pq.emplace(0, 0, s, -1);
    while (pq.size()) {
        Weight d; int sco, v, u; tie(d, sco, v, u) = pq.top(); pq.pop();
        if (dist[v * (n+1) + sco] < d)continue;
        for (auto &e : g[v]) {
            if (dist[v * (n+1) + sco] + e.w <= L) {
                if (dist[e.d * (n+1) + sco] > dist[v * (n+1) + sco] + e.w) {
                    dist[e.d * (n+1) + sco] = dist[v * (n+1) + sco] + e.w;
                    ans[e.d] = min(ans[e.d], sco);
                    pq.emplace(dist[e.d * (n+1) + sco], sco, e.d, v);
                }
            } else {
                if (sco+1 < n+1) {
                    if (dist[e.d * (n+1) + sco + 1] > e.w) {
                        dist[e.d * (n+1) + sco + 1] = e.w;
                        ans[e.d] = min(ans[e.d], sco + 1);
                        pq.emplace(dist[e.d*(n+1)+sco+1], sco+1, e.d, v);
                    }
                }
            }
        }
    }
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int2(n, m);
    Int(l);
    Graph g(n);
    for (int i = 0; i < m; i++) {
        int3(tmpx, tmpy, tmp);
        tmpx--; tmpy--;
        addEdge(g, tmpx, tmpy, tmp);
    }

    vvi ans(n, vi(n));
    rep(i, n) {
        dijkstra(g, i, ans[i], l);
    }

    /*
    rep(i, ans.size()) {
        rep(j, ans.size()) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    */

    Int(q);
    while (q--) {
        int2(a, b);
        a--; b--;
        cout << ans[a][b] << endl;
    }


    return 0;
}



