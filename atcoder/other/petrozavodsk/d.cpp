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

void dfs(Graph &g, int p, vi &yui, vi &used)
{
    for (auto i : g[p]) {
        if (!used[i.d]) {
            used[i.d] = 1;
            yui.pb(i.d);
            dfs(g, i.d, yui, used);
        }
    }
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int2(n, m);
    Graph g(n);

    vector<int> cost(n);
    for (int i = 0; i < n; i++) {
        cin >> cost[i];
    }
    
    rep(i, m) {
        int2(a, b);
        addEdge(g, a, b);
    }

    vvi funami;
    vi used(n, 0);
    rep(i, n) {
        vi yui;
        if (!used[i]) {
            used[i] = 1; yui.pb(i);
            dfs(g, i, yui, used);
        }
        if (yui.size()) funami.pb(yui);
    }

    if (funami.size() == 1) {
        std::cout << 0 << std::endl;
        return 0;
    }

    /*
    for (auto i : funami) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
    */

    int kyoko = (funami.size() - 1) * 2;

    if (kyoko > n) {
        std::cout << "Impossible" << std::endl;
        return 0;
    }

    rep(i, funami.size()) {
        rep(j, funami[i].size()) {
            funami[i][j] = cost[funami[i][j]];
        }
        sort(all(funami[i]));
    }

    int ans = 0;
    vi toshino;
    rep(i, funami.size()) {
        ans += funami[i][0];
        Rep(j, funami[i].size()) {
            toshino.pb(funami[i][j]);
        }
    }

    sort(all(toshino));
    rep(i, kyoko - funami.size()) {
        ans += toshino[i];
    }

    cout << ans << endl;

    return 0;
}
