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

bool mm(vvi &data, vi &dg, int p, int num)
{
    dg[p] = num;
    bool ret = true;
    rep(i, data.size()) {
        if (i != p && data[i][p]) {
            if (!dg[i]) {
                ret &= mm(data, dg, i, (num == 1LL ? 2LL : 1LL));
            } else if (dg[i] == dg[p]) {
                return false;
            }
        }
    }
    return ret;
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    

    Int(n);
    vvi data(n, vi(n, 0));
    vi digraph(n, 0);

    vector<string> shami(n);
    rep(i, n) {
        cin >> shami[i];
    }

    rep(i, n) {
        rep(j, n) {
            data[i][j] = shami[i][j] - '0';
        }
    }

    bool ret = true;
    rep(i, n) {
        if (!digraph[i]) {
            ret &= mm(data, digraph, i, 1LL);
        }
    }

    if (!ret) {
        std::cout << -1 << std::endl;
        return 0;
    }

    rep(i, n) {
        rep(j, n) {
            if (i == j) continue;
            if (data[i][j] == 0) data[i][j] = INF;
        }
    }
    
    rep(k, n) rep(i, n) rep(j, n)
        data[i][j] = min(data[i][j], data[i][k] + data[k][j]);

    int ans = 0;
    rep(i, n) {
        rep(j, n) {
            if (data[i][j] != INF) ans = max(ans, data[i][j]);
        }
    }

    std::cout << ans + 1 << std::endl;


    return 0;
}
