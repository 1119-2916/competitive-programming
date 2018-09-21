#include <bits/stdc++.h>

using namespace std;

#define INF 1001000100010001000ll
#define MOD 1000000007
#define EPS 1e-10
#define int long long
#define rep(i, N) for (int i = 0; i < N; i++)
#define Rep(i, N) for (int i = 1; i < N; i++)
#define For(i, a, b) for (int i = (a); i < (b); i++)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vi >
#define vb vector<bool>
#define vvb vector<vb >
#define vp vector< pii >
#define all(a) (a).begin(), (a).end()
#define Int(x) int x; cin >> x;
#define int2(x, y) Int(x); Int(y);
#define int3(x, y, z) Int(x); int2(y, z);
#define in(x, a, b) ((a) <= (x) && (x) < (b))
#define fir first
#define sec second
#define ffir first.first
#define fsec first.second
#define sfir second.first
#define ssec second.second
#define Decimal fixed << setprecision(10)

#define ttjr 7

//int dxy[5] = {0, 1, 0, -1, 0};
// BIT DiscreteFourierTransform FFT avl cmd cusum dijkstra dinic geo2 gin graph kruskal lca lcm matrix ncm next_combination ppuf segtree st tmp topcoder uf vi 

using Weight = int;
using Flow = int;
struct Edge {
    int s, d; Weight w1, w2; Flow c;
    Edge() {};
    Edge(int s, int d, Weight w1 = 1, Weight w2 = 1) : 
        s(s), d(d), w1(w1), w2(w2), c(w1) {};
    int cost(int t) {
        return (w2 / (w1 + t)) + !!(w2 % (w1 + t));
    }
};
bool cmp_cost(Edge &e1, Edge &e2, int time)
{
    return e1.cost(time) < e2.cost(time);
}
bool cmp_equal(Edge &e1, Edge &e2, int time)
{
    return e1.cost(time) == e2.cost(time);
}

using Edges = vector<Edge>;
using Graph = vector<Edges>;
using Array = vector<Weight>;
using Matrix = vector<Array>;

void addArc(Graph &g, int s, int d, Weight w1 = 1, Weight w2 = 1) {
    g[s].emplace_back(s, d, w1, w2);
}
void addEdge(Graph &g, int a, int b, Weight w1 = 1, Weight w2 = 1) {
    addArc(g, a, b, w1, w2);
    addArc(g, b, a, w1, w2);
}
int ceil_int(int a, int b) {
    return (a + b - 1) / b;
}
int superKenchonFunction(int a, int b, int lt)
{
    //cout << "call : " << a << " " << b << endl;
    int k1 = (int)sqrt(b);
    int k2 = k1+1, k3 = k1-1;
    int res = lt + (b + lt + a - 1) / (lt + a);
    if (ceil_int(b, k1) - a >= lt) {
        res = min(res, ceil_int(b, k1) - a + k1);
    }
    if (ceil_int(b, k2) - a >= lt) {
        res = min(res, ceil_int(b, k2) - a + k2);
    }
    if (k3 > 0 && ceil_int(b, k3) - a >= lt) {
        res = min(res, ceil_int(b, k3) - a + k3);
    } 
    return res;
    
}


//単一始点最短経路(負閉路なし)
//Dijkstra O((|E|+|V|)log|V|)
//dist: 始点から各頂点までの最短距離
//戻り値: 最短経路木の親頂点(根は-1)
vector<int> dijkstra(Graph &g, int s, Array &dist, int time) {
    int n = g.size();
    assert(s < n);
    enum { WHITE, GRAY, BLACK };
    vector<int> color(n, WHITE); color[s] = GRAY;
    vector<int> prev(n, -1);
    dist.assign(n, INF); dist[s] = 0;
    using State = tuple<Weight, int, int>; //始点からの最短距離 子 親
    priority_queue<State, vector<State>, greater<State>> pq; pq.emplace(0, s, -1);
    while (pq.size()) {
        Weight d; int v, u; tie(d, v, u) = pq.top(); pq.pop();
        if (dist[v] < d)continue;
        color[v] = BLACK; prev[v] = u;
        for (auto &e : g[v]) {
            if (color[e.d] == BLACK)continue;
            //cout << "dij : " << superKenchonFunction(e.w1, e.w2, dist[v]) << endl;
            if (dist[e.d] > superKenchonFunction(e.w1, e.w2, dist[v])) {
                dist[e.d] = superKenchonFunction(e.w1, e.w2, dist[v]);
                //cout << e.d << " : " << dist[e.d] << endl;
                pq.emplace(dist[e.d], e.d, v);
                color[e.d] = GRAY;
            }
        }
    }
    return prev;
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int2(n, m);
    int2(yui, kyoko); yui--; kyoko--;

    Graph g(n);
    for (int i = 0; i < m; i++) {
        int2(tmpx, tmpy);
        int2(a, b);
        tmpx--; tmpy--;
        addEdge(g, tmpx, tmpy, a, b);
    }

    vi data;
    /*
    int left = 0, right = INF;
    while (right - left > ttjr * 2) {
        int hoge = (left + right) / ttjr;

        int ptr = 0, ptr_e = 0;
        dijkstra(g, yui, data, left);
        int huga = data[kyoko];
        Rep(i, ttjr+1) {
            dijkstra(g, yui, data, left + hoge * i);
            if (huga > data[kyoko]) {
                huga = data[kyoko];
                ptr = i;
                ptr_e = i;
            } else if (huga == data[kyoko]) {
                ptr_e = i;
            }
        }

        if (huga == INF) {
            cout << -1 << endl;
            return 0;
        }
        if (ptr != ptr_e) {
            left = ptr; right = ptr_e;
        } else {
            left = max(0ll, ptr-hoge);
            right = min(INF, ptr + hoge);
        }
    }

    int ans = INF;
    for (int i = left; i <= right; i++) {
        dijkstra(g, yui, data, i);
        ans = min(ans, data[kyoko]);
    }
    */
/*
    int ans = INF;
    rep(i, 10000000) {
        dijkstra(g, yui, data, i);
        cout << data[kyoko] << endl;
        ans = min(ans, data[kyoko]);
    }
    */
    
    dijkstra(g, yui, data, 0);
    int ans = data[kyoko];
    /*rep(i, data.size()) {
        cout << data[i] << " ";
    }cout << endl;*/

    if (ans == INF) {
        std::cout << -1 << std::endl;
    } else {
        cout << ans << endl;
    }

    return 0;
}
