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

int dp[20][2][2][2]; // keta fl 4 9

void solve(string data)
{
    rep(i, data.size()) rep(j, 2) rep(k, 2) rep(l, 2) {
        int lim = j ? 9 : data[i] - '0';
        rep(m, lim+1) {
            dp[i+1][j || m < lim][k || m == 4][l || m == 9] +=
                dp[i][j][k][l];
        }
    }
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int2(a, b);
    a--;
    string aa = to_string(a), bb = to_string(b);

    memset(dp, 0, sizeof(dp));
    dp[0][0][0][0] = 1;
    solve(aa);
    int ans_a = dp[aa.length()][0][1][0] + dp[aa.length()][0][0][1] +
                dp[aa.length()][0][1][1] + dp[aa.length()][1][1][0] + 
                dp[aa.length()][1][0][1] + dp[aa.length()][1][1][1];
    memset(dp, 0, sizeof(dp));
    dp[0][0][0][0] = 1;
    solve(bb);
    int ans_b = dp[bb.length()][0][1][0] + dp[bb.length()][0][0][1] +
                dp[bb.length()][0][1][1] + dp[bb.length()][1][1][0] + 
                dp[bb.length()][1][0][1] + dp[bb.length()][1][1][1];
    cout << ans_b - ans_a << endl;

    return 0;
}
