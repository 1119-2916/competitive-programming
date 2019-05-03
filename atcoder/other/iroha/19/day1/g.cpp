#include <bits/stdc++.h>

using namespace std;

#define int long long
#define INF 1010001000
#define MOD 1000000007
#define EPS 1e-8
#define rep(i, N) for (int i = 0; i < N; i++)
#define Rep(i, N) for (int i = 1; i < N; i++)
#define For(i, a, b) for (int i = (a); i < (b); i++)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vi >
#define vb vector<bool>
#define vvb vector<vb >
#define vp vector< pii >
#define all(a) (a).begin(), (a).end()
#define Int(x) int x; cin >> x;
#define int2(x, y) Int(x); Int(y);
#define int3(x, y, z) Int(x); int2(y, z);
#define in(x, a, b) ((a) <= (x) && (x) < (b))
#define fir first
#define sec second
#define ffir first.first
#define fsec first.second
#define sfir second.first
#define ssec second.second
#define Decimal fixed << setprecision(10)

//int dxy[5] = {0, 1, 0, -1, 0};
// cmd

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int3(n, m, blank);
    vector<int> data(n);
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }

    vector<vvi> dp(2, vvi(370, vi(370, -1)));
    dp[0][0][0] = 0;

    rep(i, n) {
        rep(j, m+1) {
            rep(k, blank+1) {
                dp[(i+1)%2][j][k] = -1;
            }
        }
        rep(j, m+1) {
            rep(k, blank) {
                if (dp[i%2][j][k] != -1) {
                    if (j != m) dp[(i+1)%2][j+1][0] = max(dp[(i+1)%2][j+1][0], dp[i%2][j][k] + data[i]);
                    if (k != blank-1) dp[(i+1)%2][j][k+1] = max(dp[(i+1)%2][j][k+1], dp[i%2][j][k]);
                }
            }
        }
    }

    /*
    rep(i, n+1) {
        std::cout << i << " : " << std::endl;
        rep(j, m+1) {
            rep(l, k+1) {
                std::cout << dp[i][j][l] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    */

    int ans = 0;
    rep(i, m+1) {
        rep(j, blank) {
            ans = max(ans, dp[n%2][i][j]);
        }
    }
    if (ans) {
        std::cout << ans << std::endl;
    } else  {
        std::cout << -1 << std::endl;
    }


    return 0;
}
