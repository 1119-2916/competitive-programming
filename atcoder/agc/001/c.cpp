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
// cmd

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

void dfs(Graph &g, vi &depth, int pos, int dep)
{
    depth[pos] = dep;
    for (auto i : g[pos]) {
        if (depth[i.d] == -1) {
            dfs(g, depth, i.d, dep+1);
        }
    }
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int2(n, k);
    Graph g(n);
    for (int i = 0; i < n-1; i++) {
        int2(x, y);
        x--; y--;
        addEdge(g, x, y);
    }

    int ans = INF;
    if (k % 2) {
        for (auto i : g) {
            for (auto j : i) {
                vi depth(n, -1);
                depth[j.s] = 0; depth[j.d] = 0;
                dfs(g, depth, j.s, 0); dfs(g, depth, j.d, 0);
                int cnt = 0;
                rep(l, depth.size()) {
                    cnt += (depth[l] > k/2) ? 1 : 0;
                }
                ans = min(cnt, ans);
            }
        }
    } else {
        rep(i, n) {
            //cout << "call : " << i << endl;
            vi depth(n, -1);
            dfs(g, depth, i, 0);
            int cnt = 0;
            //rep(j, depth.size()) cout << depth[j] << " ";cout << endl;
            rep(j, depth.size()) {
                cnt += (depth[j] > k/2) ? 1 : 0;
            }
            ans = min(cnt, ans);
            //cout << cnt << endl;
        }
    }
    cout << ans << endl;

    return 0;
}



