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

int a, b, c, n;
int dp[501][50], g[501][501];

signed main()
{
    int m;
    cin >> n >> m;
    fill(g[0], g[501], INF);
    //memset(g, INF, sizeof(g));
    rep(i, m) {
        int s, t, u;
        cin >> s >> t >> u;
        g[s][t] = u;
        g[t][s] = u;
    }
    Int(v);
    cin >> a >> b >> c;
    queue< pair<int, i_i > > q;
    q.push(mp(0, mp(1, v)));
    fill(dp[0], dp[501], INF);
    //memset(dp, INF, sizeof(dp));
    dp[1][v] = 0;
    while (!q.empty()) {
        pair<int, i_i > tmp = q.front(); q.pop();
        int val = tmp.first, pos = tmp.second.first, 
            ver = tmp.second.second;
        if (val > dp[pos][ver]) {
            continue;
        }
        for (int i = 1; i <= n; i++) {
            if (g[pos][i] != INF) {
                int nval = val + ver * g[pos][i];
                int nver = (ver * a + b) % c;
                if (nval < dp[i][nver]) {
                    dp[i][nver] = nval;
                    q.push(mp(nval, mp(i, nver)));
                }
            }
        }
    }

    //Rep(i, n+1) { rep(j, c) { cout << dp[i][j] << " "; } cout << endl;}
    
    for (int i = 0; i < c; i++) {
        if (dp[n][i] != INF) {
            q.push(mp(dp[n][i], mp(n, i)));
        }
    }

    //memset(dp, INF, sizeof(dp));
    fill(dp[0], dp[501], INF);
    while (!q.empty()) {
        pair<int, i_i > tmp = q.front(); q.pop();
        int val = tmp.first, pos = tmp.second.first, 
            ver = tmp.second.second;
        if (val > dp[pos][ver]) {
            continue;
        } else {
            dp[pos][ver] = val;
        }
        for (int i = 1; i <= n; i++) {
            if (g[pos][i] != INF) {
                int nval = val + ver * g[pos][i];
                int nver = (ver * a + b) % c;
                if (nval < dp[i][nver]) {
                    dp[i][nver] = nval;
                    q.push(mp(nval, mp(i, nver)));
                }
            }
        }
    }
    int ans = INF;
    rep(i, c) {
        ans = min(ans, dp[1][i]);
    }
    cout << ans << endl;


    return 0;
}




