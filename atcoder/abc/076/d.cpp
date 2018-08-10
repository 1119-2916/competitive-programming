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

double dp[20002][102];
int yui[20002][102];
int n;

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    cin >> n;
    vector<int> time(n);
    for (int i = 0; i < n; i++) {
        Int(tmp);
        if (i) time[i] = time[i-1] + tmp;
        else time[i] = tmp;
    }
    vector<int> fast(n);
    for (int i = 0; i < n; i++) {
        cin >> fast[i];
    }

    yui[0][0] = 1;

    int ptr = 0;
    rep(i, time.back()) {
        if (i == time[ptr]) ptr++;
        rep(j, fast[ptr]+1) {
            if (yui[i][j]) {
                if (j < fast[ptr]) {
                    dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j] + 0.5 + (double)j);
                    dp[i+1][j] = max(dp[i+1][j], dp[i][j] + 0.25 + (double)j);
                    yui[i+1][j+1] = 1;
                }
                dp[i+1][j] = max(dp[i+1][j], dp[i][j] + (double)j);
                yui[i+1][j] = 1;
                if (j >= 1) {
                    dp[i+1][j-1] = max(dp[i+1][j-1], dp[i][j] + ((double)j - 0.5));
                    yui[i+1][j-1] = 1;
                }
            }
        }
    }

    cout << Decimal << dp[time.back()][0] << endl;

    return 0;
}
