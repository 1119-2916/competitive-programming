
bool find_negative_loop(int n, vector<edge> &es);
bool find_negative_loop(int n, vector<edge> &es)
{
    int n = g.size();
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
 
