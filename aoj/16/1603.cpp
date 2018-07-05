#include <bits/stdc++.h>

using namespace std;

#define INF 1001000100010001000
#define INF7f 9187201950435737471
#define MOD 1000000007
#define EPS 1e-10
#define int long long
#define rep(i, N) for (int i = 0; i < N; i++)
#define Rep(i, N) for (int i = 1; i < N; i++)
#define For(i, a, b) for (int i = (a); i < (b); i++)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define i_i pair<int, int>
#define vi vector<int>
#define vvi vector<vi >
#define vb vector<bool>
#define vvb vector<vb >
#define vp vector< i_i >
#define all(a) (a).begin(), (a).end()
#define Int(x) int x; cin >> x;
#define int2(x, y) Int(x); Int(y);
#define int3(x, y, z) Int(x); int2(y, z);
#define fir first
#define sec second
#define ffir first.first
#define fsec first.second
#define sfir second.first
#define ssec second.second
#define Decimal fixed << setprecision(10)

//int dxy[5] = {0, 1, 0, -1, 0};
// cmd

int dp[102][50000];
int data[100];
int n;

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    cin >> n;
    while (n) {
        rep(i, n) cin >> data[i];
        memset(dp, 0x7f, sizeof(dp));
        dp[0][0] = 0;
        
        rep(i, n) {
            for (int j = 100; j >= 0; j--) {
                for (int k = 50000-1; k >= 0; k--) {
                    if (dp[j][k] != INF7f) {
                        if (data[i] % 1000 == 0) {
                            if (k >= 500) {
                                dp[j+1][k-500] = min(dp[j+1][k-500], 
                                        dp[j][k] + data[i]);
                            }
                        } else if (data[i] % 1000 <= 500) {
                            int ret = 1000 - (data[i] % 1000);
                            dp[j+1][k+(ret-500)] = min(dp[j+1][k+(ret-500)],
                                    dp[j][k] + data[i]);
                        } else {
                            int ret = 1000 - (data[i] % 1000);
                            if (k >= 500 - ret) {
                                dp[j+1][k - (500 - ret)] = min(dp[j+1][k - (500 - ret)],
                                        dp[j][k] + data[i]);
                            }
                            dp[j][k + ret] = min(dp[j][k+ret], dp[j][k] + data[i]);
                        }
                        //cout << "call : " << i << " " << j << " " << k << endl;
                    }
                }
            }
        }
        int ans = INF7f;
        for (int i = 101; i >= 0; i--) {
            rep(j, 50000) {
                ans = min(ans, dp[i][j]);
            }
            if (ans != INF7f) {
                cout << i << " " << ans << endl;
                break;
            }
        }
        cin >> n;
    }

    return 0;
}


