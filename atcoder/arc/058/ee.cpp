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

string bitst(int a)
{
    string st;
    if (!a) return "0";
    while (a) {
        st.pb((a % 2) + '0');
        a /= 2;
    }
    reverse(all(st));
    return st;
}

int dp[41][11][11][11];

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    Int(n); int3(x, y, z);

    dp[0][0][0][0] = 1;

    rep(i, n) {
        rep(a, 11) {
            rep(b, 11) {
                rep(c, 11) {
                    if (dp[i][a][b][c]) {
                        Rep(j, 11) {
                            if (!(b == x && c == y && j == z)) {
                                dp[i+1][b][c][j] = (dp[i+1][b][c][j] + 
                                     dp[i][a][b][c]) % MOD;
                            }
                        }
                    }
                }
            }
        }
    }

    int ans = 1;
    rep(i, n) {
        ans = (ans * 10) % MOD;
    }
    rep(a, 11) 
        rep(b, 11) 
            rep(c, 11) 
                if (!(a == x && b == y && c == z))
                    ans = (ans - dp[n][a][b][c] + MOD) % MOD;
    cout << ans << endl;

    return 0;
}

