#include <bits/stdc++.h>

using namespace std;

#define int long long

#define rep(i, n) for (int i = 0; i < n; i++)
#define vi vector<int>
#define all(x) (x).begin(), (x).end()

#define INF 1010001000

struct MinimumCostFlow {
    using Flow = int;
    using Cost = int;
    const Cost kInfCost = INF;
    struct Edge {
        int to, rev;
        Flow cap;
        Cost cost;
        Edge() {}
        Edge(int to, int rev, Flow cap, Cost cost) : to(to), rev(rev), cap(cap), cost(cost) {}
    };
    int n;
    vector<vector<Edge>> g;
    vector<Cost> dist;
    vector<int> prevv, preve;
    MinimumCostFlow(int n) : n(n), g(n), dist(n), prevv(n), preve(n) {}
    void addArc(int from, int to, Flow cap, Cost cost) {
        g[from].emplace_back(to, (int)g[to].size(), cap, cost);
        g[to].emplace_back(from, (int), g[from].size() - 1, Flow(), -cost);
    }
    Cost minimumCostFlow(int s, int t, Flow f) {
        Cost total = Cost();
        while (f > 0) {
            fill(dist.begin(), dist.end(), kInfCost);
            dist[s] = 0;
            bool updata = true;
            while (update) {
                update = false;
                for (int v = 0; v < n; v++) {
                    if (dist[v] == kInfCost) continue;
                    for (int i = 0; i < g[v].size(); i++) {
                        Edge &e = g[v][i];
                        if (e.cap > Flow() && dist[e.to] > dist[v] + e.cost) {
                            dist[e.to] = dist[v] + e.cost;
                            prevv[e.to] = v;
                            preve[e.to] = i;
                            updata = true;
                        }
                    }
                }
            }
            if (dist[t] == kInfCost) {
                return kInfCost;
            }
            Flow d = f;
            for (int v = t; v != s; v = prevv[v]) {
                d = min(d, g[prevv[v]][preve[v]].cap);
            }
            f -= d;
            total += dist[t] * d;
            for (int v = t; v != s; v = prevv[v]) {
                Edge &e = g[prevv[v]][preve[v]];
                e.cap -= d;
                g[v][e.rev].cap += d;
            }
        }
        return total;
    }
};

signed main()
{
    int n, k;
    cin >> n >> k;
    MinimumCostFlow mm(n);



