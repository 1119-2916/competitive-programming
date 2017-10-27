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

int n = 3;
int b[2][3], c[3][2];

int calc(vvi &state)
{
    int ret = 0;
    rep(i, n-1) {
        rep(j, n) {
            if (state[i][j] == state[i+1][j]) {
                ret += b[i][j];
            }
        }
    }
    rep(i, n) {
        rep(j, n-1) {
            if (state[i][j] == state[i][j+1]) {
                ret += c[i][j];
            }
        }
    }
    return ret;
}

int solve(vvi state, int t)
{
    if (t == 9) return calc(state);
    int ret = (t % 2) ? INF : 0;
    rep(i, n) {
        rep(j, n) {
            if (!state[i][j]) {
                state[i][j] = (t % 2) + 1;
                ret = (t % 2) ? min(ret, solve(state, t+1))
                        : max(ret, solve(state, t+1));
                state[i][j] = 0;
            }
        }
    }
    return ret;
}

signed main()
{
    int sum = 0;
    rep(i, n-1) {
        rep(j, n) {
            cin >> b[i][j];
            sum += b[i][j];
        }
    }

    rep(i, n) {
        rep(j, n-1) {
            cin >> c[i][j];
            sum += c[i][j];
        }
    }

    vvi state(n, vi(n, 0));
    int ans = solve(state, 0);

    cout << ans << endl;
    cout << sum - ans << endl;

    return 0;
}

