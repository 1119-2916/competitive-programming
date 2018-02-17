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
char dist[4] = {'D', 'R', 'U', 'L'};

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
    }
    random_device rnd;
    int nx = sr, ny = sc;
    for (int i = 0; i < k;) {
        int rn = rnd() % 4;
        int nnx = nx + dxy[rn], nny = ny + dxy[rn+1];
        if (0 <= nnx && nnx < h && 
                0 <= nny && nny < w &&
                board[nnx][nny] != '#') {
            cout << dist[rn];
            nx = nnx;
            ny = nny;
            i++;
        }
    }


    return 0;
}

