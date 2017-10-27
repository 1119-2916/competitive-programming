#include <bits/stdc++.h>

using namespace std;

#define INF 1001000100010001000
#define int long long 
#define rep(i, N) for (int i = 0; i < N; i++)
#define Int(x) int x; cin >> x;
#define int2(x, y) Int(x); Int(y);
#define vi vector<int>
#define vvi vector< vi >
#define pb push_back

int n, ans;
vector<string> board;

bool line(int stx, int enx, int sty, int eny)
{
    for (int i = stx; i < enx; i++) {
        for (int j = sty; j < eny; j++) {
            if (board[i][j] == 'o') {
                return false;
            }
        }
    }
    return true;
}

int funami_yui(int stx, int enx, int sty, int eny, int score)
{
    int ans = 0;
    for (int i = stx; i < enx; i++) {
        if ( line(i, i+1, sty, eny) ) {
            int state = -1;
            for (int j = sty; j < eny; j++) {
                if (state == -1) {
                    state = 0;
                }
                int res = score;
                ret += funami_yui(stx, i, sty, j, score+1);
                ret += funami_yui(i+1, enx, sty, j, score+1);
                ret += funami_yui(stx, i, j+1, eny, score+1);
                ret += funami_yui(i+1, enx, j+1, eny, score+1);
                ans = max(ans, ret);
            }
        }
    }
}

    //cout << stx << " " << enx << " " << sty << " " << eny << endl;
    int xpos = stx;
    for (int i = stx; i < enx; i++) {
        if (line(i, i+1, sty, eny)) {
            //cout << " : " << i << endl;
            int ypos = sty;
            for (int j = sty; j < eny; j++) {
                if (line(stx, enx, j, j+1)) {
                    //cout << "( " << i << ", " << j << ")" << endl;
                    ans++;
                    funami_yui(xpos, i, ypos, j);
                    ypos = j+1;
                }
            }
            funami_yui(xpos, i, ypos, eny);
            xpos = i+1;
        }
    }
    if (xpos != stx) {
        int ypos = sty;
        for (int j = sty; j < eny; j++) {
            if (line(stx, enx, j, j+1)) {
                //cout << "( " << sty << ", " << j << ")" << endl;
                //ans++;
                funami_yui(xpos, enx, ypos, j);
                ypos = j+1;
            }
        }
        funami_yui(xpos, enx, ypos, eny);
    }
}

signed main()
{
    cin >> n;
    rep(i, n) {
        string tmp;
        cin >> tmp;
        board.pb(tmp);
    }

    funami_yui(0, n, 0, n);
    cout << ans << endl;


    return 0;
}
