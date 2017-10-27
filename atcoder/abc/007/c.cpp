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

signed main()
{
    queue< i_i > q;
    int2(n, m);
    int2(sa, sb);
    int2(ga, gb);
    vector<string> board(n);
    rep(i, n) {
        cin >> board[i];
    }
    int ans = 0;
    q.push(i_i(sa-1, sb-1));
    while (!q.empty()) {
        queue< i_i > nq;
        ans++;
        while (!q.empty()) {
            i_i tmp = q.front(); q.pop();
            rep(i, 4) {
                int x = tmp.first + dxy[i], y = tmp.second + dxy[i+1];
                if (x == ga-1 && y == gb-1) {
                    cout << ans << endl;
                    return 0;
                }
                if (0 <= x && x < n && 0 <= y && y < m && 
                        board[x][y] == '.') {
                    nq.push(i_i(x, y));
                    board[x][y] = '#';
                }
            }
        }
        q = nq;
    }



    return 0;
}

