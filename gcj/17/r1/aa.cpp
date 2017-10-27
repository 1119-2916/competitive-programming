#include <bits/stdc++.h>
 
using namespace std;
 
#define INF 1001000100010001000
#define MOD 1000000007
#define pi 3.1415926535897932384626433
#define EPS 1e-10
#define int long long
#define double long double
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
 
signed main()
{
    Int(dataset);

    Rep(state, dataset+1) {
        cout << "Case #" << state << ": ";

        int2(n, k);
        vector < i_i > c(n);
        rep(i, n) {
            cin >> c[i].first >> c[i].second;
        }

        sort(all(c));
        reverse(all(c));

        vvi dp(k+1, vi(n+1, 0));

        rep(i, k) {
            rep(j, n) {
                if (!i) {
                    dp[i+1][j+1] = max(dp[i+1][j], 
                            c[j].first * c[j].first +
                            c[j].first * 2 * c[j].second);
                } else {
                    dp[i+1][j+1] = max(max(dp[i+1][j], dp[i][j]),
                            dp[i][j] + c[j].first * 2
                            * c[j].second);
                }
            }
        }

        int ans = 0;
        rep(i, n+1) {
            ans = max(ans, dp[k][i]);
        }
        printf("%.9Lf\n", (double)ans * pi);
    }

    return 0;
}

