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

int N, K, H, W, T;
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

/*
string solve_bfs(int num)
{
    string ans;
    int x, y;
    rep(i, h) rep(j, w) {
        if (board[p][i][j] == 3) { x = i; y = j; }
    }
*/

string ans;
char command[4] = {'D', 'R', 'U', 'L'};
int dxy[5] = {0, 1, 0, -1, 0};

int solve(int p, string ans)
{
    int x, y;
    int ret = 0;
    rep(i, H) rep(j, W) {
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

signed main()
{
    timer_set();
    random_device rnd;
    std::mt19937 mt(rnd());
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    cin >> N >> K >> H >> W >> T;
    board.assign(N, vvi(H, vi(W, 0)));
    rep(i, N) {
        rep(j, H) {
            rep(k, W) {
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

    vp pos(0);
    rep(i, N) {
        int x, y;
        rep(i, H) rep(j, W) {
            if (board[p][i][j] == 3) { pos.pb({i, j}); break; }
        }
    }

    vi bef_score(N, 0);
    string output;
    rep(i, T) {
        int nxt_num = 0, nxt_score = 0;
        rep(j, 4) {
            string now = output + command[j];
            int tmp = 0;
            rep(k, N) {
                int x = pos[k].fir, y = pos[k].sec;
                if (board[k][x+dxy[j]][y+dxy[j+1]] == 1) {
                    board[k][x+dxy[j]][y+dxy[j+1]] = 0;
                    tmp += 10 + (T - i); // score
                } else if (board[k][x+dxy[j]][y+dxy[j+1]] == 2) {
                    tmp     


    
    string output; int output_score = 0;
    vi output_nums(0);
    rep(i, T) {
        output += command[mt() % 4];
    }
    while (time_check(3980)) {
        int now_score = 0;
        vi now_nums(0);
        /*
        int tmp = mt() % (t-4);
            output[tmp] = command[mt() % 4];
            output[tmp+1] = command[mt() % 4];
            output[tmp+2] = output[tmp];
            output[tmp+3] = output[tmp+1];
            */
        int tmp = mt() % (T-3);
            output[tmp] = command[mt() % 4];
            output[tmp+1] = output[tmp];
            output[tmp+2] = output[tmp];
        priority_queue<i_i> score;
        rep(i, N) {
            int tmp = solve(i, output);
            score.push({tmp, i});
        }
        rep(i, K) {
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

    return 0;
}


