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
// cmd

using Weight = int;
using Flow = int;
struct Edge {
    int s, d; Weight w; Flow c;
    int fl;
    Edge() {};
    Edge(int s, int d, Weight w = 1) : s(s), d(d), w(w), c(w), fl(0) {};
};
bool operator<(const Edge &e1, const Edge &e2) { if (e1.fl == e2.fl)return e1.w < e2.w;return e1.fl < e2.fl;}
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

int T, E;

bool suc = false, done = false;
void dfs(Graph &g, vi &cnt, int pos, int pre)
{
    if (done) return;
    ++cnt[pos];
    for (auto p : g[pos]) {
        if (p.d == pre) continue;
        if (done) return;
        if (p.w <= (cnt[pos] + cnt[p.d]) * T) {
            done = true;
            return ;
        }
        dfs(g, cnt, p.d, pos);
        if (done) return;
        if (p.w <= (cnt[pos] + cnt[p.d]) * T) {
            done = true;
            return ;
        }
        if (done) return;
        cnt[pos]++;
    }
    if (pos == E) {
        done = true;
        suc = true;
    }
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int2(n, t);
    int2(st, en);
    st--; en--;

    T = t; E = en;

    Graph g(n);
    for (int i = 1; i < n; i++) {
        int3(tmpx, tmpy, tmpz);
        tmpx--; tmpy--;
        addEdge(g, tmpx, tmpy, tmpz);
    }

    vi dst, den;
    dijkstra(g, st, dst);
    dijkstra(g, en, den);

    vector<bool> pathJoe(n, false);
    { 
        int cost = dst[en];
        rep(i, n) {
            if (dst[i] + den[i] == cost) {
                pathJoe[i] = true;
            }
        }
        rep(i, n) {
            for (int j = 0; j < g[i].size(); j++) {
                if (pathJoe[g[i][j].s] && pathJoe[g[i][j].d]) {
                    g[i][j].fl = 1;
                }
            }
        }
    }
    rep(i, n) {
        sort(all(g[i]));
    }

    vi cnt(n, 0);
    cnt[st] = -1;
    dfs(g, cnt, st, -1);
    if (suc) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }

    return 0;
}
