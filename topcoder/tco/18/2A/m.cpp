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

class MakingRegularGraph
{ 
    public:
        bool dfs(vector<bool> &used, Graph &g, int pos, int bef) {
            bool ret = true;
            for (Edge e : g[pos]) {
                if (e.d != bef && used[e.d]) {
                    return false;
                } else if (e.d != bef && !used[e.d]) {
                    used[e.d] = true;
                    ret &= dfs(used, g, e.d, pos);
                }
            }
            return ret;
        }

        vector <int> addEdges(int n, vector <int> x, vector <int> y)
        {
            Graph g(n);
            rep(i, x.size()) {
                addEdge(g, x[i], y[i]);
            }
            vector<bool> kyoko(n, false);
            rep(i, n) {
                if (!kyoko[i] && !dfs(kyoko, g, i, -1)) {
                    vi ret(1, -1);
                    return ret;
                }
            }

            priority_queue<int> zero, ichi;
            rep(i, n) {
                if (!g[i].size()) {
                    zero.push(-i);
                } else if (g[i].size() == 1) {
                    ichi.push(-i);
                }
            }

            vi ret(0);
            UnionFind uf(n);
            rep(i, x.size()) uf.unite(x[i], y[i]);
            vi yui(n, 0);
            rep(i, n) yui[i] = g[i].size();

            rep(i, n) {
                //cout << i << endl;
                while (yui[i] < 2) {
                    for (int j = i+1; j < n; j++) {
                        if (yui[j] < 2 && !uf.same(i, j)) {
                            uf.unite(i, j);
                            ret.pb(i); ret.pb(j);
                            yui[i]++;
                            yui[j]++;
                            break;
                        } else if (yui[j] < 2 && uf.sizeOf(i) == n) {
                            uf.unite(i, j);
                            ret.pb(i); ret.pb(j);
                            yui[i]++;
                            yui[j]++;
                            break;
                        }
                    }
                }
                //rep(j, ret.size()) cout << ret[j] << " "; cout << endl;
                //rep(j, n) cout << yui[j] << " "; cout << endl;
            }

            return ret;
            
        }

};



int main()
{
    MakingRegularGraph solve;
    int2(n, m);
    vector<int> a(m);
    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }
    vector<int> b(m);
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    
    vi ret = solve.addEdges(n, a, b);
    rep(i, ret.size()) cout << ret[i] << " "; cout << endl;

    return 0;
}
