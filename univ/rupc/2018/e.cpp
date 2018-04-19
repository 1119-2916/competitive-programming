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
// // assign avl ncm dijkstra geo2 kruskal graph uf lca BIT
// matrix dinic next_combination topcoder lcm vi st gin
// cusum segtree

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

void dfs(Graph &g, int pos, int &k, vp &seg)
{
    seg[pos].fir = k++;
    for (auto i : g[pos]) {
        dfs(g, i.d, k, seg);
    }
    seg[pos].sec = k;
}

int r_size = 350;
int data[100001];
int flag[1000];
int cnt[1000][2];

void updata(int st, int en)
{
    for (int i = st; i < en;) {
        if (i % r_size || i + r_size >= en) {
            cnt[i / r_size][data[i]]--;
            data[i] = 1 - data[i];
            cnt[i / r_size][data[i]]++;
            i++;
        } else {
            flag[i / r_size] = 1 - flag[i / r_size];
            i += r_size;
        }
    }
}

int get(int n)
{
    int ret = 0;
    for (int i = 0; i < n; ) {
        ret += cnt[i / r_size][flag[i / r_size]];
        i += r_size;
    }
    return (ret < n - ret);
}


signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int2(n, q);
    Graph g(n);
    for (int i = 0; i < n-1; i++) {
        Int(tmp);
        addArc(g, tmp-1, i+1);
    }

    vi l(n);
    for (int i = 0; i < n; i++) {
        char yui; cin >> yui;
        l[i] = (yui == 'G'); // G = 0, W = 1;
    }

    int tmp = 0;
    vp seg(n);
    dfs(g, 0, tmp, seg);

    rep(i, n) {
        data[seg[i].fir] = l[i];
        cnt[seg[i].fir/r_size][data[seg[i].fir]]++;
    }

    string ans[2] = {"cauliflower", "broccoli"};
    rep(i, q) {
        Int(yui);
        yui--;
        int st = seg[yui].fir, en = seg[yui].sec;

        updata(st, en);

        cout << ans[get(n)] << endl;
    }

    return 0;
}
