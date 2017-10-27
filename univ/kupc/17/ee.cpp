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

struct UnionFind {
    vector<int> parent;
    int size;
    UnionFind(int n) :parent(n, -1), size(n) {}
    bool unite(int x, int y) {
        x = root(x); y = root(y);
        if (x == y)return false;
        if (sizeOf(x) < sizeOf(y))swap(x, y);
        parent[x] += parent[y]; parent[y] = x; size--;
        return true;
    }
    bool same(int x, int y) { return root(x) == root(y); }
    int root(int x) { return parent[x] < 0 ? x : parent[x] = root(parent[x]); }
    int sizeOf(int x) { return -parent[root(x)]; }
};

int n, m;
Graph graph;
vector<bool> yui, kyoko; // n , m ( keyko )
vi hoge;

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    cin >> n >> m; // value, key
    vector<int> value(n);
    for (int i = 0; i < n; i++) {
        cin >> value[i];
    }
    UnionFind Funami_yui(n + m); // value, key
    rep(i, m) {
        int2(a, b);
        a--; b--;
        Funami_yui.unite(a, i+n);
        Funami_yui.unite(b, i+n);
    }
    vi yui(n), kyoko(m);
    rep(i, n) { yui[i] = Funami_yui.root(i); }
    rep(i, m) { kyoko[i] = Funami_yui.root(i+n); }

    map<int, int> Toshino_kyoko;
    rep(i, m) {
        Toshino_kyoko[kyoko[i]]++;
    }

    int ans = 0;
    for (int i = Toshino_kyoko.begin(); i != Toshino_kyoko.end(); i++) {
        if (i->second < (Funami_yui.sizeOf(i->first) - i->second)) {




    rep(i, n) {
        if (!kyoko[i]) {
            cout << i << endl;
            hoge = vi();
            dfs(i);
            //rep(j, hoge.size()) cout << hoge[j] << " "; cout << endl;
            int funami = 0, toshino = 0;
            rep(j, hoge.size()) {
                if (hoge[j] >= n) {
                    funami++;
                    yui[hoge[j]+n] = true;
                } else {
                    toshino++;
                    kyoko[hoge[j]] = true;
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

