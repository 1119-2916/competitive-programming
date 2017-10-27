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
 
//int dxy[5] = {0, 1, 0, -1, 0};
// assign
 
signed main()
{
    Int(n);
    Int(m);

    while (m) {
        vi code(m);
        rep(i, m) {
            cin >> code[i];
        }
        vi x(n);
        rep(i, n) {
            cin >> x[i];
        }
        vvi dp(n, vi(256, INF));
        int st = 128;
        rep(i, m) {
            int tmp = st + code[i];
            tmp = (tmp < 0) ? 0 : tmp;
            tmp = (tmp > 255) ? 255 : tmp;
            dp[0][tmp] = min(dp[0][tmp], (x[0] - tmp) * (x[0] - tmp));
        }
        rep(i, n-1) {
            rep(j, 256) {
                if (dp[i][j] != INF) {
                    st = j;
                } else {
                    continue;
                }
                rep(k, m) {
                    int tmp = st + code[k];
                    tmp = (tmp < 0) ? 0 : tmp;
                    tmp = (tmp > 255) ? 255 : tmp;
                    dp[i+1][tmp] = min(dp[i+1][tmp], 
                            dp[i][j] + (x[i+1] - tmp) * (x[i+1] - tmp));
                }
            }
        }
        int ret = INF;
        rep(i, 256) {
            ret = min(ret, dp[n-1][i]);
        }
        cout << ret << endl;
        cin >> n >> m;
    }

    return 0;
}

