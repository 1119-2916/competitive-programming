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


signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int2(n, m);
    vi data(n), dic(n+1);
    vb used(n+1, false);
    rep(i, n) {
        cin >> data[i];
        dic[data[i]] = i;
    }
    Graph g(n+1);
    rep(i, m) {
        int2(a, b);
        addEdge(g, a, b);
    }

    vi table(n+1, 0);
    table[0] = 1;
    int len = 0;
    used[1] = true;
    Rep(i, n) {
        /*
        rep(j, len+1) 
            std::cout << table[j] << " ";
        cout << endl;
        */
        bool ok = false;
        for (Edge e : g[table[len]]) {
            if (e.d == data[i]) {
                len++;
                table[len] = data[i];
                used[data[i]] = true;
                ok = true;
                break;
            }
        }
        if (ok) {
            continue;
        }
        for (int j = len; j > 0; j--) {
            for (Edge e : g[table[len]]) {
                if (!used[e.d]) {
                    std::cout << 0 << std::endl;
                    return 0;
                }
            }
            len--;
            for (Edge e : g[table[len]]) {
                if (e.d == data[i]) {
                    len++;
                    table[len] = data[i];
                    used[data[i]] = true;
                    ok = true;
                    break;
                }
            }
            if (ok) {
                break;
            }
        }
        if (ok) {
            continue;
        } else {
            std::cout << 0 << std::endl;
            return 0;
        }
    }
    std::cout << 1 << std::endl;

    return 0;
}








