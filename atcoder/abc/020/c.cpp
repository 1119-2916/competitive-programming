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
 
int dxy[5] = {0, 1, 0, -1, 0};
// assign

int h, w, t, stx, sty, glx, gly;
string board[11];
int dp[11][11];

bool bfs(int ans);

signed main()
{
    cin >> h >> w >> t;
    rep(i, h) cin >> board[i];

    rep(i, h) {
        rep(j, w) {
            if (board[i][j] == 'S') {
                stx = i; sty = j;
            } else if (board[i][j] == 'G') {
                glx = i; gly = j;
            }
        }
    }

    int l = 0, r = t;
    while (r - l > 1) {
        int mid = (r + l) / 2;
        if (bfs(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }

    if (bfs(r)) {
        cout << r << endl;
    } else {
        cout << l << endl;
    }

    return 0;
}



bool bfs(int ans)
{
    //cout << ans << " ";
    queue< i_i > q;
    q.push(mp(stx, sty));
    memset(dp, MOD, sizeof(dp));
    dp[stx][sty] = 0;

    while (!q.empty()) {
        int x = q.front().first, y = q.front().second;
        q.pop();
        rep(i, 4) {
            int nx = x + dxy[i], ny = y + dxy[i+1];
            if (0 <= nx && nx < h && 0 <= ny && ny < w) {
                if (board[nx][ny] == '.' || 
                        board[nx][ny] == 'G') {
                    if (dp[nx][ny] > dp[x][y] + 1) {
                        dp[nx][ny] = dp[x][y] + 1;
                        q.push(mp(nx, ny));
                    }
                } else if (board[nx][ny] == '#') {
                    if (dp[nx][ny] > dp[x][y] + ans) {
                        dp[nx][ny] = dp[x][y] + ans;
                        q.push(mp(nx, ny));
                    }
                }
            }
        }
    }
    //cout << dp[glx][gly] << endl;

    if (dp[glx][gly] <= t) {
        return true;
    } else {
        return false;
    }
}

