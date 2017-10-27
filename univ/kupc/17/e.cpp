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
// assign avl ncm dijkstra geo2 kruskal graph uf lca BIT
// matrix dinic next_combination topcoder lcm

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

int n, m;
Graph graph;
vector<bool> yui, kyoko; // m , n ( keyko )
vi hoge;

void dfs(int pos)
{
    stack<int> st;
    st.push(pos);
    kyoko[pos] = true;
    while (st.size()) {
        //cout << "call  : " <<  pos << endl;
        pos = st.top(); st.pop();
        /*
        if (pos < n) {
            if (kyoko[pos]) continue;
            else kyoko[pos] = true;
        } else {
            if (yui[pos-n]) continue;
            else yui[pos-n] = true;
        }
        */
        hoge.pb(pos);
        for (int i = 0; i < graph[pos].size(); i++) {
            int nxt = graph[pos][i].d;
            if (nxt < n) {
                if (!kyoko[nxt]) {
                    st.push(nxt);
                    kyoko[nxt] = true;
                }
            } else {
                if (!yui[nxt-n]) {
                    st.push(nxt);
                    yui[nxt-n] = true;
                }
            }
        }
    }
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    cin >> m >> n;
    vector<int> value(m);
    for (int i = 0; i < m; i++) {
        cin >> value[i];
    }
    graph = Graph(n+m);
    rep(i, n) {
        int2(a, b);
        a--; b--;
        //if (a != b) {
            addEdge(graph, i, a+n);
            addEdge(graph, i, b+n);
            /*
        } else {
            addEdge(graph, i, a+n);
        }
        */
    }
    kyoko = vector<bool>(n, false);
    yui = vector<bool>(m, false);

    int ans = 0;
    rep(i, n) {
        if (!kyoko[i]) {
            //cout << i << endl;
            hoge = vi();
            dfs(i);
            //rep(j, hoge.size()) cout << hoge[j] << " "; cout << endl;
            int funami = 0, toshino = 0;
            rep(j, hoge.size()) {
                if (hoge[j] >= n) {
                    funami++;
                } else {
                    toshino++;
                }
            }
            //cout << funami << " " << toshino << endl;
            if (funami > toshino) {
                vi tmp;
                rep(j, hoge.size()) {
                    if (n <= hoge[j]) {
                        tmp.pb(value[hoge[j]-n]);
                    }
                }
                sort(all(tmp));
                Rep(j, tmp.size()) {
                    ans += tmp[j];
                }
            } else {
                rep(j, hoge.size()) {
                    if (n <= hoge[j]) {
                        ans += value[hoge[j]-n];
                    }
                }
            }
        }
    }
    cout << ans << endl;

    return 0;
}

