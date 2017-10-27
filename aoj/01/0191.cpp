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
#define vd vector<double>
#define vvd vector< vd >
 
//int dxy[5] = {0, 1, 0, -1, 0};
// assign
 
signed main()
{
    int2(a, b);
    while (a) {
        vvd table(a, vd(a));
        rep(i, a) { rep(j, a) {
            cin >> table[i][j];
        } }

        vvd dp(b, vd(a, 0.0));
        rep(i, a) {
            dp[0][i] = 1.0;
        }
        rep(i, b-1) {
            rep(j, a) {
                rep(k, a) {
                    dp[i+1][k] = max(dp[i+1][k], 
                            dp[i][j] * table[j][k]);
                }
            }
        }
            
        double ans = 0.0;
        rep(i, a) {
            ans = max(dp[b-1][i], ans);
        }
        long ret = round(ans * 100);
        printf("%.2lf\n", (double)ret / 100);
        cin >> a >> b;
    }
    return 0;
}

