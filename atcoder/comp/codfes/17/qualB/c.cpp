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

bool dfs(Graph &g, vi &state, vi &used, int pos, int num)
{
    //cout << pos << " " << num << endl;
    used[pos] = true;
    state[pos] = num;
    bool ret = true;
    rep(i, g[pos].size()) {
        if (!used[g[pos][i].d]) {
            ret &= dfs(g, state, used, g[pos][i].d, -num);
        } else if (state[g[pos][i].d] == num) {
            //    cout << "finish in : " << i << endl;
            return false;
        }
    }
    return ret;
}

bool is_binary_graph(Graph &g, vi &state)
{
    int n = g.size();
    state = vi(n, 0);
    vi used(n, false);
    /*
    rep(i, n) {
        if (!used[i]) {
            if (!dfs(g, state, used, i, 1LL)) {
                cout << "finish in : " << i << endl;
                return false;
            }
        }
    }*/
    return dfs(g, state, used, 0, 1);
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int2(n, m);
    Graph g(n);
    for (int i = 0; i < m; i++) {
        int tmpx, tmpy;
        cin >> tmpx >> tmpy;
         tmpx--; tmpy--;
        addEdge(g, tmpx, tmpy );
    }

    vi state;

    if (is_binary_graph(g, state)) {
        int yui = 0;
        rep(i, n) {
            yui += (state[i] == 1) ? 1 : 0;
        }
        cout << (yui * (n - yui)) - m << endl;
    } else {
        cout << n * (n-1) / 2 - m << endl;
    }

    return 0;
}
