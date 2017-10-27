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

int n, m;
vvi kyoko, yui, yuikyo;
vi gorakubu;
vb used;

void dfs(int pos);
void make_toshino(void);
bool permTest(int k, const Matrix &g, const Matrix &h,
        vector<VertexInfo> &gs, vector<VertexInfo> &hs);
bool isomorphism(const Matrix &g, const Matrix &h);

signed main()
{
    cin >> n >> m;
    n++;
    yuikyo.assign(n, vi());
    used.assign(n, false);
    rep(i, m) {
        int2(a, b);
        yuikyo[a].pb(b);
        yuikyo[b].pb(a);
    }
    Int(yn);
    yn++;
    yui.assign(yn, vi());
    Rep(i, yn-1) {
        int2(a, b);
        yui[a].pb(b);
        yui[b].pb(a);
    }
    int ans = 0;
    cout << "end_scan" << endl;
    Rep(i, n) {
        //rep(i, n) cout << used[i] << " ";cout << endl;
        if (!used[i]) {
            cout << i << endl;
            gorakubu.assign(0, 0);
            used[i] = true;
            gorakubu.pb(i);
            dfs(i);
            //rep(i, gorakubu.size())cout<<gorakubu[i]<< " ";cout << endl;
            //cout << "size" << gorakubu.size() << endl;
            //kyoko.assign(gorakubu.size(), vi());
            make_toshino();

            if (isomorphism(kyoko, yui)) {
                ans++;
            }
        }
    }
    cout << ans << endl;

    return 0;
}

void dfs(int pos)
{
    //cout << "size" << yuikyo[pos].size() << endl;
    for (int i : yuikyo[pos]) {
        if (used[i]) continue;
        else {
            //cout << i << " " ;
            used[i] = true;
            gorakubu.pb(i);
            dfs(i);
        }
    }
}

void make_toshino(void)
{
    rep(i, gorakubu.size()) {
        kyoko.pb(yuikyo[gorakubu[i]]);
        // copy(all(), kyoko.begin());
    }
    /*
    rep(i, kyoko.size()) {
        rep(j, kyoko[i].size()) {
            cout << kyoko[i][j] << " ";
        }
        cout << endl;
    }
    */
}


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

