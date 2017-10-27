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
#define Int(x) int x; scanf("%lld", &x);
#define int2(x, y) int x, y; scanf("%lld %lld", &x, &y);
#define int3(x, y, z) Int(x); int2(y, z);
#define fir first
#define sec second
#define ffir first.first
#define fsec first.second
#define sfir second.first
#define ssec second.second

//int dxy[5] = {0, 1, 0, -1, 0};
// assign avl ncm dijkstra geo2 kruskal graph uf lca BIT
// matrix dinic next_combination

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

bool next_combination(std::vector<int>& v, int n) {
    int k = v.size();
    int p = k - 1;
    if (v[p] >= n) return false;
    while (p >= 0 && ++v[p] >= n - (k - p - 1)) --p;
    if (p < 0) return false;
    ++p;
    while (p < k) {
        v[p] = v[p - 1] + 1;
        ++p;
    }
    return true;
}

signed main()
{
    int2(n, m);
    int3(p, q, r);

    Edges graph;
    rep(i, r) {
        int3(a, b, c);
        graph.pb(Edge(a-1, b-1, c));
    }
    sort(all(graph));
    /*
    cout << "====" << endl;
    rep(i, graph.size()) {
        std::cout << graph[i] << std::endl;
    }
    cout << "====" << endl;
    */

    vi node(p);
    int ans = 0;
    //rep(i, p) node[i] = i;
    do {
        //rep(i, p) std::cout << node[i] << " "; cout << endl;
        
        vb used(n, false);
        rep(i, node.size()) used[node[i]] = true;
        vi cnt(m, 0);
        rep(i, graph.size()) {
            if (used[graph[i].s]) {
                cnt[graph[i].d] += graph[i].w;
            }
        }
        sort(all(cnt));
        reverse(all(cnt));
        int sum = 0;
        rep(i, q) {
            sum += cnt[i];
        }
        ans = max(ans, sum);
    } while (next_combination(node, n));

    std::cout << ans << std::endl;

    return 0;
}



