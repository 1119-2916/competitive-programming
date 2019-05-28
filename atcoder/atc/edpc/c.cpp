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
    vector<int> a(n), b(n), c(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i] >> c[i];
    }

    //vvi dp(n, vi(3, 0));
    //vi = vector<int>
    // vvi = vector< vi >
    vector<vector<int>> dp(n+1, vector<int>(3, 0));

    rep(i, n) {
        dp[i+1][0] = max(dp[i+1][0], dp[i][1] + a[i]);
        dp[i+1][0] = max(dp[i+1][0], dp[i][2] + a[i]);
        dp[i+1][1] = max(dp[i+1][1], dp[i][0] + b[i]);
        dp[i+1][1] = max(dp[i+1][1], dp[i][2] + b[i]);
        dp[i+1][2] = max(dp[i+1][2], dp[i][0] + c[i]);
        dp[i+1][2] = max(dp[i+1][2], dp[i][1] + c[i]);
    }

    std::cout << max({dp[n][0], dp[n][1], dp[n][2]}) << std::endl;


    return 0;
}
