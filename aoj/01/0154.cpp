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
#define Edge pair< i_i, int>
#define all(a) (a).begin(), (a).end()
#define Int(x) int x; scanf("%lld", &x);
#define int2(x, y) int x, y; scanf("%lld %lld", &x, &y);
#define fir first
#define sec second
#define ffir first.first
#define fsec first.second
#define sfir second.first
#define ssec second.second
 
//int dxy[5] = {0, 1, 0, -1, 0};
// assign
 
signed main()
{
    int n;
    while (cin >> n, n) {
        vi data(n), num(n);
        rep(i, n) {
            cin >> data[i] >> num[i];
        }
        vvi dp(n+1, vi(70200, 0));
        dp[0][0] = 1;
        rep(i, n) {
            rep(j, 70200) {
                dp[i+1][j] += dp[i][j];
            }
            Rep(j, num[i]+1) {
                for (int k = 70100; k >= 0; k--) {
                    if (dp[i][k]) {
                        dp[i+1][k+data[i]*j] += dp[i][k];
                    }
                }
            }
        }
        Int(g);
        while (g--) {
            Int(tmp);
            cout << dp[n][tmp] << endl;
        }
    }

    return 0;
}

