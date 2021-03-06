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
    while (a) {
        a++; b++;
        vvi dp(a, vi(b, 0));
        Rep(i, a) {
            string st;
            cin >> st;
            rep(j, st.size()) {
                if (st[j] == '*') {
                    dp[i][j+1]++;
                }
            }
        }
        Rep(i, a) {
            Rep(j, b) {
                dp[i][j] += dp[i][j-1];
            }
        }
        Rep(j, b) {
            Rep(i, a) {
                dp[i][j] += dp[i-1][j];
            }
        }

        int ans = 0;
        Rep(st, a) {
            rep(sz, (a-st)) {
                int l = 1, r = 1;
                while (r < b) {
                    int tmp = 0;
                    tmp = dp[st+sz][r] - dp[st+sz][l-1] - dp[st-1][r]
                        + dp[st-1][l-1];
                    while (r < b && !tmp) {
                        ans = max(ans, ((r - l + 1) * (sz+1)));
                        r++;
                        tmp = dp[st+sz][r] - dp[st+sz][l-1]
                            - dp[st-1][r] + dp[st-1][l-1];
                    }
                    l = ++r;
                }
            }
        }

        cout << ans << endl;
        cin >> a >> b;
    }

    return 0;
}

