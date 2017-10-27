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
#define mp make_pair
#define i_i pair<int, int>
#define vi vector<int>
#define vvi vector<vi >
#define vb vector<bool>
#define vvb vector<vb >
#define vp vector< i_i >
#define all(a) (a).begin(), (a).end()
#define Int(x) int x; scanf("%lld", &x);
 
//int dxy[5] = {0, 1, 0, -1, 0};
// assign
 
signed main()
{
    int n, ma, mb;
    cin >> n >> ma >> mb;
    vvi dp(4001, vi(4001, INF));
    vector< pair<int, i_i > > item(n);
    rep(i, n) {
        pair<int, i_i > tmp;
        cin >> tmp.first >> tmp.second.first >> tmp.second.second;
        item[i] = tmp;
    }
    dp[0][0] = 0;
    rep(i, n) {
        for (int j = 4000; j >= 0; j--) {
            for (int k = 4000; k >= 0; k--) {
                if (dp[j][k] != INF || (j == 0 && k == 0)) {
                    dp[j+item[i].first][k+item[i].second.first] =
                        min(dp[j+item[i].first][k+item[i].second.first],
                        dp[j][k] + item[i].second.second);
                }
            }
        }
    }
    int i = 1;
    int ret = INF;
    while (i * ma < 4001 && i * mb < 4001) {
        ret = min(ret, dp[i*ma][i*mb]);
        i++;
    }
    cout << ((ret == INF) ? -1 : ret) << endl;

    return 0;
}

