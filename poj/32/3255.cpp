#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
#include <stack>
#include <cstdlib>
#include <string>
#include <set>
#include <map>

using namespace std;

#define INF 1001000100010001000
#define MOD 1000000007
#define EPS 1e-10
#define int long long
#define rep(i, N) for (int i = 0; i < N; i++)
#define Rep(i, N) for (int i = 1; i < N; i++)
#define For(i, a, b) for (int i = (a); i < (b); i++)
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
#define Int(x) int x; scanf("%lld", &x);
#define int2(x, y) int x, y; scanf("%lld %lld", &x, &y);
#define fir first
#define sec second
#define ffir first.first
#define fsec first.second
#define sfir second.first
#define ssec second.second
#define Graph vector< vp >

//単一始点最短経路(負閉路なし)
//Dijkstra O((E+V)logV)
//dist: 始点から各頂点までの最短距離
//戻り値: 最短経路木の親頂点(根は-1)
void dijkstra(Graph &g, int s, vp &dist)
{
    int n = g.size();
    dist.assign(n, i_i(INF, INF)); dist[s].fir = 0;
    priority_queue< i_i, vector< i_i >, greater< i_i > > pq;
    pq.push(i_i((int)0, s));

    while (pq.size()) {
        int d = pq.top().fir, v = pq.top().sec;
        pq.pop();
        if (dist[v].sec < d) continue; //すでに最短でなければ無視
        for (int i = 0; i < g[v].size(); i++) {
            i_i &e = g[v][i];
            int d2 = d + e.sec;
            if (dist[e.fir].fir > d2) {
                swap(dist[e.fir].fir, d2);
                pq.push(i_i(dist[e.fir].fir, e.fir));
            }
            if (dist[e.fir].sec > d2 && dist[e.fir].fir < d2) {
                dist[e.fir].sec = d2;
                pq.push(i_i(dist[e.fir].sec, e.fir));
            }
        }
    }
}



signed main()
{
    int2(n, m);
    Graph g(n);
    rep(i, m) {
        int2(a, b);
        Int(cost);
        a--; b--;
        g[a].pb(i_i(b, cost));
        g[b].pb(i_i(a, cost));
    }
    vp dist(n);
    dijkstra(g, 0, dist);
    /*
    rep(i, n) {
        cout << dist[i].fir << " " << dist[i].sec << endl;
    }
    */
    cout << dist[n-1].sec << endl;
    return 0;
}

