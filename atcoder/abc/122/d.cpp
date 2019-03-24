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

int dp[200][5][5][5];

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    Int(n);

    dp[0][0][0][0] = 1;
    dp[1][0][0][0] = 1;
    dp[2][0][0][0] = 1;

    for (int i = 2; i < n + 2; i++) {
        for (int a = 0; a < 5; a++) {
            for (int b = 0; b < 5; b++) {
                for (int c = 0; c < 5; c++) {
                    for (int d = 1; d < 5; d++) {
                        if (b == 1 && c == 3 && d == 2) continue;
                        if (b == 1 && c == 2 && d == 3) continue;
                        if (b == 3 && c == 1 && d == 2) continue;
                        if (a == 1 && b == 3 && d == 2) continue;
                        if (a == 1 && c == 3 && d == 2) continue;
                        dp[i+1][b][c][d] = 
                            (dp[i+1][b][c][d] + dp[i][a][b][c]) % MOD;
                    }
                }
            }
        }
    }

    /*
    rep(i, n + 4) {
        rep(a, 5) {
            cout << "a : " << a << endl;
            rep(b, 5) {
            cout << "b : " << b << endl;
                rep(c, 5) {
                    std::cout << dp[i][a][b][c] << " ";
                }
                cout << endl;
            }
        }
    }
    */

    int ans = 0;
    rep(a, 5) rep(b, 5) rep(c, 5) 
        ans = (ans + dp[n+2][a][b][c]) % MOD;

    std::cout << ans << std::endl;

    return 0;
}
