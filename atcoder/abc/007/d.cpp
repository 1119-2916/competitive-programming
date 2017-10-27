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

int solve(int a);

signed main()
{
    int2(a, b);
    a--;
    int n1 = solve(a);
    int n2 = solve(b);

    cout << n2 - n1 << endl;

    return 0;
}


int solve(int a)
{
    string s = to_string(a);
    int dp[20][2][2];
    memset(dp, 0, sizeof dp);

    dp[0][0][0] = 1;

    rep(i, s.size()) {
        rep(j, 2) {     // 非確定, 確定
            rep(k, 2) { // 含まない, 含む
                int cnt = (j) ? 10 : s[i] - '0' + 1;
                rep(l, cnt) {
                    dp[ i + 1 ][ j || l != cnt-1 ][ k || l == 4 || l == 9 ]
                        += dp[i][j][k];
                }
            }
        }
    }

    int ret = 0;
    rep(i, 2) ret += dp[s.size()][i][1];

    return ret;
}

