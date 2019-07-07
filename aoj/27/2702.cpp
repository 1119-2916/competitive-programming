#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < n; i++) 
#define vi vector<int>
#define in(a, b, x) ((a <= x) && (x < b))
#define pii pair<int, int>

vector<vi> tate, yoko, kabe, nabe;
int h, w, r, c;
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

bool movable(const int x, const int y, const int dir, const bool kabenabe)
{
    if (dir == 0) {
        return yoko[x][y] != kabenabe;
    } else if (dir == 1) {
        return tate[x][y+1] != kabenabe;
    } else if (dir == 2) {
        return yoko[x+1][y] != kabenabe;
    } else if (dir == 3) {
        return tate[x][y] != kabenabe;
    } else {
        assert(0);
        return false;
    }
}

bool win_move(const int x, const int y, const int dir, const bool kabenabe)
{
    int nx = x + dx[dir], ny = y + dy[dir];
    //cout << "call : " << x << ", " << y << ", " << dir << " : ";
    //cout << in(0, h, nx) << ", " << in(0, w, ny) << ", " <<  movable(x, y, dir, kabenabe) << endl;
    if ( !(in(0, h, nx) && in(0, w, ny)) && movable(x, y, dir, kabenabe) ) {
        return true;
    } else {
        if (kabenabe) {
            return (in(0, h, nx) && in(0, w, ny)) && movable(x, y, dir, kabenabe) && kabe[nx][ny] == 1;
        } else {
            return (in(0, h, nx) && in(0, w, ny)) && movable(x, y, dir, kabenabe) && nabe[nx][ny] == 1;
        }
        //return false;
    }
}

void kinbo_push(queue<pii> &data, int x, int y)
{
    rep(i, 4) {
        int nx = x + dx[i], ny = y + dy[i];
        //if (in(0, h, nx) && in(0, w, ny)) {
        if (in(0, h, nx) && in(0, w, ny) && !kabe[nx][ny]) {
            data.push({nx, ny});
        }
    }
}

bool is_win_cell(int x, int y)
{
    bool kabe_fl = false, nabe_fl = false;
    rep(i, 4) {
        kabe_fl |= win_move(x, y, i, true);
        nabe_fl |= win_move(x, y, i, false);
    }
    return kabe_fl && nabe_fl;
}

bool is_deadcell(const int x, const int y)
{
    int cnt = 0;
    rep(i, 4) {
        cnt += movable(x, y, i, true);
    }
    return cnt == 0 || cnt == 4;
}

void bfs(queue<pii> &que)
{
    while (!que.empty()) {
        //cout << que.size() << endl;
        pii tmp = que.front(); que.pop();
        if (is_win_cell(tmp.first, tmp.second)) {
            kabe[tmp.first][tmp.second] = nabe[tmp.first][tmp.second] = 1;
            kinbo_push(que, tmp.first, tmp.second);
        }
    }
}

int main()
{
    while (cin >> h >> w >> r >> c, h) {
        yoko.assign(h+1, vi(w, 0));
        tate.assign(h, vi(w+1, 0));
        kabe.assign(h, vi(w, 0));
        nabe.assign(h, vi(w, 0));
        r--; c--;
        rep(i, h) {
            rep(j, w) {
                cin >> yoko[i][j];
            }
            rep(j, w+1) {
                cin >> tate[i][j];
            }
        }
        rep(j, w) {
            cin >> yoko[h][j];
        }

        bool fl = false;
        rep(i, 4) {
            if (win_move(r, c, i, true)) {
                cout << "Yes" << endl;
                fl = true;
                break;
            }
        }
        if (fl) {
            continue;
        }

        rep(i, h) {
            rep(j, w) {
                if (is_deadcell(i, j)) {
                    kabe[i][j] = nabe[i][j] = -1;
                }
            }
        }
        kabe[r][c] = nabe[r][c] = 0;
    /*
        rep(i, h) {
            rep(j, w) {
                cout << kabe[i][j];
            } cout << endl;
        }
    */
        queue<pii> que;
        /*
        if (is_win_cell(0, 0)) {
            kabe[0][0] = nabe[0][0] = 1;
            kinbo_push(que, 0, 0);
        }
        if (is_win_cell(h-1, 0)) {
            kabe[h-1][0] = nabe[h-1][0] = 1;
            kinbo_push(que, h-1, 0);
        }
        if (is_win_cell(0, w-1)) {
            kabe[0][w-1] = nabe[0][w-1] = 1;
            kinbo_push(que, 0, w-1);
        }
        if (is_win_cell(h-1, w-1)) {
            kabe[h-1][w-1] = nabe[h-1][w-1] = 1;
            kinbo_push(que, h-1, w-1);
        }
        */
        rep(i, h) {
            rep(j, w) {
                if (is_win_cell(i, j)) {
                    kabe[i][j] = nabe[i][j] = 1;
                    kinbo_push(que, i, j);
                }
            }
        }
    /*
        rep(i, h) {
            rep(j, w) {
                cout << kabe[i][j];
            } cout << endl;
        }
    */
        bfs(que);
        if (kabe[r][c]) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}


