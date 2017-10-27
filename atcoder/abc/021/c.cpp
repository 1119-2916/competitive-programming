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

int n, a, b;
bool g[101][101];
int dp[101];

void solve(int pt);

signed main()
{
    cin >> n >> a >> b;
    Int(m);
    memset(g, false, sizeof(g));
    rep(i, m) {
        int2(x, y);
        g[x][y] = true;
        g[y][x] = true;
    }
    
    //cout << endl;

    memset(dp, 0, sizeof(dp));
    dp[a]++;
    solve(a);

    //Rep(i, n+1) cout << dp[i] << endl;

    cout << dp[b] % MOD << endl;


    return 0;
}

void solve(int pt)
{
    queue< int > q, p;
    q.push(pt);

    bool fl = false;
    bool used[101] = {false};
    while (!q.empty() && !fl) {
        int ndp[101]; rep(i, 101) ndp[i] = dp[i];
        while (!q.empty()) {
            pt = q.front(); q.pop();
            if (used[pt]) continue;
            else used[pt] = true;
            //cout << dp[pt] << endl;
            Rep(i, n+1) {
                if (g[pt][i]) {
                    ndp[i] += dp[pt];
                    //cout << i << " " << dp[i] << endl;
                    p.push(i);
                    if (i == b) fl = true;
                }
            }
        }
        rep(i, 101) dp[i] = ndp[i];
        //cout << endl;
        q = p;
    }
}

