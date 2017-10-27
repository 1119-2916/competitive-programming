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
 
int dxy[5] = {0, -1, 0, 1, 0};
// assign

string board[50];
bool used[50][50];
vector< i_i > ans;
int h, w, k;
int piece;

void bfs(int x, int y);

signed main()
{
    cin >> h >> w >> k;
    memset(used, false, sizeof(used));
    rep(i, h) {
        cin >> board[i];
        for (int j = 0; j < 50; j++) {
            if (board[i][j] == '0' || 
                    board[i][j] == '1' ||
                    board[i][j] == '2' || 
                    board[i][j] == '3') {
                used[i][j] = true;
            }
        }
    }
    piece = 0;
    for (int i = 1; i < 49; i++) {
        for (int j = 1; j < 49; j++) {
            if (!used[i][j]) {
                bfs(i, j);
            }
        }
    }

    cout << piece << endl;
    for (i_i tmp : ans) {
        cout << tmp.first +1<< " " << tmp.second +1<< endl;
    }
    return 0;
}

void bfs(int x, int y)
{
    int nx = x, ny = y;
    vector< i_i > a;
    queue< i_i > s;

    for (int i = 0; i < 4; i++) {
        nx = x + dxy[i];
        ny = y + dxy[i+1];
        if (0 <= nx && nx < h &&
                0 <= ny && ny < w && 
                !used[nx][ny]) {
            a.pb(i_i(nx, ny));
            used[nx][ny] = true;
            s.push(i_i(nx, ny));
        }
    }

    while (a.size() < 8 && !s.empty()) {
        nx = s.front().first;
        ny = s.front().second;
        s.pop();
        for (int i = 0; i < 4; i++) {
            int nnx = nx + dxy[i];
            int nny = ny + dxy[i+1];
            if (0 <= nnx && nnx < h &&
                    0 <= nny && nny < w && 
                    !used[nnx][nny]) {
                a.pb(i_i(nnx, nny));
                used[nnx][nny] = true;
                s.push(i_i(nnx, nny));
            }
            if (a.size() == 8) {
                break;
            }
        }
    }


    if (a.size() == 8) {
        piece++;
        for (i_i tmp : a) {
            ans.pb(tmp);
        }
    }

}

