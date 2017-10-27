typedef struct edge { int f, t, c; } edge;

int bellman_ford(int st, int en, vvi &g, vector<edge> &es);
int bellman_ford(int st, int en, vvi &g, vector<edge> &es)
{
    vi d(g.size(), INF);
    d[st] = 0;
    while (1) {
        bool update = false;
        rep(i, es.size()) {
            edge e = es[i];
            if (d[e.f] != INF && d[e.t] > d[e.f] + e.c) {
                d[e.t] = d[e.f] + e.c;
                update = true;
            }
        }
        if (update) {
            break;
        }
    }
    return d[en];
}


bool find_negative_loop(int n, vector<edge> &es);
bool find_negative_loop(int n, vector<edge> &es)
{
    vi d(n, 0);

    rep(i, n) {
        rep(j, es.size()) {
            edge e = es[j];
            if (d[e.t] > d[e.f] + e.c) {
                d[e.t] = d[e.f] + e.c;
                if (i == n - 1) return true;
            }
        }
    }
    return false;
}
 
