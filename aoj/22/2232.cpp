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
#define int2(x, y) int x, y; scanf("%lld %lld", &x, &y);

int dxy[5] = {0, 1, 0, -1, 0};
// assign

bool solve(int x, int y, vector<string> board);
bool run(vector<string> board);
int h, w, n;

//rep(i, h) cout << board[i] << endl;

signed main()
{
    cin >> h >> w >> n;
    vector<string> board(h);
    rep(i, h) {
        cin >> board[i];
    }
    rep(i, h) {
        rep(j, w) {
            if (solve(i, j, board)) {
                cout << "YES" << endl;
                return 0;
            } 
        }
    }
    cout << "NO" << endl;
    return 0;
}

bool solve(int x, int y, vector<string> board)
{
    rep(i, 1) {
        if (x+dxy[i] < h && y + dxy[i+1] < w) {
            //if (board[x][y] != '.' && board[x+dxy[i]][y+dxy[i+1]] != '.') {
                char tmp = board[x+dxy[i]][y+dxy[i+1]];
                board[x+dxy[i]][y+dxy[i+1]] = board[x][y];
                board[x][y] = tmp;
                vector<string> board2;
                copy(all(board), back_inserter(board2));
                //cout << x << y << i << endl;
                if (run(board2)) {
                    return true;
                }
                tmp = board[x+dxy[i]][y+dxy[i+1]];
                board[x+dxy[i]][y+dxy[i+1]] = board[x][y];
                board[x][y] = tmp;
           // }
        }
    }
    return false;
}

bool run(vector<string> board)
{
    rep(i, w) {
        for (int j = h-1; j >= 0; j--) {
            if (board[j][i] != '.') {
                int pos = j;
                for (int k = j+1; k < h; k++) {
                    if (board[k][i] == '.') {
                        pos = k;
                    } else {
                        break;
                    }
                }
                char tmp = board[pos][i];
                board[pos][i] = board[j][i];
                board[j][i]= tmp;
            }
        }
    }
    bool flag = true;
    while (flag) {
        flag = false;
        vvb ch(h, vb(w, false));
        rep(i, w) {
            int x = 0, y = i, cnt = 1;
            char bef = board[x][y];
            while (x+1 < h) {
                if (board[x+1][y] == bef && bef != '.') {
                    cnt++;
                } else {
                    bef = board[x+1][y];
                    if (cnt >= n) {
                        int tmp = x;
                        rep(j, cnt) {
                            ch[tmp-j][y] = true;
                        }
                    }
                    cnt = 1;
                }
                x++;
            }
            if (cnt >= n) {
                int tmp = x;
                rep(j, cnt) {
                    ch[tmp-j][y] = true;
                }
            }
        }
        //cout << "height" << endl;
        rep(i, h) {
            int x = i, y = 0, cnt = 1;
            char bef = board[x][y];
            while (y+1 < w) {
                if (board[x][y+1] == bef && bef != '.') {
                    cnt++;
                } else {
                    bef = board[x][y+1];
                    if (cnt >= n) {
                        int tmp = y;
                        rep(j, cnt) {
                            ch[x][tmp-j] = true;
                        }
                    }
                    cnt = 1;
                }
                y++;
            }
            if (cnt >= n) {
                int tmp = y;
                rep(j, cnt) {
                    ch[x][tmp-j] = true;
                }
            }
        }
        //cout << "width" << endl;
        rep(i, h) {
            rep(j, w) {
                if (ch[i][j]) {
                    flag = true;
                    board[i][j] = '.';
                }
            }
        }
        //if (flag) { rep(i, h) cout << board[i] << endl; }
        //if (flag) { rep(i, h) cout << board[i] << endl; }
        rep(i, w) {
            for (int j = h-1; j >= 0; j--) {
                if (board[j][i] != '.') {
                    int pos = j;
                    for (int k = j+1; k < h; k++) {
                        if (board[k][i] == '.') {
                            pos = k;
                        } else {
                            break;
                        }
                    }
                    char tmp = board[pos][i];
                    board[pos][i] = board[j][i];
                    board[j][i]= tmp;
                }
            }
        }
        //if (flag) { rep(i, h) cout << board[i] << endl; }
    }
    rep(i, h) {
        rep(j, w) {
            if (board[i][j] != '.') {
                return false;
            }
        }
    }
    return true;
}
