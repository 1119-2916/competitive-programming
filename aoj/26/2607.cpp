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
    int2(d, x);
    vvi table(d, vi(n, 0));
    rep(i, d) {
        rep(j, n) {
            cin >> table[i][j];
        }
    }
    vi dp(100001, 0);
    rep(i, d-1) {
        rep(j, x+1) {
            dp[j] = j;
        }
        int nxt = x;
        rep(j, n) {
            rep(k, x+1) {
                if (k < table[i][j]) continue;
                dp[k] = max(dp[k], dp[k-table[i][j]]+table[i+1][j]);
                nxt = max(nxt, dp[k]);
            }
        }
//        rep(i, x+1) { cout << dp[i] << " ";}cout << endl;
        x = nxt;
    }

    cout << x << endl;


    return 0;
}

