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

    int3(n, x, y);
    int sum = 0;
    
    Graph g(n+2);
    vector<pair<int, pii>> input;
    Rep(i, n) {
        int3(a, b, c);
        input.pb({a, {b, c}});
    }

    vi pupi(n, 0);
    rep(i, x) {
        Int(a); a--;
        pupi[a] = 1;
        addEdge(g, a, n, 100001000010000ll);
    }

    rep(i, y) {
        Int(a); a--;
        pupi[a] = 2;
        addEdge(g, a, n+1, 100001000010000ll);
    }

    rep(i, input.size()) {
        int a = input[i].fir, b = input[i].sfir, c = input[i].ssec;
        a--; b--;
        if (!(pupi[a] && pupi[a] == pupi[b])) {
            addEdge(g, a, b, c);
            sum += c;
        }
    }

    Dinic funami(g);
    cout << funami.solve(n, n+1) << endl;

    return 0;
}
