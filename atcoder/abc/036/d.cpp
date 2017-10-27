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
 
//int dxy[5] = {0, 1, 0, -1, 0};
// assign

vb used;
vi f, g;
vvi tree;
int n;

int cf(int pos, int par);
int cg(int pos, int par);

signed main()
{
    cin >> n;
    used = vb(n, false);
    tree = vvi(n);
    f = vi(n, 0);
    g = vi(n, 0);
    rep(i, n-1) {
        int2(a, b);
        a--; b--;
        tree[a].pb(b);
        tree[b].pb(a);
    }

    cout << cf(0, -1) << endl;

//    rep(i, n) cout << f[i] << " " << g[i] << endl;
    return 0;
}

int cf(int pos, int par)
{
    if (f[pos]) return f[pos];
    int ret = 1;
    for (int i : tree[pos]) {
        if (i != par) {
            ret *= cg(i, pos);
        }
        ret %= MOD;
    }
    f[pos] = (ret + cg(pos, par)) % MOD;
    return f[pos];
}

int cg(int pos, int par)
{
    if (g[pos]) return g[pos];
    int ret = 1;
    for (int i : tree[pos]) {
        if (i != par) {
            ret *= cf(i, pos);
        }
        ret %= MOD;
    }
    g[pos] = ret;
    return ret;
}

