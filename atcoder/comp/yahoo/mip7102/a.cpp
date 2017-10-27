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
    string s;
    cin >> s;

    int dp[s.size()+1][5];
    fill(dp[0], dp[s.size()+1], INF);

    string y = "yahoo";

    rep(i, 5) dp[0][i] = i+1;
    dp[0][4] = 0;
    //rep(i, s.size()) dp[i][0] = i;

    Rep(i, s.size()+1) {
        rep(j, 5) {
            int tmp = ((s[i-1] == y[j]) ? 0:1);
            dp[i][j] = min(dp[i-1][(j + 4) % 5] + tmp,
                    min(dp[i-1][j]+1, dp[i][(j+4)%5]+1));
        }
        rep(j, 5) {
            int tmp = ((s[i-1] == y[j]) ? 0:1);
            dp[i][j] = min(dp[i-1][(j + 4) % 5] + tmp,
                    min(dp[i-1][j]+1, dp[i][(j+4)%5]+1));
        }
    }
/*
    rep(i, s.size()+1) {
        rep(j, 5) {
            cout << dp[i][j] << " ";
        }cout << endl;
    }
    */

    cout << dp[s.size()][4] << endl;



    return 0;
}

