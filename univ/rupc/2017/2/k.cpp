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
#define eb emplace_back
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

int cost[100000], used[100000], n, m;
vvi G;

bool dfs(int pos, int state);

signed main()
{
    cin >> n >> m;
    rep(i, n) cin >> cost[i];
    G.assign(n, vi());

    rep(i, m) {
        int2(a, b);
        G[a].pb(b);
        G[b].pb(a);
    }
    if (dfs(0, 1)) {
        int ans = 0;
        rep(i, n) {
            if (used[i] == 1) {
                ans += cost[i];
            }
        }
        cout << ans << endl;
    } else {
        int ans = 0;
        rep(i, n) {
            ans += cost[i];
        }
        cout << ans << endl;
    }

    return 0;
}

bool dfs(int pos, int state)
{
//    cout << pos << endl;
    if (!used[pos]) {
        used[pos] = state;
    } else if (used[pos] == state) return true;
    else return false;
    bool ret = true;
    for (int i : G[pos]) {
        ret &= dfs(i, -state);
    }
    return ret;
}

