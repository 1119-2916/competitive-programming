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
 
int dx[8] = {0, 1, 0, -1, 1, -1, 1, -1};
int dy[8] = {1, 0, -1, 0, 1, 1, -1, -1};
// assign

vector< string > board(8);

bool f(char a, char b);
bool g(char a, char b);
int search(int x, int y, char a, char b);
void turn(int x, int y, char a, char b);

signed main()
{
    rep(i, 8) {
        cin >> board[i];
    }
    while (1) {
        bool ret1 = f('o', 'x');
        bool ret2 = g('x', 'o');
        if (!ret1 && !ret2) {
            break;
        }
    }
    rep(i, 8) {
        cout << board[i] << endl;
    }
    return 0;
}

bool f(char a, char b)
{
    int getpoint = 0, x = -1, y = -1;
    rep(i, 8) {
        rep(j, 8) {
            int tmp = search(i, j, a, b);
            if (tmp > getpoint) {
                getpoint = tmp;
                x = i; y = j;
            }
        }
    }
    if (x == -1) {
        return false;
    } else {
        turn(x, y, a, b);
        return true;
    }
}

int search(int x, int y, char a, char b)
{
    int ret = 0;
    if (board[x][y] != '.' ) { return 0;}
    rep(i, 8) {
        int px = x, py = y, tmp = 0;
        while (0 <= px + dx[i] && px + dx[i] < 8 && 
                0 <= py + dy[i] && py + dy[i] < 8 && 
                board[px + dx[i]][py + dy[i]] == b) {
            tmp++;
            px += dx[i]; py += dy[i];
        }
        if (tmp && 0 <= px + dx[i] && px + dx[i] < 8 && 
                0 <= py + dy[i] && py + dy[i] < 8 && 
                board[px + dx[i]][py + dy[i]] == a) {
            ret += tmp;
        }
    }
    return ret;
}

void turn(int x, int y, char a, char b)
{
    board[x][y] = a;
    rep(i, 8) {
        int px = x, py = y;
        while (0 <= px + dx[i] && px + dx[i] < 8 && 
                0 <= py + dy[i] && py + dy[i] < 8 && 
                board[px + dx[i]][py + dy[i]] == b) {
            px += dx[i]; py += dy[i];
        }
        if (0 <= px + dx[i] && px + dx[i] < 8 && 
                0 <= py + dy[i] && py + dy[i] < 8 && 
                board[px + dx[i]][py + dy[i]] == a) {
            while (board[px][py] == b) {
                board[px][py] = a;
                px -= dx[i]; py -= dy[i];
            }
        }
    }
}

bool g(char a, char b)
{
    int getpoint = 0, x = -1, y = -1;
    for (int i = 7; i >= 0; i--) {
        for (int j = 7; j >= 0; j--) {
            int tmp = search(i, j, a, b);
            if (tmp > getpoint) {
                getpoint = tmp;
                x = i; y = j;
            }
        }
    }
    if (x == -1) {
        return false;
    } else {
        turn(x, y, a, b);
        return true;
    }
}
