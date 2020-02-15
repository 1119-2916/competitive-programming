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

int table[40][201][201];
int g[201][201];
int yui[201][201];

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int2(n, m);
    int3(w, s, k);

    rep(i, 201) {
        rep(j, 201) {
            g[i][j] = -INF;
        }
    }
    rep(i, 40) {
        rep(j, 201) {
            rep(l, 201) {
                table[i][j][l] = -INF;
            }
        }
    }

    for (int i = 0; i < m; i++) {
        int2(tmpx, tmpy);
        Int(tmpw);
        g[tmpx-1][tmpy-1] = tmpw;
    }

    rep(i, 201) {
        rep(j, 201) {
            table[1][i][j] = g[i][j];
        }
    }

    Rep(step, 40) {
        rep(st, n) {
            rep(mid, n) {
                if (table[step][st][mid] != -INF) {
                    rep(en, n) {
                        if (table[step][mid][en] != -INF) {
                            table[step+1][st][en] = max(
                                    table[step+1][st][en],
                                    table[step][st][mid] + 
                                    table[step][mid][en]);
                        }
                    }
                }
            }
        }
        rep(st, n) {
            rep(en, n) {
                if (table[step+1][st][en] != -INF) {
                    table[step+1][st][en] = max(-w,
                            table[step+1][st][en]);
                }
            }
        }
    }

    vi ans(n, -INF), nxt;
    ans[s-1] = w;
    int rest = k;
    for (int i = 39; i > 0; i--) {
        if (rest >= pow(2, i)) {
            nxt = vector<int>(n, -INF);
            rep(st, n) {
                rep(en, n) {
                    nxt[en] = max(nxt[en],
                            ans[st] + table[i][st][en]);
                }
            }
            rep(i, n) {
                if (nxt[i] != -INF) {
                    ans[i] = max(-w, nxt[i]);
                }
            }
            rest -= pow(2, i);
        }
    }

    int ret = -INF;
    rep(i, ans.size()) ret = max(ans[i], ret);
    if (ret == -INF) {
        std::cout << -1 << std::endl;
    } else {
        std::cout << ret << std::endl;
    }

    return 0;
}




