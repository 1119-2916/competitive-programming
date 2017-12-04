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
    int2(a, b);
    vvi dp(a, vi(b));
    vector<string> ans;
    rep(i, a) {
        rep(j, b) {
            cin >> dp[i][j];
        }
    }
    if (a <= b) {
        rep(i, a) {
            int tmp = INF;
            rep(j, b) {
                tmp = min(tmp, dp[i][j]);
            }
            if (tmp) {
                rep(j, tmp) {
                    ans.pb("row ");
                    ans[ans.size()-1] += to_string(i+1);
                }
                rep(j, b) {
                    dp[i][j] -= tmp;
                }
            }
        }
        rep(j, b) {
            int tmp = INF;
            rep(i, a) {
                tmp = min(tmp, dp[i][j]);
            }
            if (tmp) {
                rep(i, tmp) {
                    ans.pb("col ");
                    ans[ans.size()-1] += to_string(j+1);
                }
                rep(i, a) {
                    dp[i][j] -= tmp;
                }
            }
        }
    } else {
        rep(j, b) {
            int tmp = INF;
            rep(i, a) {
                tmp = min(tmp, dp[i][j]);
            }
            if (tmp) {
                rep(i, tmp) {
                    ans.pb("col ");
                    ans[ans.size()-1] += to_string(j+1);
                }
                rep(i, a) {
                    dp[i][j] -= tmp;
                }
            }
        }
        rep(i, a) {
            int tmp = INF;
            rep(j, b) {
                tmp = min(tmp, dp[i][j]);
            }
            if (tmp) {
                rep(j, tmp) {
                    ans.pb("row ");
                    ans[ans.size()-1] += to_string(i+1);
                }
                rep(j, b) {
                    dp[i][j] -= tmp;
                }
            }
        }
    }
    bool ret = true;
    rep(i, a) {
        rep(j, b) {
            if (dp[i][j]) ret = false;
        }
    }

    if (ret) {
        cout << ans.size() << endl;
        rep(i, ans.size()) {
            cout << ans[i] << endl;
        }
    } else {
        cout << -1 << endl;
    }


    return 0;
}

