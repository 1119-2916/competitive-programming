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
#define eb emplace_back
#define mp make_pair
#define i_i pair<int, int>
#define vi vector<int>
#define vvi vector<vi >
#define vb vector<bool>
#define vvb vector<vb >
#define vp vector< i_i >
#define all(a) (a).begin(), (a).end()
#define Int(x) int x; cin >> x;
#define int2(x, y) Int(x); Int(y);
#define int3(x, y, z) Int(x); int2(y, z);
#define fir first
#define sec second
#define ffir first.first
#define fsec first.second
#define sfir second.first
#define ssec second.second
#define Decimal fixed << setprecision(10)

int dxy[5] = {0, 1, 0, -1, 0};
// // assign avl ncm dijkstra geo2 kruskal graph uf lca BIT
// matrix dinic next_combination topcoder lcm vi st gin
// cusum segtree

int N;
vvi board;

void mount_add(int x, int y, int h);
void mount_add_bfs(int x, int y, int h);

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    random_device rnd;
    std::mt19937 mt(rnd());

    N = 5;
    board.assign(N, vi(N, 0));
    rep(i, N) {
        rep(j, N) {
            cin >> board[i][j];
        }
    }

    // debug
    ///*
    Int(Q);
    rep(i, Q) {
        int3(a, b, c);
        mount_add(a, b, c);
        rep(i, N) { rep(j, N) cout << board[i][j] << " "; cout << endl; }
    }

    //*/
    /*
    cout << 1000 << endl;
    rep(i, 1000) {
        int x = mt() % N, y = mt() % N;
        cout << x << " " << y << " ";
        cout << min(max(board[x][y], 0LL), N) << endl;
        mount_add(x, y, min(max(board[x][y], 0LL), N));
    }
    */

    return 0;
}

vvb used;

void mount_add(int x, int y, int h)
{
    used.assign(N, vb(N, false));
    mount_add_bfs(x, y, h);
}

void mount_add_bfs(int x, int y, int h)
{
    queue<pair<int, i_i>> yui;
    yui.push({h, {x, y}});
    used[x][y] = true;
    board[x][y] -= h;
    while (yui.size()) {
        int nx = yui.front().sfir, ny = yui.front().ssec,
            num = yui.front().fir;
        yui.pop();
        //cout << "(" << nx << "," << ny << ") : " << num << endl;
        if (num) {
            rep(i, 4) {
                int nnx = nx + dxy[i], nny = ny + dxy[i+1];
                if (0 <= nnx && nnx < N && 0 <= nny && nny < N) {
                    if (!used[nnx][nny]) {
                        yui.push({num-1, {nnx, nny}});
                        used[nnx][nny] = true;
                        board[nnx][nny] -= num-1;
                    }
                }
            }
        }
    }
}

