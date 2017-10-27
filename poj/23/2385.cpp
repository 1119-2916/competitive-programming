#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
#include <stack>
#include <cstdlib>
#include <string>
#include <set>
#include <map>

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
#define Edge pair< int, i_i >
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

int dp[1001][31][2];

signed main()
{
    int2(t, l);
    //int dp[t+1][l+1][2];
    //memset(dp, (int)0, sizeof(dp));

    //vi apple(t);
    rep(i, t) {
        Int(tmp);
        Rep(j, l+1) {
            dp[i+1][j-1][0] = max(dp[i+1][j-1][0], dp[i][j][1]);
            dp[i+1][j-1][1] = max(dp[i+1][j-1][1], dp[i][j][0]);
            dp[i+1][j][0] = max(dp[i+1][j][0], dp[i][j][0]);
            dp[i+1][j][1] = max(dp[i+1][j][1], dp[i][j][1]);
        }
        dp[i+1][0][0] = max(dp[i+1][0][0], dp[i][0][0]);
        dp[i+1][0][1] = max(dp[i+1][0][1], dp[i][0][1]);

        rep(j, l+1) {
            dp[i+1][j][tmp]++;
        }

    }

    int ans = 0;
    rep(j, l+1) {
        ans = max(ans, dp[t][j][1]);
        ans = max(ans, dp[t][j][0]);
    }
    cout << ans << endl;

    return 0;
}

