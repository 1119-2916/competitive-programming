#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
#include <stack>
#include <cstdlib>
#include <string>
#include <set>
#include <map>

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
#define Edge pair< int, i_i >
#define all(a) (a).begin(), (a).end()
#define Int(x) int x; scanf("%lld", &x);
#define int2(x, y) int x, y; scanf("%lld %lld", &x, &y);
#define fir first
#define sec second
#define ffir first.first
#define fsec first.second
#define sfir second.first
#define ssec second.second
 
int dxy[5] = {0, 1, 0, -1, 0};
// assign

vvi board;

signed main()
{
    board = vvi(350, vi(350, INF));
    Int(m);
    rep(i, m) {
        int2(a, b);
        Int(ti);
        board[a][b] = min(board[a][b], ti);
        rep(k, 4) {
            int aa = a + dxy[k], bb = b + dxy[k+1];
            if (0 <= aa && 0 <= bb) {
                board[aa][bb] = min(board[aa][bb], ti);
            }
        }
    }
    /*
    rep(i, 5) {
        rep(j, 5) {
            if (board[i][j] == INF) {
                cout << 0;
            } else {
                cout << board[i][j];
            }
        }cout << endl;
    }*/

    int cnt = 0;
    vvb used(350, vb(350, false));
    queue<i_i> nxt, que, nul;
    que.push(i_i(0, 0));
    used[0][0] = true;
    while (!que.empty()) {
        cnt++;
        while (!que.empty()) {
            int x = que.front().fir, y = que.front().sec;
            que.pop();
            if (board[x][y] == INF) {
            //    cout << "(" << x << " "  << y << ")" << endl;
                cout << cnt-1 << endl;
                return 0;
            }
            rep(i, 4) {
                int ax = x + dxy[i], ay = y + dxy[i+1];
                if (0 <= ax && 0 <= ay && !used[ax][ay] && 
                        cnt < board[ax][ay]) {
                    nxt.push(i_i(ax, ay));
                    used[ax][ay] = true;
                }
            }
        }
        que = nxt;
        nxt = nul;
    }
    cout << -1 << endl;
    return 0;
}

