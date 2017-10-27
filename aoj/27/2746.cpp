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
 
//int dxy[5] = {0, 1, 0, -1, 0};
// assign


signed main()
{
    string data;
    while (cin >> data) {
        vvi board;
        if (data[0] == '#') break;
        vi tmp;
        rep(i, data.size()) {
            if (data[i] == '/') {
                board.pb(tmp);
                tmp.assign(0,0);
            } else if (data[i] == 'b') {
                tmp.pb(1);
            } else {
                rep(j, data[i] - '0') {
                    tmp.pb(0);
                }
            }
        }
        board.pb(tmp);
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a--; b--; c--; d--;
        int temp = board[a][b];
        board[a][b] = board[c][d];
        board[c][d] = temp;

        rep(i, board.size()) {
            int a = 0;
            rep(j, board[i].size()) {
                if (board[i][j]) {
                    if (a) {
                        cout << a;
                        a = 0;
                    }
                    cout << "b";
                } else {
                    a++;
                }
                //cout << board[i][j];
            }
            if (a) {
                cout << a;
            }
            if (i+1 != board.size()) {
                cout << "/";
            }
        }
        cout << endl;
    }


    return 0;
}

