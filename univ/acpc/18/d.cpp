#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < n; i++) 
#define pb emplace_back
#define vi vector<int>
#define in(a, b, c) a <= b && b < c

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
string com[4] = {"U", "R", "D", "L"};

string search(vector<string> &board, int x, int y)
{
    int px = 0, py = 0;
    string ret;
    while (1) {
        rep(i, 4) {
            int nx = x + dx[i], ny = y + ny[i];
            if (in(0, nx, board.size()) && in(0, ny, board[0].size()) && 
                    board[nx][ny] == '#') {
                x += dx[i]; y += dy[i];
                px += dx[i]; py += dy[i];
                ret += com[i];
            }
        }
        if (!px && !py




}


signed main()
{
    int n, m;
    vector<string> board(n);
    rep(i, n) cin >> board[i];
    vector<vi> check(n, vi(m, 0));

    vector<string> funami;

    rep(i, n) {
        rep(j, m) {
            if (board[i][j] == '#' && !check[i][j]) {
                funami.pb(search(board, i, j));
                paint(board, check, i, j);
            }
        }
    }




}


