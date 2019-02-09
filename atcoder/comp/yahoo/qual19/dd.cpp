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
#define eb emplace_back
#define mp make_pair
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vi >
#define vb vector<bool>
#define vvb vector<vb >
#define vp vector< pii >
#define all(a) (a).begin(), (a).end()
#define Int(x) int x; cin >> x;
#define int2(x, y) Int(x); Int(y);
#define int3(x, y, z) Int(x); int2(y, z);
#define in(x, a, b) ((a) <= (x) && (x) < (b))
#define fir first
#define sec second
#define ffir first.first
#define fsec first.second
#define sfir second.first
#define ssec second.second
#define Decimal fixed << setprecision(10)

//int dxy[5] = {0, 1, 0, -1, 0};
// cmd

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    Int(n);
    vector<int> data(n);
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }

    int yui = INF;

    {
        vvi dp(data.size()+1, vi(4, INF));
        dp[0][0] = dp[0][1] = dp[0][2] = dp[0][3] = 0;

        rep(i, data.size()) {
            dp[i+1][0] = min(dp[i+1][0], dp[i][0] + data[i]);
            
            dp[i+1][1] = min(dp[i+1][1], dp[i][0] + (data[i] ? (data[i]-1) % 2 : 1));
            dp[i+1][1] = min(dp[i+1][1], dp[i][1] + (data[i] ? (data[i]-1) % 2 : 1));

            dp[i+1][2] = min(dp[i+1][2], dp[i][0] + (data[i] ? (data[i]) % 2 : 2));
            dp[i+1][2] = min(dp[i+1][2], dp[i][1] + (data[i] ? (data[i]) % 2 : 2));
            dp[i+1][2] = min(dp[i+1][2], dp[i][2] + (data[i] ? (data[i]) % 2 : 2));

            dp[i+1][3] = min(dp[i+1][3], dp[i][0] + data[i]);
            dp[i+1][3] = min(dp[i+1][3], dp[i][1] + data[i]);
            dp[i+1][3] = min(dp[i+1][3], dp[i][2] + data[i]);
            dp[i+1][3] = min(dp[i+1][3], dp[i][3] + data[i]);
        }
 /*   
        rep(i, data.size()+1) {
            rep(j, dp[i].size()) {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
   */ 
        yui = min({dp[data.size()][0], dp[data.size()][1], 
                dp[data.size()][2], dp[data.size()][3]});
    }

    //std::cout << "yui : " << yui << std::endl;

    reverse(all(data));

    {
        vvi dp(data.size()+1, vi(4, INF));
        dp[0][0] = dp[0][1] = dp[0][2] = dp[0][3] = 0;

        rep(i, data.size()) {
            dp[i+1][0] = min(dp[i+1][0], dp[i][0] + data[i]);

            dp[i+1][1] = min(dp[i+1][1], dp[i][0] + (data[i] ? (data[i]-1) % 2 : 1));
            dp[i+1][1] = min(dp[i+1][1], dp[i][1] + (data[i] ? (data[i]-1) % 2 : 1));
            //dp[i+1][1] = min(dp[i+1][1], dp[i][0] + (data[i]+1) % 2);
            //dp[i+1][1] = min(dp[i+1][1], dp[i][1] + (data[i]+1) % 2);
            
            dp[i+1][2] = min(dp[i+1][2], dp[i][0] + (data[i] ? (data[i]) % 2 : 2));
            dp[i+1][2] = min(dp[i+1][2], dp[i][1] + (data[i] ? (data[i]) % 2 : 2));
            dp[i+1][2] = min(dp[i+1][2], dp[i][2] + (data[i] ? (data[i]) % 2 : 2));

            dp[i+1][3] = min(dp[i+1][3], dp[i][0] + data[i]);
            dp[i+1][3] = min(dp[i+1][3], dp[i][1] + data[i]);
            dp[i+1][3] = min(dp[i+1][3], dp[i][2] + data[i]);
            dp[i+1][3] = min(dp[i+1][3], dp[i][3] + data[i]);
        }
    /*
        rep(i, data.size()+1) {
            rep(j, dp[i].size()) {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
    */
        yui = min({yui, dp[data.size()][0], dp[data.size()][1], 
                dp[data.size()][2], dp[data.size()][3]});
    }

//    rep(i, data.size()) cout << data[i] << " "; cout << endl;

    {
        vvi dp(data.size()+1, vi(5, INF));
        dp[0][0] = dp[0][1] = dp[0][2] = dp[0][3] = dp[0][4] = 0;

        rep(i, data.size()) {
            dp[i+1][0] = min(dp[i+1][0], dp[i][0] + data[i]);

            dp[i+1][1] = min(dp[i+1][1], dp[i][0] + (data[i] ? (data[i]) % 2 : 2));
            dp[i+1][1] = min(dp[i+1][1], dp[i][1] + (data[i] ? (data[i]) % 2 : 2));

            dp[i+1][2] = min(dp[i+1][2], dp[i][0] + (data[i] ? (data[i]-1) % 2 : 1));
            dp[i+1][2] = min(dp[i+1][2], dp[i][1] + (data[i] ? (data[i]-1) % 2 : 1));
            dp[i+1][2] = min(dp[i+1][2], dp[i][2] + (data[i] ? (data[i]-1) % 2 : 1));
            
            dp[i+1][3] = min(dp[i+1][3], dp[i][0] + (data[i] ? (data[i]) % 2 : 2));
            dp[i+1][3] = min(dp[i+1][3], dp[i][1] + (data[i] ? (data[i]) % 2 : 2));
            dp[i+1][3] = min(dp[i+1][3], dp[i][2] + (data[i] ? (data[i]) % 2 : 2));
            dp[i+1][3] = min(dp[i+1][3], dp[i][3] + (data[i] ? (data[i]) % 2 : 2));

            dp[i+1][4] = min(dp[i+1][4], dp[i][0] + data[i]);
            dp[i+1][4] = min(dp[i+1][4], dp[i][1] + data[i]);
            dp[i+1][4] = min(dp[i+1][4], dp[i][2] + data[i]);
            dp[i+1][4] = min(dp[i+1][4], dp[i][3] + data[i]);
            dp[i+1][4] = min(dp[i+1][4], dp[i][4] + data[i]);
        }
 /*   
        rep(i, data.size()+1) {
            rep(j, dp[i].size()) {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
*/
        yui = min({yui, dp[data.size()][0], dp[data.size()][1], 
                dp[data.size()][2], dp[data.size()][3], dp[data.size()][4]});
    }

    std::cout << yui << std::endl;

    return 0;
}
