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
int score(char ban[50][50]);
void drop(char ban[50][50]);
void print_drop_board();

char drop_board[50][50];

signed main()
{
    char board[50][50], erase_board[50][50];
    auto start = chrono::system_clock::now();
    //map< i_i, i_i > place;
    rep(i, 50) {
        rep(j, 50) {
            board[i][j] = getchar();
            //erase_board[i][j] = 0;
        }
        getchar();
    }
    /*
    int a = 0, b = 0;
    rep(j, 50) {
        b = j; a = 0;
        for (int i = 49; i >= 0; i--) {
            if (board[i][j] != '.') {
                erase_board[a][b] = board[i][j];
                place.insert(mp(i_i(i, j), i_i(a, b)));
                a++;
            }
        }
    }

    rep(i, 50) {
        rep(j, 50) {
            if (erase_board[i][j] == 'o' || 
                    erase_board[i][j] == 'x') {
                cout << erase_board[i][j];
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }
*/
    auto input_time = chrono::system_clock::now() - start;
    auto input_msec = 
        chrono::duration_cast<chrono::milliseconds>(input_time).count();

    //cout << "input::" << input_msec << endl;

    while (1) {
        auto before_search = chrono::system_clock::now();
        int max_score(score(erase_board));
        int max_x = 0, max_y = 0;
        //cout << max_score << endl;
        rep(j, 50) {
            for (int i = 49; i > 0; i--) {
                if (board[i][j] == '.') {
                    board[i][j] = '+';
                    drop(board);
                    //print_drop_board();
                    int tmp_score = score(drop_board);
                    //cout << tmp_score << endl;
                    if (max_score >= tmp_score) {
                        board[i][j] = '.';
                    } else {
                        max_score = tmp_score;
                        //cout << i << " " << j << endl;
                        max_x = i; max_y = j;
                        board[i][j] = '.';
                    }
                }
            }
        }
        board[max_x][max_y] = '+';
        //cout << max_score << endl;

        auto after_search = chrono::system_clock::now();
        auto search_time = after_search - before_search;
        auto msec_search =
    chrono::duration_cast<chrono::milliseconds>(search_time).count();
        auto now_time = chrono::system_clock::now() - start;
        auto msec_now =
    chrono::duration_cast<chrono::milliseconds>(now_time).count();
        //cout << msec_search << endl;
        if (msec_now + msec_search > 1000) {
            break;
        }
    }


    //cout << max_score << endl;

    rep(i, 50) {
        rep(j, 50) {
            putchar(board[i][j]);
        }
        putchar('\n');
    }

/*

    auto time = chrono::system_clock::now() - start;
    auto msec =
       chrono::duration_cast<chrono::milliseconds>(time).count();
*/
//    cout << msec << endl;

    return 0;
}

int score(char ban[50][50])
{
    //vvb used(50, vb(50, false));
    bool used[50][50];
    memset(used, false, 50*50);
    int omax = 0, xmax = 0;
    rep(i, 50) {
        rep(j, 50) {
            if (ban[i][j] == 'o' && !used[i][j]) {
                char start = ban[i][j];
                queue< i_i > que;
                int ret = 1;
                used[i][j] = true;
                que.push(i_i(i, j));
                while (!que.empty()) {
                    i_i pos = que.front(); que.pop();
                    rep(i, 4) {
                        int x = pos.first + dxy[i],
                        y = pos.second + dxy[i+1];
                        if (0 <= x && x < 50 && 
                                0 <= y && y < 50 &&
                                !used[x][y] && 
                                ban[x][y] == 'o') {
                            ret++;
                            que.push(i_i(x, y));
                            used[x][y] = true;
                        } else if (0 <= x && x < 50 && 
                                0 <= y && y < 50 &&
                                ban[x][y] == '+') {
                            used[x][y] = true;
                        }
                    }
                }
                omax = max(omax, ret);
            } else if (ban[i][j] == 'x' && !used[i][j]) {
                char start = ban[i][j];
                queue< i_i > que;
                int ret = 1;
                used[i][j] = true;
                que.push(i_i(i, j));
                while (!que.empty()) {
                    i_i pos = que.front(); que.pop();
                    rep(i, 4) {
                        int x = pos.first + dxy[i],
                        y = pos.second + dxy[i+1];
                        if (0 <= x && x < 50 && 
                                0 <= y && y < 50 &&
                                !used[x][y] && 
                                ban[x][y] == 'x') {
                            ret++;
                            que.push(i_i(x, y));
                            used[x][y] = true;
                        } else if (0 <= x && x < 50 && 
                                0 <= y && y < 50 &&
                                ban[x][y] == '+') {
                            used[x][y] = true;
                        }
                    }
                }
                xmax = max(xmax, ret);
            } else if (ban[i][j] == '+' && !used[i][j]) {
                used[i][j] = true;
            }
        }
    }
    //cout << xmax << " " << omax << endl;
    return (xmax + omax);
}

void drop(char ban[50][50])
{
    memset(drop_board, ' ', 50*50);
    rep(j, 50) {
        for (int i = 49, a = 0; i >= 0; i--) {
            if (ban[i][j] == 'o' || 
                    ban[i][j] == 'x' ||
                    ban[i][j] == '+' || 
                    ban[i][j] == '-') {
                drop_board[a++][j] = ban[i][j];
            }
        }
    }
}

void print_drop_board()
{
    rep(i, 50) {
        rep(j, 50) {
            if (drop_board[i][j] == '+' ||
                    drop_board[i][j] == '-' ||
                    drop_board[i][j] == 'o' ||
                    drop_board[i][j] == 'x') {
                cout << drop_board[i][j];
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }
}

