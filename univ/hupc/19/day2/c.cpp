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

int x, y, z;
int dp[100][100][100];

int solve(int a, int b, int c)
{
    cout << "call : " << a << " " << b << " " << c << endl;
    if (a == 0 && b == 0 && c == 0) return -1;
    if (dp[a][b][c] != 0) return dp[a][b][c];

    int ret = -1;
    if (a-1 >= 0 && b-z >= 0 && c-z >= 0 &&
            solve(a - 1, b - z, c - z) == -1) {
        ret = 1;
    }
    if (a-y >= 0 && b-y >= 0 && c-1 >= 0 &&
            solve(a - y, b - y, c - 1) == -1) {
        ret = 1;
    }
    if (a-x >= 0 && b-1 >= 0 && c-x >= 0 &&
            solve(a - x, b - 1, c - x) == -1) {
        ret = 1;
    }
    
    if (a-1 >= 0  && c-z >= 0 &&
            solve(a - 1, b, c - z) == -1) {
        ret = 1;
    }
    if (b-y >= 0 && c-1 >= 0 &&
            solve(a, b - y, c - 1) == -1) {
        ret = 1;
    }
    if (a-x >= 0 && b-1 >= 0 &&
            solve(a - x, b - 1, c) == -1) {
        ret = 1;
    }

    if (a-1 >= 0 && b-z >= 0 &&
            solve(a - 1, b - z, c) == -1) {
        ret = 1;
    }
    if (a-y >= 0 && c-1 >= 0 &&
            solve(a - y, b, c - 1) == -1) {
        ret = 1;
    }
    if (b-1 >= 0 && c-x >= 0 &&
            solve(a, b - 1, c - x) == -1) {
        ret = 1;
    }


    return dp[a][b][c] = ret;
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    cin >> x >> y >> z;

    solve(x*y, y*z, x*z);


    rep(i, x*y+1) {
        rep(j, y*z+1) {
            rep(k, x*z+1) {
                if (dp[i][j][k]) {
                    cout << i << " " << j << " " << k <<
                         " : " << dp[i][j][k] << endl;
                }
            }
        }
    }
    /*
    rep(i, x*y+1) {
        cout << "=========== " << i << " ==========" << endl;
        rep(j, y*z+1) {
            rep(k, x*z+1) {
                cout << dp[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    */


    return 0;
}
