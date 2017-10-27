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

string board[501];
int sum[501][501];
int r, c, k;

int solve(int a, int b);
 
signed main()
{
    cin >> r >> c >> k;

    rep(i, r) {
        cin >> board[i];
    }


    rep(i, c) {
        int tmp = 0;
        rep(j, r) {
            if (board[j][i] == 'o') {
                sum[j][i] = ++tmp;
            } else {
                sum[j][i] = tmp = 0;
            }
        }
    }

    int ans = 0;
    for (int i = k-1; i <= r-k; i++) {
        for (int j = k-1; j <= c-k; j++) {
            //cout << "(" << i << j << ")" << endl;
            ans += solve(i, j);
        }
    }
    cout << ans << endl;


    return 0;
}

int solve(int a, int b)
{
    for (int i = 1; i <= k; i++) {
        if (sum[i - 1 + a][b - k + i] >= i * 2 - 1) {
            //cout << i - 1 + a << " " << b - k + i << endl;
            ;
        } else {
            return 0;
        }
    }
    for (int i = 1; i <= k; i++) {
        if (sum[a + k - i - 1][b + i] >= (k - i) * 2 - 1) {
            //cout << a + k - i - 1 << " " << b + i << endl;
            ;
        } else {
            return 0;
        }
    }
    //cout << a << " " << b << endl;
    return 1;
}



