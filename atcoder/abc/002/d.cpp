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

int n, m;
vvb g;

int solve(int p);

signed main()
{
    cin >> n >> m;
    g.assign(n, vb(n, false));
    rep(i, m) {
        int2(x, y); x--; y--;
        g[x][y] = g[y][x] = true;
    }
    int ans = 0;
    Rep(i, (1 << n) + 1) {
        ans = max(ans, solve(i));
    }
    cout << ans << endl;

    return 0;
}

int solve(int p)
{
    int ret = 0;
    rep(i, n) {
        if ((p >> i) & 1) {
            ret++;
            for (int j = i+1; j < n; j++) {
                if ((((p >> j) & 1) && !g[i][j])) {
                    return 0;
                }
            }
        }
    }
    return ret;

}

