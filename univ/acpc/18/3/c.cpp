#include <bits/stdc++.h>

using namespace std;

#define int long long 
#define rep(i, n) for (int i = 0; i < n; i++) 
#define pb emplace_back

using Weight = int;
using Flow = int;
struct Edge {
    int s, d; Weight w; Flow c;
    Edge() {};
    Edge(int s, int d, Weight w = 1) : s(s), d(d), w(w), c(w) {};
};

using Edges = vector<Edge>;
using Graph = vector<Edges>;
using Array = vector<Weight>;

void addArc(Graph &g, int s, int d, Weight w = 1)
{
    g[s].emplace_back(s, d, w);
}
void addEdge(Graph &g, int a, int b, Weight w = 1)
{
    addArc(g, a, b, w);
    addArc(g, b, a, w);
}

int yui;

int dfs(Graph &g, vector<int> &data, vector<int> &visited,int pos,int bef)
{
    visited[pos] = 1;
    for (auto i : g[pos]) {
        if (i.d != bef) {
            if (visited[i.d]) {
                yui = i.d;
                data[i.d] = 1;
                data[pos] = 1;
                return 1;
            } else {
                int status = dfs(g, data, visited, i.d, pos);
                if (status) {
                    if (pos == yui) {
                        status = 2;
                    }
                    if (status == 1) {
                        data[pos] = 1;
                    }
                    return status;
                }
            }
        }
    }
    return 0;
}
    
void FunamiYui(Graph &g, vector<int> &data)
{
    vector<int> visited(g.size(), 0);
    dfs(g, data, visited, 0ll, -1ll);
}

signed main(void)
{
    int n; cin >> n;
    Graph g(n);
    rep(i, n) {
        int a, b; cin >> a >> b;
        a--; b--;
        addEdge(g, a, b);
    }

    vector<int> cycle(n, 0);
    FunamiYui(g, cycle);

    int qu; cin >> qu;
    while (qu--) {
        int a, b; cin >> a >> b;
        a--; b--;
        if (cycle[a] && cycle[b]) cout << 2 << endl;
        else cout << 1 << endl;
    }


    return 0;
}

