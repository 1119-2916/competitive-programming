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

// // assign avl ncm dijkstra geo2 kruskal graph uf lca BIT
// matrix dinic next_combination topcoder lcm vi st gin
// cusum segtree

int n, k, h, w, t;
vector<vvi> board;

std::chrono::high_resolution_clock::time_point now_time;
 
inline void timer_set() {
    using namespace std::chrono;
    now_time = high_resolution_clock::now();
}
inline bool time_check(int lim) {
    using namespace std::chrono;
    auto ed = high_resolution_clock::now();
    auto t = ed - now_time;
    return(duration_cast<milliseconds>(t).count() < lim);
}

string ans;
char command[4] = {'U', 'D', 'L', 'R'};
int dxy[5] = {0, 1, 0, -1, 0};

int solve(int p, string ans)
{
    int x, y;
    int ret = 0;
    rep(i, h) rep(j, w) {
        if (board[p][i][j] == 3) { x = i; y = j; }
    }
    rep(i, ans.size()) {
        int mv = 0;
        if (ans[i] == 'U') {
            mv = 2;
        } else if (ans[i] == 'D') {
            mv = 0;
        } else if (ans[i] == 'L') {
            mv = 3;
        } else if (ans[i] == 'R') {
            mv = 1;
        }
        x += dxy[mv]; y += dxy[mv];
        if (board[p][x][y] == -1) {
            x -= dxy[mv]; y -= dxy[mv];
        } else if (board[p][x][y] == 1) {
            ret++;
        } else if (board[p][x][y] == 2) {
            return ret;
        }
    }
    return ret;
}

struct State {
    int score, x, y;
    string st;
    vvi board;
    State(int score, int x, int y, string st, vvi board) :
        score(score), x(x), y(y), st(st), board(board) {};
    State(State &hoge, char nxt) :
        score(hoge.score), x(hoge.x), y(hoge.y), st(hoge.st),
        board(hoge.board) { st += nxt; };
};
bool operator<(const State &s1, const State &s2) 
{ return s1.score < s2.score; }
bool operator>(const State &s1, const State &s2) { return s2 < s1; }
inline ostream &operator<<(ostream &os, const State &s) {
    return (os << "(" << s.score << ", (" << s.x << ", " << s.y << ")"); }

vector<string> Ti11192916(int p, int haba)
{
    int x, y;
    rep(i, h) rep(j, w) {
        if (board[p][i][j] == 3) { x = i; y = j; }
    }
    State first(0, x, y, "", board[p]);
    first.board[x][y] = 0;
    priority_queue<State> funami_yui;
    funami_yui.push(first);
    rep(i, 5) {
        //cout << funami_yui.size() << endl;
        priority_queue<State> toshino_kyoko;
        int bef_score = -1, bef_x = -1, bef_y = -1;
        rep(j, haba) {
            State now = funami_yui.top();
            if (bef_score == -1) {
                bef_score = now.score;
                bef_x = now.x; bef_y = now.y;
            } else if (bef_score == now.score && 
                    bef_x == now.x && bef_y == now.y) {
                continue;
            }

            State mu(now, 'U');/*{{{*/
            x = mu.x, y = mu.y;
            if (mu.board[x-1][y] == 1) {
                mu.board[x-1][y] = 0;
                mu.score++;
                mu.x -= 1;
            } else if (mu.board[x-1][y] == 0) {
                mu.x -= 1;
            }
            if (mu.board[x][y] != 2) {
                toshino_kyoko.push(mu);
            }

            State md(now, 'D');
            x = md.x, y = md.y;
            if (md.board[x+1][y] == 1) {
                md.board[x+1][y] = 0;
                md.score++;
                md.x += 1;
            } else if (md.board[x+1][y] == 0) {
                md.x += 1;
            }
            if (md.board[x][y] != 2) {
                toshino_kyoko.push(md);
            }

            State ml(now, 'L');
            x = ml.x, y = ml.y;
            if (ml.board[x][y-1] == 1) {
                ml.board[x][y-1] = 0;
                ml.score++;
                ml.y -= 1;
            } else if (ml.board[x][y-1] == 0) {
                ml.y -= 1;
            }
            if (ml.board[x][y] != 2) {
                toshino_kyoko.push(ml);
            }

            State mr(now, 'R');
            x = mr.x, y = mr.y;
            if (mr.board[x][y+1] == 1) {
                mr.board[x][y+1] = 0;
                mr.score++;
                mr.y += 1;
            } else if (mr.board[x][y+1] == 0) {
                mr.y += 1;
            }
            if (mr.board[x][y] != 2) {
                toshino_kyoko.push(mr);
            }/*}}}*/
        }
        funami_yui = toshino_kyoko;
        rep(j, 5) {
            cout << toshino_kyoko.top() << endl;
            toshino_kyoko.pop();
        }
    }
    vector<string> ret;
    rep(i, 5) {
        if (funami_yui.size()) {
            ret.pb(funami_yui.top().st);
            cout << funami_yui.top().x << " " << 
                funami_yui.top().y << endl;
            funami_yui.pop();
        }
    }
    return ret;
}

signed main()
{
    timer_set();
    random_device rnd;
    std::mt19937 mt(rnd());
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    cin >> n >> k >> h >> w >> t;
    board.assign(n, vvi(h, vi(w, 0)));
    rep(i, n) {
        rep(j, h) {
            rep(k, w) {
                while (!board[i][j][k]) {
                    char tmp; cin >> tmp;
                    if (tmp == '#') {
                        board[i][j][k] = -1;
                    } else if (tmp == 'o') {
                        board[i][j][k] = 1;
                    } else if (tmp == 'x') {
                        board[i][j][k] = 2;
                    } else if (tmp == '@') {
                        board[i][j][k] = 3;
                    }
                }
            }
        }
    }

    //rep(i, n) {
        vector<string> yui = Ti11192916(0, 5);
        rep(j, yui.size()) {
            cout << yui[j] << endl;
        }
    //}

    /*
    while (time_check(3980)) {
        int now_score = 0;
        vi now_nums(0);
        int tmp = mt() % (t-4);
        priority_queue<i_i> score;
        rep(i, n) {
            int tmp = solve(i, output);
            score.push({tmp, i});
        }
        rep(i, k) {
            now_nums.pb(score.top().sec);
            now_score += score.top().fir;
            score.pop();
        }
        if (output_score < now_score) {
            output_score = now_score;
            output_nums = now_nums;
        }
    }

    rep(i, output_nums.size()) {
        cout << output_nums[i] << " ";
    }cout << endl;
    cout << output << endl;
    */

    return 0;
}


