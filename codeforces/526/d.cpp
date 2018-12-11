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

int data[301000];

int solve(Graph &g, vi &used, int pos, int *ans)
{
    //cout << "call : " << pos << endl;
    int ret1 = 0, ret2 = 0;
    used[pos] = 1;
    for (auto i : g[pos]) {
        if (!used[i.d]) {
            int tmp = solve(g, used, i.d, ans) - i.w;
            if (ret1 < tmp) {
                ret2 = ret1;
                ret1 = tmp;
            } else if (ret2 < tmp) {
                ret2 = tmp;
            }
        }
    }
    *ans = max(*ans, data[pos]);
    *ans = max(*ans, ret1 + ret2 + data[pos]);
    //cout << "ret : " << pos << " " << ret1 << " " << ret2 << endl;
    return ret1 + data[pos];
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    Int(n);
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }

    Graph g(n);
    rep(i, n-1) {
        int3(a, b, c);
        a--; b--;
        addEdge(g, a, b, c);
    }

    int ans = 0;
    vi used(n, 0);
    int tmp = solve(g, used, 0, &ans); 

    cout << max(ans, tmp) << endl;

    return 0;
}
