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

int v[210], w[210];

signed main()
{
    int2(n, W);
    rep(i, n) { cin >> v[i] >> w[i]; }

    if (n <= 30) {
        vector< i_i > bef(1 << n/2, i_i(0, 0));
        Rep(i, 1 << n/2) {
            rep(j, n/2) {
                bef[i].first += w[j] * (i >> j & 1);
                bef[i].second += v[j] * (i >> j & 1);
            }
        }
        sort(all(bef));
        Rep(i, bef.size()) {
            if (bef[i-1].second > bef[i].second) {
                bef[i].second = bef[i-1].second;
            }
        }

        int ans = 0;
        rep(i, 1 << (n - n/2)) {
            int sw = 0, sv = 0;
            rep(j, (n - n/2)) {
                sw += w[j + n/2] * ((i >> j) & 1);
                sv += v[j + n/2] * ((i >> j) & 1);
            }
            if (W >= sw) {
                auto res = lower_bound(all(bef), i_i(W - sw , INF))-1;
                ans = max(ans, sv + res->second);
            }
        }
        cout << ans << endl;
    } else if(*min_element(v, v + n) <= 1000) {
        vi dp(1000 * 200 + 1, INF);
        rep(i, n) {
            for (int j = 1000 * 200; j > 0; j--) {
                if (dp[j] != INF) {
                    dp[j + v[i]] = min(dp[j + v[i]], dp[j] + w[i]);
                }
            }
            dp[v[i]] = min(dp[v[i]], w[i]);
        }
        int ans = 0;
        rep(i, dp.size()) {
            if (dp[i] <= W) {
                ans = max(ans, i);
            }
        }
        cout << ans << endl;
    } else {
        vi dp(W+1, 0);
        rep(i, n) {
            for (int j = W; j >= 0; j--) {
                if (j + w[i] <= W) {
                    dp[j + w[i]] = max(dp[j + w[i]], dp[j] + v[i]);
                }
            }
            dp[w[i]] = max(dp[w[i]], v[i]);
        }
        int ret = 0;
        rep(i, W+1) {
            ret = max(ret, dp[i]);
        }
        cout << ret << endl;
    }

    return 0;
}

