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
    int2(n, x);
    vi data(n);
    int ans = 0;
    rep(i, n) {
        cin >> data[i];
        ans += data[i];
    }
    vvi dp(n, vi(n));
    rep(i, n) {
        int tmp = dp[i][i] = data[i];
        for (int j = i+1; j < n; j++) {
            tmp = min(data[j], tmp);
            dp[i][j] = tmp;
        }
    }

    for (int i = 2; i < n+1; i++) {
        // 区間のサイズ
//        cout << "===size: " << i << endl;
        
        int sum = 0;
        rep(j, n) {
            // 始点
   //         cout << "point: " << j << " ";
            if (j + 1 < i) {
                sum += min(dp[0][j], dp[n-(i-j-1)][n-1]);
 //               cout << min(dp[0][j], dp[n-(i-j-1)][n-1]) << endl;
            } else {
                sum += dp[j-i+1][j];
  //              cout << dp[j-i+1][j] << endl;
            }
        }
//        cout << "========" << endl;
        ans = min(ans, sum + ((i - 1) * x));
    }
    cout << ans << endl;
    return 0;
}

