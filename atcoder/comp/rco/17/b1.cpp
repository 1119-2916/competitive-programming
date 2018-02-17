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
#define eb emplece_back
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

typedef struct food{
    int x, y;
    int score, dec;
}Food;

int h, w, k, sr, sc;
string board[50];
int n;
Food food[2500];
char dist[4] = {'R', 'D', 'L', 'U'};
int step;

void bfs(int x, int y);

signed main()
{
    cin >> h >> w >> k >> sr >> sc;
    sr--; sc--;
    rep(i, h) {
        cin >> board[i];
    }
    cin >> n;
    rep(i, n) {
        cin >> food[i].x >> food[i].y >> food[i].score >> food[i].dec;
        board[food[i].x-1][food[i].y-1] = food[i].score;
    }

    while (step < k) {
        bfs(sr, sc);
    }

    return 0;
}

void bfs(int x, int y)
{
    int count = 0;
    queue< pair< i_i , pair<string, int> > > qs;
    bool used[50][50];
    memset(used, false, sizeof(used));
    used[x][y] = true;
    qs.push(pair< i_i , pair<string, int> >
            (i_i(x, y), pair<string, int>("", 1)));
    while (!qs.empty()) {
        x = qs.front().first.first;
        y = qs.front().first.second;
        string st = qs.front().second.first;
        count = qs.front().second.second;
        if (count + step >= k) {
            for (int i = step; i < k; i++) {
                cout << "-";
                step++;
            }
            return;
        }
        qs.pop();
        rep(i, 4) {
            int nx = x + dxy[i], ny = y + dxy[i+1];
            string nst = st;
            if (0 <= nx && nx < h && 
                    0 <= ny && ny < w && 
                    !used[nx][ny] &&
                    board[nx][ny] != '#') {
                if (board[nx][ny] != '.') {
                    if (step + count < k) {
                        step += count;
                        sr = nx; sc = ny;
                        nst.pb(dist[i]);
                        cout << nst;
                        board[nx][ny] = '.';
                        return;
                    } else {
                        for (int i = step; i < k; i++) {
                            cout << "-";
                            step++;
                        }
                        return;
                    }
                } else {
                    used[nx][ny] = true;
                    nst.pb(dist[i]);
                    qs.push(pair< i_i , pair<string, int> >
                            (i_i(nx, ny), pair<string, int>(nst, count+1)));
                }
            }
        }
    }
    for (int i = step; i < k; i++) {
        cout << "-";
        step++;
    }
    return;
}


