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

    vi depth(n, -1);
    dfs(g, depth, 0, 0);
    int pos = 0;
    rep(i, depth.size()) {
        if (depth[pos] < depth[i]) {
            pos = i;
        }
    }
    cout << pos << endl;
    depth = vi(n, -1);
    dfs(g, depth, pos, 0);
    vi cnt(*max_element(all(depth))+1, 0);
    rep(i, depth.size()) {
        cnt[depth[i]]++;
    }
    ///*
    rep(i, cnt.size()) {
        cout << cnt[i] << " ";
    }cout << endl;
    //*/
    int sum = 0, st = 0;
    while (cnt.size() - st > k + 1) {
        if (cnt[st+1] != 1) break;
        st++; sum++;
    }
    cout << st << " " << sum << endl;
    for (int i = cnt.size()-1; i - st > k+1; i--) {
        sum += cnt[i];
        cout << sum << endl;
    }

    cout << sum << endl;

    return 0;
}



