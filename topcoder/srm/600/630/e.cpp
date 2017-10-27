#include <bits/stdc++.h>

using namespace std;

#define INF 1010001000
#define MOD 1000000007
#define ll long long
#define rep(i, N) for (int i = 0; i < N; i++)
#define Rep(i, N) for (int i = 1; i < N; i++)
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
#define Int(x) int x; scanf("%d", &x);
#define int2(x, y) int x, y; scanf("%d %d", &x, &y);
#define int3(x, y, z) int2(x, y) Int(z)
#define fir first
#define sec second
#define ffir fir.fir
#define fsec fir.sec
#define sfir sec.fir
#define ssec sec.sec
#define BEGIN_STACK_EXTEND(size) void * stack_extend_memory_ = malloc(size);void * stack_extend_origin_memory_;char * stack_extend_dummy_memory_ = (char*)alloca((1+(int)(((long long)stack_extend_memory_)&127))*16);*stack_extend_dummy_memory_ = 0;asm volatile("mov %%rsp, %%rbx\nmov %%rax, %%rsp":"=b"(stack_extend_origin_memory_):"a"((char*)stack_extend_memory_+(size)-1024));

#define END_STACK_EXTEND asm volatile("mov %%rax, %%rsp"::"a"(stack_extend_origin_memory_));free(stack_extend_memory_);

//int dxy[5] = {0, 1, 0, -1, 0};
// assign avl ncm dijkstra geo2 kruskal graph uf lca BIT
// matrix dinic next_combination topcoder lcm
// stack size = 128 * 1024 * 1024

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

//lowest common ancestor (ダブリング + dfs再帰)
//構築O(NlogN) クエリO(logN)
struct LowestCommonAncestor {
    const int n, log2_n;
    vector< vector <int> > parent;
    vector<int> depth;
    const Graph &g;
    LowestCommonAncestor(const Graph &g, int root)
        :g(g), n(g.size()), log2_n(log2(n) + 1), parent(log2_n, vector<int>(n)), depth(n) {
            dfs(root, -1, 0);
            for (int k = 0; k + 1 < log2_n; k++) {
                for (int v = 0; v < n; v++) {
                    if (parent[k][v] < 0)
                        parent[k + 1][v] = -1;
                    else
                        parent[k + 1][v] = parent[k][parent[k][v]];
                }
            }
        }
    void dfs(int s, int p, int d) {
        parent[0][s] = p;
        depth[s] = d;
        for (int i = 0; i < g[s].size(); i++) {
            Edge e = g[s][i];
            if (e.d == p)continue;
            dfs(e.d, s, d + 1);
        }
    }
    int get(int u, int v) {
        if (depth[u] > depth[v]) swap(u, v);
        for (int k = 0; k < log2_n; k++) {
            if ((depth[v] - depth[u]) >> k & 1) {
                v = parent[k][v];
            }
        }
        if (u == v) return u;
        for (int k = log2_n - 1; k >= 0; k--) {
            if (parent[k][u] != parent[k][v]) {
                u = parent[k][u];
                v = parent[k][v];
            }
        }
        return parent[0][u];
    }
    int dist(int u, int v) {
        int w = get(u, v);
        return depth[u] + depth[v] - depth[w] * 2;
    }
};


class Egalitarianism3
{ 
    public:
        int maxCities(int n, vi a, vi b, vi len)
        {
            if (n <= 1) return 1;
            Graph g(n);
            rep(i, a.size()) {
                addEdge(g, a[i]-1, b[i]-1, len[i]);
            }
            LowestCommonAncestor *lca[n];
            rep(i, n) {
                lca[i] = new LowestCommonAncestor(g, i);
            }

            int ret = 2;
            rep(i, n) {
                vi ans(n);
                //std::cout << "solve : " << i << " " << endl;
                rep(j, n) {
                    ans[j] = lca[i]->dist(i, j);
                    //std::cout << ans[j] << " " ;
                }
                //cout << endl;
                sort(all(ans));
                int cnt = 0, num = 0;
                rep(i, n) {
                    if (ans[i] == num) {
                        cnt++;
                    } else {
                        ret = max(cnt, ret);
                        cnt = 1;
                        num = ans[i];
                    }
                }
                ret = max(cnt, ret);
            }
            return ret;
        }

};



int main()
{
    Egalitarianism3 solve;
    Int(n);
    vi a(n-1), b(n-1), len(n-1);
    rep(i, n-1) cin >> a[i];
    rep(i, n-1) cin >> b[i];
    rep(i, n-1) cin >> len[i];
    std::cout << solve.maxCities(n, a, b, len) << std::endl;

    return 0;
}
