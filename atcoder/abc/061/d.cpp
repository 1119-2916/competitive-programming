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
typedef struct edge { int f, t, c; } edge;
 
//int dxy[5] = {0, 1, 0, -1, 0};
// assign
 
int bellman_ford(int st, int en, int n, vector<edge> &es);
int bellman_ford(int st, int en, int n, vector<edge> &es)
{
    vi d(n, INF);
    d[st] = 0;
    Rep(i, n) {
        bool update = false;
        rep(i, es.size()) {
            edge e = es[i];
            if (d[e.f] != INF && d[e.t] > d[e.f] + e.c) {
                d[e.t] = d[e.f] + e.c;
                update = true;
            }
        }
        if (!update) {
 //   rep(i, n) cout << d[i] << endl;
            return d[en];
        }
    }
//    cout << "ok" << endl;
    int bef = d[en];
    Rep(i, n) {
        bool update = false;
        rep(i, es.size()) {
            edge e = es[i];
            if (d[e.f] != INF && d[e.t] > d[e.f] + e.c) {
                d[e.t] = d[e.f] + e.c;
                update = true;
            }
        }
        if (!update) {
            return d[en];
        }
    }
    if (bef == d[en]) {
        return bef;
    } else {
        return INF;
    }
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
 
 
signed main()
{
    int2(n, m);
    vector<edge> es(m);
 
    rep(i, m) {
        cin >> es[i].f >> es[i].t >> es[i].c;
        es[i].f--;
        es[i].t--;
        es[i].c *= -1;
    }

    int ret = bellman_ford(0, n-1, n, es);
    if (ret == INF) {
        cout << "inf" << endl;
    } else {
        cout << -ret << endl;
    }
 
    return 0;
}

