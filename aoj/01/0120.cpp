#include <bits/stdc++.h>

using namespace std;

#define INF 1001000100010001000
#define INFd 1010001000
#define MOD 1000000007
#define EPS 1e-10
#define int long long
#define double long double
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
#define vvd vector<vd>

signed main()
{
    double len;
    char t;
    while (scanf("%Lf", &len) != EOF) {
        vi cake;
        while (scanf("%c", &t), t != '\n') {
            Int(tmp);
            cake.pb(tmp);
        }
        vvd dp(1 << cake.size(), vd(cake.size(), INFd));
        dp[0][0] = 0.0;


        rep(i, cake.size()) {
            int tmp = 1 << i;
            dp[tmp][i] = cake[i];
        }

        rep(i, 1 << cake.size()) {
            rep(j, cake.size()) {
                if (i & (1 << j)) {
                    rep(k, cake.size()) {
                        if (!(i & (1 << k))) {
                            dp[i|(1 << k)][k] = min(dp[i|(1 << k)][k],
                                    dp[i][j] + 
                                    sqrt( (double)((cake[j]+cake[k])*(cake[j]+cake[k]) - 
                                            (cake[k]-cake[j])*(cake[k]-cake[j])) ));
                        }
                    }
                }
            }
        }
        bool ans = false;
        rep(i, cake.size()) {
            if (len >= dp[(1 << cake.size())-1][i] + (double)cake[i]) {
                ans = true;
                break;
            }
        }
        cout << ( (ans) ? "OK" : "NA" ) << endl;
    }

    return 0;
}

