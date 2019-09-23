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
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vi >
#define vb vector<bool>
#define vvb vector<vb >
#define vp vector< pii >
#define all(a) (a).begin(), (a).end()
#define Int(x) int x; cin >> x;
#define int2(x, y) Int(x); Int(y);
#define int3(x, y, z) Int(x); int2(y, z);
#define in(x, a, b) ((a) <= (x) && (x) < (b))
#define fir first
#define sec second
#define ffir first.first
#define fsec first.second
#define sfir second.first
#define ssec second.second
#define Decimal fixed << setprecision(10)

//int dxy[5] = {0, 1, 0, -1, 0};
// cmd

using Mino = vector<string>;

bool put(vector<string> &board, Mino &mino)
{
    int pos_i = -1, pos_j;
    rep(i, board.size()) {
        if (pos_i != -1) break;
        rep(j, board[i].size()) {
            if (board[i][j] == '.') {
                pos_i = i;
                pos_j = j;
                break;
            }
        }
    }
    int mino_i = -1, mino_j;
    rep(i, mino.size()) {
        if (mino_i != -1) break;
        rep(j, mino[i].size()) {
            if (mino[i][j] == '#') {
                mino_i = i;
                mino_j = j;
                break;
            }
        }
    }

    rep(i, mino.size()) {
        rep(j, mino[i].size()) {
            if (mino[i][j] == '#') {
                if (in(pos_i + i - mino_i, 0, board.size()) &&
                    in(pos_j + j - mino_j, 0, board[i].size()) &&
                        board[pos_i + i - mino_i][pos_j + j - mino_j] == '.') {
                    board[pos_i+i-mino_i][pos_j+j-mino_j] = 'k';
                } else {
                    return false;
                }
            }
        }
    }
    rep(i, board.size()) {
        rep(j, board[i].size()) {
            if (board[i][j] == 'k') board[i][j] = 'm';
        }
    }

    return true;
}

bool solve(vector<string> board, vector<Mino> &minos, vi &index)
{
    rep(i, index.size()) index[i] = i;
    vector<string> raw = board;
    bool ret = false;
    do {
        //rep(i, index.size()) cout << index[i] << " "; cout << endl;
        bool rret = true;
        board = raw;
        rep(i, 3) {
            rret &= put(board, minos[index[i]]);
        }
        /*
    rep(i, board.size()) {
        rep(j, board[i].size()) {
            cout << board[i][j];
        }
        cout << endl;
    }
    */
        if (rret) {
            ret = true;
            break;
        }
    } while (next_permutation(all(index)));
    
    rep(i, board.size()) {
        rep(j, board[i].size()) {
            ret &= board[i][j] != '.';
        }
    }
    return ret;
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int mino_n = 4;
    vector<Mino> minos(mino_n);
    rep(i, mino_n) {
        int2(a, b);
        Mino tmp;
        rep(j, a) {
            string t;
            cin >> t;
            tmp.push_back(t);
        }
        minos[i] = tmp;
    }

    Int(n);
    int board_x = 4;
    rep(_, n) {
        vector<string> board(board_x);
        vector<int> index(minos.size());
        rep(i, board_x) {
            cin >> board[i];
        }
        if (solve(board, minos, index)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    
    return 0;
}
