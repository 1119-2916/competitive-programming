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
    vp data(n*2);
    int ans = 0;
    rep(i, n*2) {
        cin >> data[i].fir >> data[i].sec;
        if (data[i].sec <= 1) {
            ans += 1 - data[i].sec;
            data[i].sec = 1;
        } else {
            ans += data[i].sec - 2;
            data[i].sec = 2;
        }
    }

    sort(all(data));
/*
    rep(i, data.size()) {
        cout << data[i].fir << " " << data[i].sec << endl;
    }
*/
    vvi dp(n*2+1, vi(n*2+1, INF));
    //vvi dp(n*2+1, vi(n*2+1, 100));
    dp[0][0] = 0;
    rep(i, data.size()) {
        rep(j, i+1) {
            dp[j+1][i-j] = min(dp[j+1][i-j], 
                    dp[j][i-j] + abs((j+1) - data[i].fir) + 
                    abs(data[i].sec-2));
        }
        rep(j, i+1) {
            dp[i-j][j+1] = min(dp[i-j][j+1], 
                    dp[i-j][j] + abs((j+1) - data[i].fir) + 
                    abs(data[i].sec-1));
        }
/*
        rep(i, n*2+1) {
            rep(j, n*2+1) {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
*/
    }

    cout << dp[n][n] + ans << endl;

    return 0;
}



