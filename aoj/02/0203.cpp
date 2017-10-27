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
    int2(b, a);
    while (a) {
        vvi data(a, vi(b));
        rep(i, a) {
            rep(j, b) {
                cin >> data[i][j];
            }
        }
        
       // cout << "=======" << endl;
        vvi dp(a+1, vi(b, 0));
        rep(i, b) {
            if (!data[0][i]) {
                dp[0][i] = 1;
            }
        }
        

        rep(i, a-1) {
            rep(j, b) {
                if (!data[i][j]) {
                    for (int k = -1; k < 2; k++) {
                        if (data[i+1][j+k] == 2) {
                            if (!k) {
                                dp[i+1][j] += dp[i][j];
                            }
                        } else if (!data[i+1][j+k]) {
                            dp[i+1][j+k] += dp[i][j];
                        }
                    }
                } else if (data[i][j] == 2) {
                    dp[i+2][j] += dp[i][j];
                }
            }
        }
/*
        rep(i, a+1) {
            rep(j, b) {
                cout << dp[i][j] << " ";
            }cout << endl;
        }*/

        int ans = 0;
        rep(i, b) {
            if (data[a-1][i] != 1) {
                ans += dp[a][i] + dp[a-1][i];
            } else {
                ans += dp[a][i];
            }
            /*
            if (data[a-1][i] == 1) {
                //cout << dp[a][i] << " ";
                ans += dp[a][i];
            } else {
                //cout << dp[a-1][i] << " ";
                ans += dp[a-1][i];
            }
            */
        }
        cout << ans << endl;
        cin >> b >> a;
    }

    return 0;
}

