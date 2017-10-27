#include <bits/stdc++.h>

using namespace std;

#define INF 1001000100010001000
#define MOD 1000000007
#define EPS 1e-8
#define int long long 
#define rep(i, N) for (int i = 0; i < N; i++)
#define Rep(i, N) for (int i = 1; i < N; i++)
#define pb push_back
#define mp make_pair
#define i_i pair<int, int>
#define vi vector<int>
#define vvi vector< vi >
#define vb vector<bool>
#define vp vector< i_i >
#define all(a) (a).begin(), (a).end()
#define Int(x) int x; cin >> x;
#define int2(x, y) Int(x); Int(y);
#define fir first
#define sec second
#define ffir first.first
#define fsec first.second
#define sfir second.first
#define ssec second.second


signed main()
{
    int SCORE = 10001;
    //int SCORE = 101;
    int2(n, c);
    vector< pair<i_i, int> > data(n);
    rep(i, n) {
        cin >> data[i].ffir >> data[i].fsec >> data[i].sec;
    }
    static int dp[2][102][10010];
    memset(dp, 0, sizeof(dp));
    //cout << "ok" << endl;

    rep(i, n) {
        for (int j = c; j > 0; j--) {
            for (int k = SCORE; k >= 0; k--) {
                dp[(i+1)%2][j][k] = max(dp[(i+1)%2][j][k], dp[i%2][j][k]);
                if (dp[i%2][j][k] && j + data[i].sec <= c) {
                    int yui = k + data[i].ffir, 
                        kyoko = dp[i%2][j][k] + data[i].fsec;
                    dp[(i+1)%2][j+data[i].sec][max(yui,kyoko)] =
                        max(dp[(i+1)%2][j+data[i].sec][max(yui,kyoko)],
                                min(yui, kyoko));

                    yui = k + data[i].fsec; 
                    kyoko = dp[i%2][j][k] + data[i].ffir;
                    dp[(i+1)%2][j+data[i].sec][max(yui,kyoko)] =
                        max(dp[(i+1)%2][j+data[i].sec][max(yui,kyoko)],
                                min(yui, kyoko));
                }
            }
        }
        int yui = data[i].ffir, 
            kyoko = data[i].fsec;
        dp[(i+1)%2][data[i].sec][max(yui,kyoko)] =
            max(dp[(i+1)%2][data[i].sec][max(yui,kyoko)], min(yui, kyoko));
    }

    int ans = 0;
    /*
    rep(i, n) {
        cout << "====" << i << "=====" << endl;
        rep(j, c+1) {
            rep(k, SCORE+1) {
                cout << dp[i][j][k] << " ";
            }
            cout << endl;
        }
    }
    */
    rep(i, c+1) {
        rep(j, SCORE+1) {
            //cout << dp[n][i][j] << " ";
            ans = max(ans, dp[n%2][i][j]);
        }
        //cout << endl;
    }
    cout << ans << endl;
    return 0;

}

