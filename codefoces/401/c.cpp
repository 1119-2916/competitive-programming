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
 
signed main()
{
    int2(n, m);
    vvi input(n, vi(m, 0));
    vvi board(n, vi(m));
    rep(i, n) {
        rep(j, m) {
            cin >> board[i][j];
        }
    }
    rep(i, m) {
        Rep(j, n) {
            if (board[j-1][i] > board[j][i]) {
                input[j][i] = 1;
            }
        }
    }
    vi ans(n, 0);
    rep(i, m) {
        int st = 0;
        Rep(j, n) {
            input[j][i] += input[j-1][i];
            if (input[st][i] == input[j][i]) {
                ans[st] = max(ans[st], j);
            } else {
                st = j;
            }
        }
    }
    Rep(i, n) {
        if (ans[i] < i) {
            ans[i] = i;
        }
        if (ans[i-1] > ans[i]) {
            ans[i] = ans[i-1];
        }
    }
    Int(k);
    rep(i, k) {
        int2(a, b);
        a--; b--;
        if (ans[a] >= b) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}

