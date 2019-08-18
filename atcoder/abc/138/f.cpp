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

int dp[70][2][70];

string hoge(int n)
{
    string ret = "";
    while (n) {
        ret += (n % 2) ? '1' : '0';
        n /= 2;
    }
    reverse(all(ret));
    return ret;
}

int solve(string n)
{
    dp[0][1][0] = 1;
    cout << "n : " << n << endl;
    rep(i, n.size()) {
        for (int j = 0; j < 70; j++) {
            dp[i+1][0][j] = (dp[i+1][0][j] + dp[i][0][j]) % MOD;
            dp[i+1][0][j+1] = (dp[i+1][0][j+1] + dp[i][0][j]) % MOD;
            if (n[i]) {
                dp[i+1][0][j] = (dp[i+1][0][j] + dp[i][1][j]) % MOD;
                dp[i+1][1][j+1] = (dp[i+1][1][j+1] + dp[i][1][j]) % MOD;
            } else {
                dp[i+1][1][j] = (dp[i+1][1][j] + dp[i][1][j]) % MOD;
            }
        }
    }
    int ret = 0;
    rep(i, 70) {
        ret = (ret + dp[n.size()][0][i] * pow(2, i-1));
        ret = (ret + dp[n.size()][1][i] * pow(2, i-1));
    }
    return ret;
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int2(l, r);

    int ans = 0;
    ans = solve(hoge(r));
    cout << ans << endl;
    ans = (ans - solve(hoge(l-1)) + MOD) % MOD;
    cout << ans << endl;

    return 0;
}








