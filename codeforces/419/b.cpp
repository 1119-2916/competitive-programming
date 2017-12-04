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
    Int(n);
    int2(k, q);
    vi data(200002, 0);
    rep(i, n) {
        int2(a, b);
        data[a]++;
        data[b+1]--;
    }
    Rep(i, data.size()) {
        data[i] += data[i-1];
    }
    vi dp(200002, 0);
    rep(i, data.size()) {
        if (data[i] >= k) {
            dp[i]++;
        }
    }
    Rep(i, dp.size()) {
        dp[i] += dp[i-1];
    }
    while (q--) {
        int2(a, b);
        cout << dp[b] - dp[a-1] << endl;
    }
        

    return 0;
}

