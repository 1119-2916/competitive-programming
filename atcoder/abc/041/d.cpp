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
    int2(n, m);
    bool g[n][n];
    memset(g, false, sizeof(g));
    rep(i, m) {
        int2(a, b);
        g[a-1][b-1] = true;
    }

    int dp[1 << n + 1]; memset(dp, 0, sizeof(dp));
    rep(i, n) dp[1 << i] = 1;
    int s = (1 << n) -1;

    Rep(i, s) {
        rep(j, n) {     // 終端に追加するうさぎ
            if (i & (1 << j)) continue;
            bool fl = true;
            rep(k, n) {
                if (i & (1 << k)) {      // 必ずiにjが含まれない事が言える
                    if (g[j][k]) {      // 終端に追加したいので
                                        // iのどの要素にも勝ってはいけない
                        fl = false; break;
                    }
                }
            }
            if (fl) dp[i | (1 << j) ] += dp[i];
        }
    }
    cout << dp[s] << endl;


    return 0;
}

