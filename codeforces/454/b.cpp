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

//int dxy[5] = {0, 1, 0, -1, 0};
// cmd

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    vector<vector<string>> board(9, vector<string>(0));
    rep(i, 9) {
        rep(j, 3) {
            string st;
            cin >> st;
            board[(i / 3) * 3 + j].pb(st);
        }
    }
    int2(a, b); a--; b--;

    int pos = (a % 3) * 3 + b % 3, aa = a % 3, bb = b % 3,
        cnt = 0;

    rep(i, board[pos].size()) {
        rep(j, board[pos][i].size()) {
            if (board[pos][i][j] == '.') {
                board[pos][i][j] = '!';
                cnt++;
            }
        }
    }
    if (!cnt) {
        rep(i, board.size()) {
            rep(j, board[i].size()) {
                rep(k, board[i][j].size()) {
                    if (board[i][j][k] == '.') {
                        board[i][j][k] = '!';
                    }
                }
            }
        }
    }

    rep(i, 9) {
        rep(j, 3) {
            cout << board[(i / 3) * 3 + j][i % 3] << " ";
        }
        cout << endl;
        if ((i + 1) % 3 == 0) cout << endl;
    }



            
    return 0;
}
