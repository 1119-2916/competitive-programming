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
#define eb emplece_back
#define mp make_pair
#define i_i pair<int, int>
#define vi vector<int>
#define vvi vector<vi >
#define vb vector<bool>
#define vvb vector<vb >
#define vp vector< i_i >
#define vvp vector< vp >
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

//int dxy[5] = {0, 1, 0, -1, 0};
// // assign avl ncm dijkstra geo2 kruskal graph uf lca BIT
// matrix dinic next_combination topcoder lcm vi st gin

typedef int Weight;
typedef int Flow;
struct Edge {
    int s, d; Weight w; Flow c;
    Edge() {};
    Edge(int s, int d, Weight w = 1) : s(s), d(d), w(w), c(w) {};
};
bool operator<(const Edge &e1, const Edge &e2) { return e1.w < e2.w; }
bool operator>(const Edge &e1, const Edge &e2) { return e2 < e1; }
inline ostream &operator<<(ostream &os, const Edge &e) { return (os << '(' << e.s << ", " << e.d << ", " << e.w << ')'); }

typedef vector<Edge> Edges;
typedef vector<Edges> Graph;
typedef vector<Weight> Array;
typedef vector<Array> Matrix;

void addArc(Graph &g, int s, int d, int w = 1) {
    g[s].push_back(Edge(s, d, w));
}
void addEdge(Graph &g, int a, int b, int w = 1) {
    addArc(g, a, b, w);
    addArc(g, b, a, w);
}

vector<int> kosaraju(const Graph &g) {
	int n = g.size();
	Graph rg = reverse(all(g));
	vector<int> cc(n, -1);
	vector<int> post;
	function<void(int, int)> dfs_cc = [&](int u, int cc_id) {
		if (cc[u] != -1)return;
		cc[u] = cc_id;
		for (auto &e : g[u])
			dfs_cc(e.d, cc_id);
		post.emplace_back(u);
	};
	int count_cc = 0;
	for (int u = 0; u < n; u++)
		if (cc[u] == -1)
			dfs_cc(u, count_cc++);
	vector<int> scc(n, -1);
	function<void(int, int, int)> dfs_scc = [&](int u, int scc_id, int cc_id) {
		if (scc[u] != -1)return;
		if (cc[u] != cc_id)return;
		scc[u] = scc_id;
		for (auto &e : rg[u])
			dfs_scc(e.d, scc_id, cc_id);
	};
	int count_scc = 0;
	reverse(post.begin(), post.end());
	for (auto &u : post)
		if (scc[u] == -1)
			dfs_scc(u, count_scc++, cc[u]);
	return scc;
}

Graph exg;
vvp gl;
Edges olphe;
hash<string> mhs;
map< int, int > yui;
vb used;
int n, m, ratea;

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    cin >> n >> m;
    gl = vvp(n, vp(n, i_i(INF, -1)));
    exg = Graph(m);
    olphe = Edges(m);
    rep(i, m) {
        int3(a, b, c);
        olphe[i] = Edge(a-1, b-1, c);
        gl[a-1][b-1] = i_i(c, i);
    }

    //cout << "=====" << endl;

    rep(i, m) {
        rep(j, n) {
            int st = olphe[i].s;
            if (j != st && gl[j][st].fir != INF) {
                addArc(exg, gl[j][st].sec, i);
            }
        }
    }

    vi ret = kosaraju(exg);
    
    /*
    rep(i, m) {
        rep(j, m) {
            cout << exg[i][j].sec << " ";
        }
        cout << endl;
    }
    
    rep(i, m) {
        ret = vi();
        vi path;
        used = vb(m, false);
        ratea = i;
        solve(i, 0, path);
        //cout << "=====" << i << "====" << endl;
        
        rep(i, ret.size()) {
            cout << ret[i] << " ";
        }
        cout << endl;
        if (ret.size()) {
            bool ok = true;
            int tmp = ret[0];
            rep(i, ret.size()) {
                if (tmp != ret[i]) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                cout << "Yes" << endl;
                return 0;
            }
        }
        //
    }

    //cout << yui.size() << endl;

    int kyoko = INF-2;
    for (auto it = yui.begin(); it != yui.end(); it++) {
        if (kyoko == INF-2) {
            kyoko = it->second;
        } else if (kyoko != it->second) {
            cout << "No" << endl;
            return 0;
        }
    }
    */

    cout << "Yes" << endl;

    return 0;
}


