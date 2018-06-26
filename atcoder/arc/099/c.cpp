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

int cnt[3];
bool failed;

void dfs(Graph &yui, vi &table, int pos)
{
    for (auto e : yui[pos]) {
        if (!table[e.d]) {
            table[e.d] = -table[pos];
            cnt[table[e.d] + 1]++;
            dfs(yui, table, e.d);
        } else if (table[e.d] == table[pos]) {
            failed = true;
            break;
        }
    }
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int2(n, m);
    vvb kyoko(n, vb(n, false));
    failed = false;

    rep(i, m) {
        int2(s, t);
        s--; t--;
        kyoko[s][t] = kyoko[t][s] = true;
    }

    Graph yui(n);
    rep(i, n) for (int j = i + 1; j < n; j++) if (!kyoko[i][j]) addEdge(yui, i, j);

    vi table(n, 0);
    vector<i_i> funami;
    rep(i, n) {
        if (!table[i]) {
            cnt[2] = 1; cnt[0] = 0; table[i] = 1;
            dfs(yui, table, i);
            if (failed) {
                cout << -1 << endl;
                return 0;
            }
            funami.pb({cnt[0], cnt[2]});
        }
    }

//    cout << endl;
//    for (auto i : funami) cout << i.fir << " " << i.sec << endl;
//    cout << endl;

    vb dp(n+1, false);
    dp[0] = true;
    for (auto i : funami) {
        vb _dp(n+1, false);
        rep(j, n+1) if (dp[j]) {
            if (j + i.fir <= n) _dp[i.fir + j] = true;
            if (j + i.sec <= n) _dp[i.sec + j] = true;
        }
        dp = _dp;
    }

    int ret = 0;
    for (int i = n / 2; i >= 0; i++) {
        if (dp[i]) {
            ret = i;
            break;
        }
    }

    cout << (ret * (ret - 1) / 2) + ((n-ret) * ((n-ret) - 1) / 2) << endl;

    return 0;
}
