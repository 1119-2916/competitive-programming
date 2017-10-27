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
    n++;
    vvi dp(n, vi(n, 0));
    Rep(i, n) Rep(j, n) cin >> dp[i][j];
    
    Rep(i, n) {
        int sum = 0;
        Rep(j, n) {
            sum += dp[i][j];
            dp[i][j] = sum;
        }
    }

    Rep(j, n) {
        int sum = 0;
        Rep(i, n) { 
            sum += dp[i][j];
            dp[i][j] = sum;
        }
    }

    vi ans(n*n, 0);
    rep(ai, n) { rep(aj, n) {
        Rep(di, n) { Rep(dj, n) {
            int sum = (di - ai) * (dj - aj);
            ans[sum] = max(ans[sum], dp[di][dj] - dp[di][aj]
                    - dp[ai][dj] + dp[ai][aj]);
        } }
    } }

    Rep(i, ans.size()) {
        ans[i] = max(ans[i-1], ans[i]);
    }

    Int(q);
    rep(i, q) {
        Int(tmp);
        cout << ans[tmp] << endl;
    }



    return 0;
}

