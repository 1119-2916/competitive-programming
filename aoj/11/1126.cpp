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

vector< vector< char > > board;
int n, m;

bool comp(vector<char> &v1, vector<char> &v2);
void search(int i, int j);

signed main()
{
    cin >> n >> m;
    while (m) {
        board.assign(m, vector<char>(n));
        getchar();
        rep(i, m) {
            rep(j, n) {
                cin >> board[i][j];
            }
        }
        vector< vector< vector<char> > > dp(m, 
                vector<vector<char> >(n));
        if ('1' <= board[0][0] && board[0][0] <= '9') {
            dp[0][0].pb(board[0][0]);
        }
        rep(i, m) {
            rep(j, n) {
                if (dp[i][j].size()) {
                    vector<char> tmp = dp[i][j];
                    if (i+1 < m && '0' <= board[i+1][j]
                            && board[i+1][j] <= '9') {
                        tmp.pb(board[i+1][j]);
                        if (comp(tmp, dp[i+1][j])) {
                            dp[i+1][j] = tmp;
                        }
                        tmp.pop_back();
                    }
                    if (j+1 < n && '0' <= board[i][j+1]
                            && board[i][j+1] <= '9') {
                        tmp.pb(board[i][j+1]);
                        if (comp(tmp, dp[i][j+1])) {
                            dp[i][j+1] = tmp;
                        }
                        tmp.pop_back();
                    }
                } else {
                    if (i+1 < m && '1' <= board[i+1][j]
                            && board[i+1][j] <= '9'
                            && !dp[i+1][j].size()) {
                        dp[i+1][j].pb(board[i+1][j]);
                    }
                    if (j+1 < n && '1' <= board[i][j+1]
                            && board[i][j+1] <= '9'
                            && !dp[i][j+1].size()) {
                        dp[i][j+1].pb(board[i][j+1]);
                    }
                }
            }
        }
        vector<char> ans;
        rep(i, m) {
            rep(j, n) {
                if (comp(dp[i][j], ans)) {
                    ans = dp[i][j];
                }
            }
        }
        for (char i : ans) {
            cout << i;
        }
        cout << endl;

        cin >> n >> m;
    }
    return 0;
}

bool comp(vector<char> &v1, vector<char> &v2)
{
    if (v2.size() < v1.size() ) {
        return true;
    } else if (v2.size() == v1.size() ) {
        rep(i, v2.size()) {
            if (v1[i] > v2[i]) {
                return true;
            } else if (v1[i] < v2[i]) {
                return false;
            }
        }
    }
    return false;
}

