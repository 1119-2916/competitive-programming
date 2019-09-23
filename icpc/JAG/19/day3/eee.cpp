#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < n; i++)
#define vi vector<int>
#define all(x) (x).begin(), (x).end()

#define INF 1010001000

int dp[2][62][62][4000];

signed main()
{
    int nn, kk;
    cin >> nn >> kk;
    vi data(nn);
    rep(i, nn) {
        cin >> data[i];
    }
    vi red(kk), black(kk);
    int RED = 0, BLACK = 0;
    rep(i, kk) {
        cin >> red[i];
        RED += red[i];
    }
    rep(i, kk) {
        cin >> black[i];
        BLACK += black[i];
    }
    sort(all(data));
    reverse(all(data));
    sort(all(red));
    reverse(all(red));
    sort(all(black));
    reverse(all(black));
    vi ruiseki(nn+1, 0);
    rep(i, nn) {
        ruiseki[i+1] = ruiseki[i] + data[i];
    }

    //cout << "hoge " << endl;

    rep(i, 2) {
        rep(j, kk+1) {
            rep(k, kk+1) {
                rep(l, RED+1) {
                    dp[i][j][k][l] = INF;
                }
            }
        }
    }
    dp[0][0][0][0] = 0;

    //cout << "hoge " << endl;

    rep(i, data.size()) {
        rep(j, kk+1) {
            rep(k, kk+1) {
                rep(l, RED+1) {
                    dp[(i+1)%2][j][k][l] = INF;
                }
            }
        }
        rep(j, kk+1) {
            rep(k, kk+1) {
                rep(l, RED+1) {
                    if (j != kk && l + data[i] <= RED) {
                        dp[(i+1)%2][j+1][k][l + data[i]] = 
                            min(dp[(i+1)%2][j+1][k][l + data[i]], 
                                    dp[i%2][j][k][l] + max(0, data[i] - red[j]));
                    }
                    if (k != kk && max(0, ruiseki[i] - l) + data[i] <= BLACK) {
                        dp[(i+1)%2][j][k+1][l] = 
                            min(dp[(i+1)%2][j][k+1][l], 
                                    dp[i%2][j][k][l] + max(0, data[i] - black[k]));
                    }
                }
            }
        }
    }
    //cout << "hoge " << endl;

    int ans = INF;
    rep(j, kk+1) {
        rep(k, kk+1) {
            rep(l, RED+1) {
                ans = min(ans, dp[nn % 2][j][k][l]);
            }
        }
    }
    if (ans == INF) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }
    return 0;
}

