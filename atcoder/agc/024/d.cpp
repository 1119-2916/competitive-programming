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
// BIT avl cusum dijkstra dinic geo2 gin graph kruskal lca lcm matrix ncm next_combination segtree st tmp topcoder uf vi 

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

int n;

int max_high(Graph &g, int pos, int pre, int rank)
{
    int ret = rank;
    for (Edge e : g[pos]) {
        int i = e.d;
        if (i == pre) continue;
        ret = max(ret, max_high(g, i, pos, rank+1));
    }
    return ret;
}

int ha(Graph &g, int pos, int pre)
{
    bool fl = true;
    int ret = 0;
    for (Edge e : g[pos]) {
        int i = e.d;
        if (i == pre) continue;
        fl = false;
        ret += ha(g, i, pos);
    }
    return ret + ( (fl) ? 1 : 0 );
}

i_i solve(Graph &g, int top)
{
    vvi data(0, vi(0));
    i_i ret = {-1, -1};
    for (Edge e : g[top]) {
        int i = e.d;
        ret.fir = max(max_high(g, i, top, 1)+1, ret.fir);
        ret.sec = max((int)(g[top].size() * ha(g, i, top)), ret.sec);
    }
    return ret;
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    cin >> n;
    if (n == 2) {
        cout << "1 2" << endl;
        return 0;
    }
    Graph g(n);

    Rep(i, n) {
        int2(a, b);
        a--; b--;
        addEdge(g, a, b);
    }

    i_i ans = {INF, INF};
    rep(i, n) {
        i_i tmp = solve(g, i);
        if (tmp.fir == -1 || tmp.sec == -1) continue;
        if (ans.fir > tmp.fir) ans = tmp;
        else if (ans.fir == tmp.fir) ans.sec = min(ans.sec, tmp.sec);
    }

    cout << ans.fir << " " << ans.sec << endl;

    return 0;
}



