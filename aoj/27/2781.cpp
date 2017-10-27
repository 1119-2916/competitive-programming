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
#define mp make_pair
#define i_i pair<int, int>
#define vi vector<int>
#define vvi vector<vi >
#define vb vector<bool>
#define vvb vector<vb >
#define vp vector< i_i >
#define all(a) (a).begin(), (a).end()
#define Int(x) int x; scanf("%lld", &x);
 
int dxy[5] = {0, 1, 0, -1, 0};
// assign

vector <string> board;
vvb used;
int x, y;

bool solve(int a, int b);

signed main()
{
    cin >> x >> y;
    board.assign(x, "");

    rep(i, x) {
        cin >> board[i];
    }

    bool ret;
    rep(i, x) {
        rep(j, y) {
            if (board[i][j] == '%') {
                ret = solve(i, j);
            }
        }
    }

    cout << ( (ret) ? "Yes" : "No" ) << endl;

    return 0;
}

bool solve(int a, int b)
{
    queue< i_i > q;
    q.push(i_i(a, b));
    used.assign(x, vb(y, false));
    used[a][b] = true;
    bool ret = true, stop = false;

    while (!q.empty()) {
        queue <i_i> nxt;
        while (!q.empty()) {
            int c = q.front().first, d = q.front().second;
            q.pop();
            rep(i, 4) {
                int nx = c + dxy[i], ny = d + dxy[i+1];
                if (nx < 0 || ny < 0 || x <= nx || y <= ny
                        || used[nx][ny] ) {
                    continue;
                }
                if (board[nx][ny] == '.') {
                    nxt.push(i_i(nx, ny));
                } else if (board[nx][ny] == '$') {
                    ret = false;
                    stop = true;
                } else if (board[nx][ny] == '@') {
                    stop = true;
                } 
                used[nx][ny] = true;
            }
        }
        if (stop) { return ret; }
        q = nxt;
    }
    return false;
}


