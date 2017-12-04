#include <bits/stdc++.h>

using namespace std;

#define INF 1001000100010001000
#define MOD 1000000007
#define EPS 1e-10
#define int long long
#define double long double
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

double solve(Graph &g, int pos, int par, double len)
{
  //  cout << "call : " << pos << " " << len << endl;
    if (pos != 0 && g[pos].size() == 1) {
 //       std::cout << " " << pos << " " << len << std::endl;
        return len;
    }
    double mom = g[pos].size()-1;
    if (pos == 0) {
        mom++;
    }
    double sum = 0.0;
    rep(i, g[pos].size()) {
        if (g[pos][i].d != par) {
            sum += solve(g, g[pos][i].d, pos, len+1.0);
        }
    }
//    std::cout << " " << pos << " " << sum / mom << std::endl;
    return sum / mom;
}

signed main()
{
    Int(n);
    Graph g(n);
    rep(i, n-1) {
        int2(a, b);
        addEdge(g, a-1, b-1, 1.0);
    }

    printf("%.10Lf\n", solve(g, 0, -1, 0.0));


    return 0;
}
