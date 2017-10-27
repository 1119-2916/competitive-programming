#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <stack>

using namespace std;

#define INF 1010001000
#define EPS 1e-10
#define rep(i, N) for (int i = 0; i < N; i++)
#define pb push_back

typedef pair<int, int> i_i;
typedef long long int llong;
typedef pair<llong, llong> ll_ll;
typedef struct edge {int f, t;}Edge;

vector<vector<bool> > check, cont;
vector<vector<char> > board;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int w, h;

bool bfs(int i, int j, char t);
int cnt(int i, int j);

int main()
{
    while (cin >> w >> h, w) {
        board.assign(h, vector<char>(w));
        check.assign(h, vector<bool>(w, false));
        cont.assign(h, vector<bool>(w, false));
        getchar();
        bool bl = false, wh = false;
        rep(i, h) {
            rep(j, w) {
                cin >> board[i][j];
                if (board[i][j] == 'W') {
                    wh = true;
                } else if (board[i][j] == 'B') {
                    bl = true;
                }
            }
            getchar();
        }
        if (!bl && ! wh) {
            cout << 0 << " " << 0 << endl;
            continue;
        }
        int white = 0, black = 0;
        rep(i, h) {
            rep(j, w) {
                if (!check[i][j] && board[i][j] == '.') {
                    if (bfs(i, j, 'W')) {
                        white += cnt(i, j);
                    }  
                }
            }
        }
        check.assign(h, vector<bool>(w, false));
        rep(i, h) {
            rep(j, w) {
                if (!check[i][j] && board[i][j] == '.') {
                    if (bfs(i, j, 'B')) {
                        black += cnt(i, j);
                    }  
                }
            }
        }
        cout << black << " " << white << endl;
    }
    return 0;
}


int cnt(int i, int j)
{
    int ret = 1;
    cont[i][j] = true;
    rep(k, 4) {
        int ni = i + dx[k], nj = j + dy[k];
        if (0 <= ni && ni < h && 0 <= nj && nj < w) {
            if (!cont[ni][nj] && board[ni][nj] == '.') {
                ret += cnt(ni, nj);
            }
        }
    }
    return ret;
}

bool bfs(int i, int j, char t)
{
    bool ret = true;
    check[i][j] = true;
    //cout << "(" << i << "," << j << ")" << " ";
    rep(k, 4) {
        int ni = i + dx[k], nj = j + dy[k];
        if (0 <= ni && ni < h && 0 <= nj && nj < w) {
            if (!check[ni][nj]) {
                if (board[ni][nj] == t) {
                    ret &= true;
                } else if (board[ni][nj] == '.') {
                    ret &= bfs(ni, nj, t);
                } else {
                    ret = false;
                }
            }
        }
    }
    return ret;
}

