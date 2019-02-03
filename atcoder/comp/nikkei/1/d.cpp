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

int MomoneMomo(Graph &g, vi &table, int pos)
{
    if (table[pos] == -1) {
        int ret = 0;
        for (auto i : g[pos]) {
            ret = max(ret, MomoneMomo(g, table, i.d) + 1);
        }
        return table[pos] = ret;
    } else {
        return table[pos];
    }
}

void bfs(Graph &g, vi &rank, int node)
{
    queue<int> now;
    now.push(node);
    while (now.size()) {
        queue<int> nxt;
        while (now.size()) {
            int pos = now.front(); now.pop();
            //cout << "call : " << pos << endl;
            rep(i, g[pos].size()) {
                nxt.push(g[pos][i].d);
                rank[g[pos][i].d] = rank[pos]+1;
            }
        }
        now = nxt;
    }
}

vi tps(Graph &g)
{
    vi cnt(g.size(), 0);
    rep(i, g.size()) {
        rep(j, g[i].size()) {
            cnt[g[i][j].d]++;
        }
    }
    vi ret;
    queue<int> nxt;
    rep(i, g.size()) if (!cnt[i]) nxt.push(i);

    int pos = 0;
    while (nxt.size()) {
        pos = nxt.front(); nxt.pop();
        ret.pb(pos);
        rep(i, g[pos].size()) {
            cnt[g[pos][i].d]--;
            if (!cnt[g[pos][i].d]) {
                nxt.push(g[pos][i].d);
            }
        }
    }

    return ret;
}

//01Trie BIT CHT DFT FFT avl cmd cusum dijkstra dinic geo2 gin graph kruskal lca lcm matrix ncm next_combination ppuf segtree st tmp topcoder uf vi 




signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int2(n, m);
    Graph g(n);
    Graph yui(n);
    vi cnt(n, 0);
    rep(i, m+n-1) {
        int2(a, b);
        a--; b--;
        addArc(g, b, a);
        addArc(yui, a, b);
        cnt[b]++;
    }

    int node = 0;
    rep(i, n) {
        if (!cnt[i]) {
            node = i;
            break;
        }
    }

    //cout << node << endl;

    vi rank(n, -1);
    //vi rank = tps(g);
    //bfs(g, rank, node);
    //MomoneMomo(g, rank, node);
    rep(i, n) {
        MomoneMomo(g, rank, i);
    }


    /*
    rep(i, rank.size()) {
        cout << rank[i] << " ";
    }
    cout << endl;
    //*/

    vi ans(n, -1);
    rep(i, n) {
        rep(j, yui[i].size()) {
            if (rank[yui[i][j].d] == rank[i]+1) {
                //cout << "set :" << i << " " << g[i][j].d << endl;
                ans[yui[i][j].d] = i;
            }
        }
    }

    rep(i, n) {
        cout << ans[i] + 1 << endl;
    }


    return 0;
}

