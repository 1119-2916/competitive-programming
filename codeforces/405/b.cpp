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
vvi g;
vi cnt;
vi nodes;

void dfs(int pos);

signed main()
{
    int2(n, m);
    g.assign(n, vi(0, 0));
    cnt.assign(n, 0);

    rep(i, m) {
        int2(a, b);
        cnt[a-1]++;
        cnt[b-1]++;
        g[a-1].pb(b-1);
        g[b-1].pb(a-1);
    }
    used.assign(n, false);
    rep(i, n) {
        if (!used[i]) {
            nodes.assign(0, 0);
            //cout << dfs(i, 0) << endl;
            dfs(i);
            rep(j, nodes.size()) {
                if (cnt[nodes[j]] != nodes.size()-1) {
                    cout << "NO" << endl;
                    return 0;
                }
            }
            //cout << ans << endl;
        }
    }
    cout << "YES" << endl;
    return 0;
}

void dfs(int pos)
{
    used[pos] = true;
    nodes.pb(pos);
    for (int i : g[pos]) {
        if (!used[i]) {
            dfs(i);
        }
    }
}

