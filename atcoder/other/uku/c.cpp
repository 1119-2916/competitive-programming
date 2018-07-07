#include <bits/stdc++.h>

using namespace std;

#define INF 1001000100010001000LL
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

int dxy[5] = {0, 1, 0, -1, 0};
// BIT DiscreteFourierTransform FFT avl cmd cusum dijkstra dinic geo2 gin graph kruskal lca lcm matrix ncm next_combination segtree st tmp topcoder uf vi 

int h, w;

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

//単一始点最短経路(負閉路なし)
//Dijkstra O((|E|+|V|)log|V|)
//dist: 始点から各頂点までの最短距離
//戻り値: 最短経路木の親頂点(根は-1)
void dijkstra(vector<string> &st, const Graph &g, int s, vector<Array> &dist) {
    int n = g.size();
    assert(s < n);
    enum { WHITE, GRAY, BLACK };
    int yui = (int)(st[s / w][s % w] == '.');
    vvi color(2, vi(n, WHITE)); color[yui][s] = GRAY;
    dist.assign(2, vi(n, INF)); dist[yui][s] = 0;
    using State = tuple<Weight, int, int>; //始点からの最短距離 子 状態
    priority_queue<State, vector<State>, greater<State>> pq; pq.emplace(0, s, yui);
    while (pq.size()) {
        Weight d; int v, u; tie(d, v, u) = pq.top(); pq.pop();
        if (dist[u][v] < d)continue;
        color[u][v] = BLACK;
        for (auto &e : g[v]) {
            if (color[u | st[v / w][v % w] == '.'][e.d] == BLACK)continue;
            if (dist[u | st[v / w][v % w] == '.'][e.d] > dist[u][v] + e.w) {
                dist[u | st[v / w][v % w] == '.'][e.d] = dist[u][v] + e.w;
                pq.emplace(dist[u | st[v / w][v % w] == '.'][e.d], e.d, (int)(u | st[v / w][v % w] == '.'));
                color[u | st[v / w][v % w] == '.'][e.d] = GRAY;
            }
        }
    }
}

int loop[900];

void make_loop(vector<string> &st, int pos, int end, vb &used, int score)
{
    if (used[pos]) {
        loop[end] = -1;
        return ;
    }
    if (st[pos / w][pos % w] == '#' || st[pos / w][pos % w] == '.') {
        loop[end] = -1;
        return ;
    }
    used[pos] = true;

    if (st[pos / w][pos % w] == '<') {
        pos--;
    } else if (st[pos / w][pos % w] == '^') {
        pos -= w;
    } else if (st[pos / w][pos % w] == '>') {
        pos++;
    } else if (st[pos / w][pos % w] == 'v') {
        pos += w;
    }

    if (pos == end) {
        loop[end] = score;
        return ;
    } else {
        make_loop(st, pos, end, used, score+1);
    }
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    cin >> h >> w; Int(q);

    Graph g(h * w);

    vector<string> st(h);
    rep(i, h) {
        cin >> st[i];
    }

    //int dxy[5] = {0, 1, 0, -1, 0};
    rep(i, h) rep(j, w) {
        if (st[i][j] == '.') {
            rep(k, 4) {
                int nx = i + dxy[k], ny = j + dxy[k+1];
                if (0 <= nx && nx < h && 0 <= ny && ny < w &&
                        st[nx][ny] != '#') {
                    addArc(g, i * w + j, nx * w + ny);
                }
            }
        } else if (st[i][j] == '>') {
            int nx = i, ny = j + 1;
            if (0 <= nx && nx < h && 0 <= ny && ny < w &&
                    st[nx][ny] != '#') {
                addArc(g, i * w + j, nx * w + ny);
            }
        } else if (st[i][j] == '<') {
            int nx = i, ny = j - 1;
            if (0 <= nx && nx < h && 0 <= ny && ny < w &&
                    st[nx][ny] != '#') {
                addArc(g, i * w + j, nx * w + ny);
            }
        } else if (st[i][j] == '^') {
            int nx = i-1, ny = j;
            if (0 <= nx && nx < h && 0 <= ny && ny < w &&
                    st[nx][ny] != '#') {
                addArc(g, i * w + j, nx * w + ny);
            }
        } else if (st[i][j] == 'v') {
            int nx = i + 1, ny = j;
            if (0 <= nx && nx < h && 0 <= ny && ny < w &&
                    st[nx][ny] != '#') {
                addArc(g, i * w + j, nx * w + ny);
            }
        }
    }

    rep(i, h * w) {
        vb used(h * w, false);
        make_loop(st, i, i, used, 1);
    }

    vvi funami[900];
    rep(i, w * h) {
        dijkstra(st, g, i, funami[i]);
    }

    while (q--) {
        int2(b, a); int2(d, c);
        a--; b--; c--; d--;
        int ans = INF;
        rep(i, w * h) {
            ans = min(ans, 
                    max(funami[i][1][a * w + b], funami[i][1][c * w + d]));
            if (loop[i] != -1) {
                ans = min(ans, 
                        ((funami[i][0][a * w + b] - funami[i][1][c * w + d]) / loop[i]
                         + 
                         !!((funami[i][0][a * w + b] - funami[i][1][c * w + d]) % loop[i])) *
                        loop[i] + funami[i][0][a * w + b]);
                ans = min(ans, 
                        ((funami[i][0][c * w + d] - funami[i][1][a * w + b]) / loop[i]
                         + 
                         !!((funami[i][0][c * w + d] - funami[i][1][a * w + b]) % loop[i])) *
                        loop[i] + funami[i][0][c * w + d]);
                if (funami[i][0][a * w + b] % loop[i] ==
                        funami[i][0][c * w + d] % loop[i]) {
                    ans = min(ans, 
                            max(funami[i][0][a * w + b], funami[i][0][c * w + d]));
                }
            }
        }
        if (ans == INF) {
            cout << -1 << endl;
        } else {
            cout << ans << endl;
        }
    }

    return 0;
}
