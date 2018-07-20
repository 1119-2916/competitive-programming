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
// BIT DiscreteFourierTransform FFT avl cmd cusum dijkstra dinic geo2 gin graph kruskal lca lcm matrix ncm next_combination segtree st tmp topcoder uf vi 

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

int n, d, k, cnt;

void dfs(Graph &g, int pos, int par, int h)
{
    //cout << "call : " << pos << " " << par << " " << h << endl;
    if (cnt == n || !h) return;
    //cout << "do" << endl;

    for (int i = g[pos].size(); i < k; i++) {
        if (cnt < n) {
            //cout << pos << " " << cnt << " ";
            addEdge(g, pos, cnt++);
        }
    }

    for (auto i : g[pos]) {
        if (cnt < n && i.d != par) dfs(g, i.d, pos, h-1);
    }
}


signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    cin >> n >> d >> k;
    Graph g(n);

    cnt = 0;
    for (cnt = 0; cnt < d; cnt++) {
        if (cnt+1 == n) {
            cout << "NO" << endl;
            return 0;
        }
        addEdge(g, cnt, cnt+1);
    } cnt++;

    if (d >= 2 && k == 1) {
        cout << "NO" << endl;
        return 0;
    }

    int st = d / 2; //cout << st << endl;
    if (d % 2) {
        //cout << st << " " << st+1 << endl;
        dfs(g, st, st+1, d/2);
        //cout << st+1 << " " << st << endl;
        dfs(g, st+1, st, d/2);
    } else {
        dfs(g, st, -1, d/2);
    }

    if (cnt < n) cout << "NO" << endl;
    else {
        cout << "YES" << endl;
        rep(i, n) {
            for (auto j : g[i]) {
                if (j.d > i) {
                    cout << i+1 << " " << j.d+1 << endl;
                }
            }
        }
    }
    
    return 0;
}


