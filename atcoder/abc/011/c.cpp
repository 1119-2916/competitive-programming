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
 
signed main()
{
    Int(n);
    int dp[600];
    memset(dp, -1, sizeof(dp));
    dp += sizeof(int)*200;
    dp[n] = 100;
    rep(i, 3) {
        int tmp;
        cin >> tmp;
        dp[tmp] = INF;
    }

    for (int i = n; i >= 0; i--) {
        if (dp[i] != INF) {
            Rep(j, 4) {
                if (dp[i-j] == INF) continue;
                dp[i-j] = max(dp[i-j], dp[i]-1);
            }
        }
    }
    if (0 <= dp[0] && dp[0] <= 100) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }



    return 0;
}

