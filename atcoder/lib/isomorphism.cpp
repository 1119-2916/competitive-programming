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

#define index second
#define degree first
typedef vector< vector<int> > Matrix;
typedef pair<int, int> VertexInfo;


bool permTest(int k, const Matrix &g, const Matrix &h,
        vector<VertexInfo> &gs, vector<VertexInfo> &hs) {
    const int n = g.size();
    if (k >= n) return true;
    for (int i = k; i < n && hs[i].degree == gs[k].degree; ++i) {
        swap(hs[i], hs[k]);
        int u = gs[k].index, v = hs[k].index;
        for (int j = 0; j <= k; ++j) {
            if (g[u][gs[j].index] != h[v][hs[j].index]) goto esc;
            if (g[gs[j].index][u] != h[hs[j].index][v]) goto esc;
        }
        if (permTest(k+1, g, h, gs, hs)) return true;
esc:swap(hs[i], hs[k]);
    }
    return false;
}

bool isomorphism(const Matrix &g, const Matrix &h) {
    const int n = g.size();
    if (h.size() != n) return false;
    vector<VertexInfo> gs(n), hs(n);
    rep(i, n) {
        gs[i].index = hs[i].index = i;
        rep(j, n) {
            gs[i].degree += g[i][j];
            hs[j].degree += h[i][j];
        }
    }
    sort(all(gs)); sort(all(hs));
    rep(i, n) if (gs[i].degree != hs[i].degree) return false;

    return permTest(0, g, h, gs, hs);
}

