#define NAAN_TIKE_PLATYPUS
#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <cstring>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <array>
#include <cassert>
#include <bitset>
#include <cstdint>
using namespace std;
using LL = long long;


struct edge {
    int to;
    long long cost;
    int isE;
    edge(int to_, long long cost_, int isE_) :
        to(to_), cost(cost_), isE(isE_) {}
};
const long long INF = 123456789012345;
using P = pair<long long, int>;
void dijkstra(vector<edge>graph_[], long long dist[], int n_, int s_) {
    priority_queue<P, vector<P>, greater<P>>que;
    que.push({ 0,s_ });
    fill(dist, dist + n_, INF);
    dist[s_] = 0ll;
    while (!que.empty()) {
        auto q = que.top();
        que.pop();
        long long thd = q.first;
        int thv = q.second;
        if (thd > dist[thv])
            continue;
        for (auto ed : graph_[thv]) {
            if (dist[ed.to] > ed.cost + thd) {
                dist[ed.to] = ed.cost + thd;
                que.push({ dist[ed.to],ed.to });
            }
        }
    }
}

LL N, T, S, E;
vector<edge>G[123456];
bool mark[123456];
LL cnt[123456];
bool done = false;
bool suc = false;
void dfs(int x, int las) {
    if (done)return;
    ++cnt[x];
    sort(G[x].begin(), G[x].end(), [&](const edge& e1, const edge& e2) {if (e1.isE == e2.isE)return e1.cost < e2.cost; return e1.isE < e2.isE; });
    for (auto p : G[x]) {
        int v = p.to;
        if (v == las)continue;
        if (p.cost <= (cnt[x] + cnt[p.to]) * T) {
            //渡れない
            done = true;
            return;
        }
        dfs(v, x);
        if (done)return;
        if (p.cost <= (cnt[x] + cnt[p.to]) * T) {
            //渡れない
            done = true;
            return;
        }
        if (done)return;
        ++cnt[x];
    }
    if (x == E) {
        done = true;
        suc = true;
    }
}

LL dS[123456], dE[123456];

int main() {
    cin >> N >> T >> S >> E;
    --S; --E;
    for (int i = 1; i < N; ++i) {
        LL a, b, w;
        cin >> a >> b >> w;
        --a; --b;
        G[a].push_back({ int(b),w,0 });
        G[b].push_back({ int(a),w,0 });
    }
    dijkstra(G, dS, N, S);
    dijkstra(G, dE, N, E);
    LL SE = dS[E];
    for (int i = 0; i < N; ++i) {
        if (dS[i] + dE[i] == SE) {
            mark[i] = true;
        }
    }
    for (int i = 0; i < N; ++i) {
        for (auto& p : G[i]) {
            p.isE = (mark[p.to] && mark[i]);
        }
    }
    cnt[S] = -1;
    dfs(S, -1);
    if (suc) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}
