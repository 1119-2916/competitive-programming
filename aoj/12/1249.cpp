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

//int dxy[5] = {0, 1, 0, -1, 0};
// assign

bool search(vector< vvi > &board, int m);
void push(vector< vvi > &board, int x, int y, int num);

signed main()
{
    Int(n);
    Int(m);
    Int(p);
    while (n) {
        vector< vvi > board(n, vvi(n, vi(n, 0)));
        bool fl = false;
        rep(i, p) {
            int a, b;
            cin >> a >> b;
            push(board, a-1, b-1, i%2 + 1);
            if (!fl && search(board, m)) {
                cout << ((i%2) ? "White " : "Black ") << i+1 << endl;
                fl = true;
            }
            // kuro = 1, shiro = 2, nashi = 0
        }
        if (!fl) {
            cout << "Draw" << endl;
        }
        cin >> n >> m >> p;
    }
    return 0;
}

void push(vector< vvi > &board, int x, int y, int num)
{
    rep(i, board.size()) {
        if (board[x][y][i]) {
            continue;
        } else {
            board[x][y][i] = num;
            break;
        }
    }
}

bool search(vector< vvi > &board, int m)
{
    int n = board.size(), ans = 0, num;
    int dx[13] = {1, 0, 0, 1, 0, 1, -1, 0, 1, 1, 1, 1, -1};
    int dy[13] = {0, 0, 1, 1, 1, 0, 1, -1, 0, 1, 1, -1, 1};
    int dz[13] = {0, 1, 0, 0, 1, 1, 0, 1, -1, 1, -1, 1, 1};

    rep(i, 13) {
        rep(j, n) {
            rep(k, n) {
                rep(l, n) {
                    int x = j, y = k, z = l;
                    num = board[x][y][z]; ans = 1;
                    x += dx[i]; y += dy[i]; z += dz[i];
                    while (0 <= x && x < n &&
                            0 <= y && y < n &&
                            0 <= z && z < n) {
                        if (board[x][y][z] == num) {
                            ans++;
                        } else {
                            ans = 1;
                            num = board[x][y][z];
                        }
                        if (ans >= m && num) {
                            return true;
                        }
                        x += dx[i]; y += dy[i]; z += dz[i];
                    }
                }
            }
        }
    }
    return false;
}

