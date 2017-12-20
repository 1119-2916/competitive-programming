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
// // assign avl ncm dijkstra geo2 kruskal graph uf lca BIT
// matrix dinic next_combination topcoder lcm vi st gin

template<class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return true; } return false; }

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

Edges bridges(const Graph &g, int root = 0) {
	/*
	e(u, v) が橋でない <=> ord[u] >= low[v]
	e(u, v) が橋 <=> ord[u] < low[v]
	*/
	int n = g.size();
	vector<bool> vis(n);
	vector<int> ord(n);
	vector<int> low(n);
	Edges bri;
	int o = 0;
	function<void(int, int)> dfs = [&](int u, int p) {
		if (vis[u])return;
		vis[u] = true;
		ord[u] = o++;
		low[u] = ord[u];
		bool is_art = false;
		for (auto &e : g[u]) {
			if (!vis[e.d]) {
				dfs(e.d, u);
				chmin(low[u], low[e.d]);
				if (ord[u] < low[e.d])bri.emplace_back(u, e.d);
			}
			else if (e.d != p) {
				chmin(low[u], ord[e.d]);
			}
		}
	};
	dfs(root, -1);
	return bri;
}

bool solve(Graph &g, int st, int en, Edges &bri, vb &used, vi &path)
{
    used[st] = true;
    for (auto i : g[st]) {
        if (i.d == en) {
            path.pb(i.d);
            path.pb(i.s);
            return true;
        }
        if (!used[i.d]) {
            if (solve(g, i.d, en, bri, used, path)) {
                path.pb(i.s);
                return true;
            }
        }
    }
    return false;
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int3(n, m, q);
    Graph g(n);
    for (int i = 0; i < m; i++) {
        int2(x, y);
        x--; y--;
        addEdge(g, x, y);
        //addArc(g, x, y);
    }

    Edges yui = bridges(g);
    vvb is_path(n, vb(n, false));
    rep(i, yui.size()) {
        is_path[yui[i].s][yui[i].d] = true;
        is_path[yui[i].d][yui[i].s] = true;
    }
    /*
    rep(i, yui.size()) {
        cout << yui[i] << endl;
    }*/

    rep(i, q) {
        int2(x, y);
        x--; y--;
        vb used(n, false);
        vi path(0);
        solve(g, x, y, yui, used, path);
        bool ok = true;
        //rep(j, path.size())cout << path[j] << " ";cout << endl;
        Rep(j, path.size()) {
            ok &= is_path[path[j]][path[j-1]];
        }
        if (ok) {
            cout << 1 << endl;
        } else {
            cout << 0 << endl;
        }
    }


    return 0;
}
