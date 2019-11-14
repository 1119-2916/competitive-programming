#include <bits/stdc++.h>

using namespace std;

#define INF 1010001000
#define MOD 1000000007
#define rep(i, N) for (int i = 0; i < N; i++) 
#define pb emplace_back
#define vi vector<int>
#define all(x) (x).begin(), (x).end()
#define Int(n) int (n); scanf("%d", &(n));
#define int2(a, b); Int(a); Int(b);

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

void addArc(Graph &g, int s, int d, Weight w = 1) {
    g[s].pb(s, d, w);
}
void addEdge(Graph &g, int a, int b, Weight w = 1) {
    addArc(g, a, b, w);
    addArc(g, b, a, w);
}

struct LCA {
    const int n, log2_n;
    vector<vi> parent;
    vi depth;
    const Graph &g;
    LCA(const Graph &g, int root) 
            :g(g), n(g.size()), log2_n(log2(n) + 1), parent(log2_n, vi(n)), depth(n) {
        dfs(root, -1, 0);
        for (int k = 0; k + 1 < log2_n; k++) {
            rep(v, n) {
                if (parent[k][v] < 0) 
                    parent[k + 1][v] = -1;
                else 
                    parent[k + 1][v] = parent[k][parent[k][v]];
            }
        }
    }
    void dfs(int s, int p, int d) {
        parent[0][s] = p;
        depth[s] = d;
        rep(i, g[s].size()) {
            Edge e = g[s][i];
            if (e.d == p) continue;
            dfs(e.d, s, d + 1);
        }
    }
    int get(int u, int v) {
        if (depth[u] > depth[v]) swap(u, v);
        rep(k, log2_n) {
            if ((depth[v] - depth[u]) >> k & 1) {
                v = parent[k][v];
            }
        }
        if (u == v) return u;
        for (int k = log2_n - 1; k >= 0; k--) {
            if (parent[k][u] != parent[k][v]) {
                u = parent[k][u];
                v = parent[k][v];
            }
        }
        return parent[0][u];
    }
    int get_ch(int u, int v) {  // u->ret->...->v
        if (depth[u] > depth[v]) swap(u, v);
        rep(k, log2_n) {
            if ((depth[v] - depth[u] - 1) >> k & 1) {
                v = parent[k][v];
            }
        }
        return v;
    }
    int dist(int u, int v) {
        int w = get(u, v);
        return depth[u] + depth[v] - depth[w] * 2;
    }
};
                        
int funami(Graph &g, vi &ch, int p, int par)
{
    int tmp = 1;
    for (auto i : g[p]) {
        if (i.d != par) {
            tmp += funami(g, ch, i.d, p);
        }
    }
    return ch[p] = tmp;
}

signed main()
{
    Int(t);
    for (int tt = 1; tt <= t; tt++) {
        printf("Case #%d:\n", tt);
        int2(n, q);
        Int(r); r--;
        Graph g(n);
        rep(i, n-1) {
            int2(a, b); a--; b--;
            addEdge(g, a, b);
        }
        LCA lca(g, 0);
        vi cnt(n, 0);
        funami(g, cnt, 0, -1);
        //rep(i, cnt.size()) cout << cnt[i] << " "; cout << endl;
        while (q--) {
            int2(s, u); u--;
            if (s) {
                int tmp = lca.get(r, u);
                //cout << "tmp : " << tmp << endl;
                if (u == r) {
                    printf("%d\n", n);
                } else if (u == tmp) {
                    //cout << "pos : " << lca.get_ch(u, r) << endl;
                    printf("%d\n", n - cnt[lca.get_ch(u, r)]);
                } else {
                    printf("%d\n", cnt[u]);
                }
            } else {
                r = u;
            }
        }
    }

    return 0;
}

