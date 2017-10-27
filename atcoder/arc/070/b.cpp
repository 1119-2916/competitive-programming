#include <bits/stdc++.h>

using namespace std;

#define RMQ_SIZE 262144
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

bool dp[5003][5003];

signed main()
{
    int2(n, k);
    vi data(n);
    rep(i, n) cin >> data[i];

    sort(all(data));

    int l = 0, r = n;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        memset(dp, false, sizeof(dp));
        dp[0][0] = true;
        bool fl = false;
        rep(i, n) {
            if (i == mid) {
                rep(j, k) {
                    if(dp[i][j]) {
                        dp[i+1][j] = true;
                    }
                }
                continue;
            }
            //cout << data[i] << "--" ;
            rep(j, k) {
                    //cout << j + data[i] << " ";
                if (dp[i][j]) {
                    dp[i+1][j] = true;
                    //cout << j + data[i] << " ";
                    if (j + data[i] < k) {
                        dp[i+1][j+data[i]] = true;
                        if (k - data[mid] <= j + data[i]) {
                            //cout << j + data[i] << endl;
                            fl = true;
                            break;
                        }
                    }
                }
            }
            if (fl) break;
        }
        //cout << fl << endl;
        if (fl) {
            r = mid;
        } else {
            l = mid;
        }
    }
    //cout << data[l] << " " << data[r] << endl;
    //cout << l << " " << r << endl;

    int mid = l;
    memset(dp, false, sizeof(dp));
    dp[0][0] = true;
    bool fl = false;
    rep(i, n) {
        if (i == mid) {
                rep(j, k) {
                    if(dp[i][j]) {
                        dp[i+1][j] = true;
                    }
                }
            continue;
        }
        rep(j, k) {
            if (dp[i][j]) {
                dp[i+1][j] = true;
                if (j + data[i] < k) {
                    dp[i+1][j+data[i]] = true;
                    if (k - data[mid] <= j + data[i]) {
                        fl = true;
                        break;
                    }
                }
            }
        }
        if (fl) break;
    }
    //cout << fl << endl;
    if (fl) {
        int ans = 0;
        rep(i, l) {
            if (data[i] < k) {
                ans++;
            }
        }
        cout << ans << endl;
        //cout << l << endl;
    } else {
        int ans = 0;
        rep(i, r) {
            if (data[i] < k) {
                ans++;
            }
        }
        cout << ans << endl;
        //cout << r << endl;
    }


    return 0;
}

