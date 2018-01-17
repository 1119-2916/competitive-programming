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

void dfs(Graph &g, vi &score, int pos, int dep)
{
    score[pos] = dep;
    for (auto i : g[pos]) {
        if (score[i.d] == -1) {
            dfs(g, score, i.d, dep+1);
        }
    }
}

bool get_path(Graph &g, vi &score, vi &ans, int pos, int en)
{
    score[pos] = 0;
    for (auto i : g[pos]) {
        if (i.d == en) {
            ans.pb(i.d);
            return true;
        }
        if (score[i.d] == -1) {
            if (get_path(g, score, ans, i.d, en)) {
                ans.pb(i.d);
                return true;
            }
        }
    }
    return false;
}

void solve(Graph &g, vi &path, vi &ans, int pos, int ptr, int bef)
{
    ans.pb(pos);
    if (pos == path.back()) return;
    for (auto i : g[pos]) {
        if (i.d != bef && i.d != path[ptr+1]) {
            solve(g, path, ans, i.d, ptr, pos);
            ans.pb(pos);
        }
    }
    if (path[ptr] == pos) {
        solve(g, path, ans, path[ptr+1], ptr+1, path[ptr]);
    }
}


signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    Int(n);
    Graph g(n);
    for (int i = 1; i < n; i++) {
        int2(a, b); a--; b--;
        addEdge(g, a, b);
    }

    vi score(n, -1);
    dfs(g, score, 0, 0);
    int st = 0;
    rep(i, n) {
        if (score[st] < score[i]) st = i;
    }
    score.assign(n, -1);
    dfs(g, score, st, 0);
    int en = 0;
    rep(i, n) {
        if (score[en] < score[i]) en = i;
    }

    //cout << st << " " << en << endl;

    score.assign(n, -1);
    vi ans(0);
    get_path(g, score, ans, st, en);
    ans.pb(st);
    reverse(all(ans));
    //rep(i, ans.size()) cout << ans[i] << " "; cout << endl;

    vi funami(0);
    solve(g, ans, funami, st, 0, -1);
    cout << funami.size()-1 << endl;
    rep(i, funami.size())cout << funami[i]+1 << " ";cout << endl;


    return 0;
}



