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
#define Edge pair< i_i, int>
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

vector<string> board;
int h, w;

i_i move(int i, int j, int k)
{
    if (0 <= i + dxy[k] && i + dxy[k] < h && 
            0 <= j + dxy[k+1] && j + dxy[k+1] < w && 
            board[i+dxy[k]][j+dxy[k+1]] == '1') {
        return i_i(-1, -1);
    }
 //   cout << " ( " << i << " , " << j << " ) " << endl;
    while (0 <= i + dxy[k] && i + dxy[k] < h && 
            0 <= j + dxy[k+1] && j + dxy[k+1] < w) {
        i += dxy[k]; j += dxy[k+1];
        if (board[i][j] == '3') {
            return i_i(i, j);
        } else if (board[i][j] == '1') {
            return i_i(i-dxy[k], j-dxy[k+1]);
        }
    }
    return i_i(-1, -1);
}

int solve(int i, int j, int cnt)
{
//    cout << i << " " << j << endl;
/*
    rep(lop, h) {
        if (lop == i) {
            rep(loop, w) {
                if (loop == j) {
                    cout << 'x';
                } else {
                    cout << board[i][j];
                }
            }
            cout << endl;
        } else {
            cout << board[i] << endl;
        }
    }
*/
    if (cnt == 10) {
        return 11;
    }
    int ans = 11;
    rep(k, 4) {
        i_i pos = move(i, j, k);
        if (pos.fir == -1) {
            continue;
        } else if (board[pos.fir][pos.sec] == '3') {
            ans = min(ans, cnt+1);
        } else {
            board[pos.fir+dxy[k]][pos.sec+dxy[k+1]] = '0';
            ans = min(ans, solve(pos.fir, pos.sec, cnt+1));
            board[pos.fir+dxy[k]][pos.sec+dxy[k+1]] = '1';
        }
    }
    return ans;
}

signed main()
{
    while (cin >> w >> h, w) {
        int stx, sty;
        board = vector<string>(h);
        rep(i, h) {
            rep(j, w) {
                Int(tmp);
                if (tmp == 2) { 
                    stx = i; sty = j;
                    tmp = 0;
                }
                board[i].pb(tmp + '0');
            }
        }
//        cout << stx << " " << sty << endl;
        /*
        rep(i, h) {
            cout << board[i] << endl;
        }*/
        int ret = solve(stx, sty, 0);
        if (ret == 11) {
            cout << -1 << endl;
        } else {
            cout << ret << endl;
        }
    }

    return 0;
}

