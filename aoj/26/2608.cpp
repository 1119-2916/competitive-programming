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

void bfs(Graph &g, vi &data, int p)
{
    deque<int> mmn;
    mmn.push_back(p);
    while (mmn.size()) {
        deque<int> mm;
        while (mmn.size()) {
            int x = mmn.front();
            mmn.pop_front();
            for (auto i : g[x]) {
                if (data[i.d] == -1) {
                    data[i.d] = data[x] + 1;
                    mm.pb(i.d);
                }
            }
        }
        mmn = mm;
    }
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int2(n, m);
    int2(s, t);

    Graph g(n);
    for (int i = 0; i < m; i++) {
        int2(tmpx, tmpy);
        tmpx--; tmpy--;
        addEdge(g, tmpx, tmpy );
    }
    
    vi mmn(n, -1), mm(n, -1);
    mmn[s-1] = 0;
    mm[t-1] = 0;
    bfs(g, mmn, s-1);
    bfs(g, mm, t-1);

    map<int, int> funami, yui;
    rep(i, mmn.size()) {
        funami[mmn[i]]++;
    }
    rep(i, mm.size()) {
        yui[mm[i]]++;
    }

    int ans = 0;
    for (int i = 0; i < mmn[t-1]-1; i++) {
        ans += funami[i] * yui[mmn[t-1]-2-i];
    }

    std::cout << ans << std::endl;

    return 0;
}






