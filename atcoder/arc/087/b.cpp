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

//int dxy[5] = {0, 1, 0, -1, 0};
// cmd

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    string st;
    cin >> st;
    int2(a, b);

    vi dx(0), dy(0);
    int cnt = 0, hop = 0;
    rep(i, st.size()) {
        if (st[i] == 'T') {
            if (hop) {
                if (cnt % 2) {
                    dy.pb(hop);
                } else {
                    dx.pb(hop);
                }
                hop = 0;
            }
            cnt++;
        } else {
            hop++;
        }
    }
    if (hop) {
        if (cnt % 2) {
            dy.pb(hop);
        } else {
            dx.pb(hop);
        }
    }
    /*
    rep(i, dx.size()) cout << dx[i] << " ";
    cout << endl;

    rep(i, dy.size()) cout << dy[i] << " ";
    cout << endl;
    */

    vvb dp(dx.size()+1, vb(16010, false));
    int zero = 8000;
    dp[0][zero] = true;
    rep(i, dx.size()) {
        rep(j, dp[i].size()) {
            if (dp[i][j]) {
                dp[i+1][j+dx[i]] = true;
                dp[i+1][j-dx[i]] = true;
            }
        }
    }
    if (!dp[dx.size()][a+zero]) {
        cout << "No" << endl;
        return 0;
    }

    dp = vvb(dy.size()+1, vb(16010, false));
    dp[0][zero] = true;
    rep(i, dy.size()) {
        rep(j, dp[i].size()) {
            if (dp[i][j]) {
                dp[i+1][j+dy[i]] = true;
                dp[i+1][j-dy[i]] = true;
            }
        }
    }
    if (!dp[dy.size()][b+zero]) cout << "No" << endl;
    else cout << "Yes" << endl;


    return 0;
}




