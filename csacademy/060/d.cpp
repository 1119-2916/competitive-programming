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

//トポロジカルソート O(|E|+|V|)
//入次数が0の点と辺を取り除きながらretに突っ込む
vector<int> topologicalSort(const Graph &g, vb &used) {
	int n = g.size(), k = 0;
	vector<int> ord(n), indeg(n); //入次数
	for (auto &es : g) for (auto &e : es) indeg[e.d]++;
	queue<int> q;
	for (int i = 0; i < n; i++) if (indeg[i] == 0 && !used[i]) q.push(i);
    if (!q.size()) return vector<int>();
    for (int i = 0; i < n; i++) if (indeg[i] == 0 && used[i]) q.push(i);
	while (!q.empty()) {
		int v = q.front(); q.pop(); ord[k++] = v;
		for (auto &e : g[v]) if (--indeg[e.d] == 0) q.push(e.d);
    }
	return *max_element(indeg.begin(), indeg.end()) == 0 ? ord : vector<int>();
}

bool dfs(Graph &g, vb &used, int pos)
{
    if (used[pos]) return true;
    else used[pos] = true;
    bool ret = false;
    for (auto i : g[pos]) {
        ret |= dfs(g, used, i.d);
    }
    return ret;
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int3(n, m, k);
    vvi data(n, vi(k));
    rep(i, n) {
        rep(j, k) {
            cin >> data[i][j];
        }
    }

    Graph g(m);
    Rep(i, n) {
        int ptr = 0;
        while (ptr < data[i].size() && data[i-1][ptr] == data[i][ptr]) {
            ptr++;
        }
        if (ptr == data[i].size()) {
            cout << -1 << endl;
            return 0;
        }
        addArc(g, data[i-1][ptr], data[i][ptr]);
    }

    vb used(m, false);
    rep(i, m) {
        if (used[i]) {
            bool ret = dfs(g, used, i);
            if (ret) {
                cout << -1 << endl;
                return 0;
            }
        }
    }

    used = vb(m, false);
    rep(i, n) {
        used[data[i][0]] = true;
    }

    vi ans = topologicalSort(g, used);

    if (ans.size() == 0 || used[ans[0]]) {
        cout << -1 << endl;
        return 0;
    }

    vi output(m);
    rep(i, ans.size()) {
        output[ans[i]] = i;
    }

    rep(i, ans.size()) {
        cout << output[i] << " ";
    }
    cout << endl;

    return 0;
}



