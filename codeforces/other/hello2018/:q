#include <bits/stdc++.h>

using namespace std;

#define INF 8001000100010001000
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

string to_bit(int a) 
{
    string ret = "";
    if (!a) return "0";
    while (a) {
        ret.pb('0' + a % 2);
        a /= 2;
    }
    return ret;
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int2(n, l);
    vector<int> data(n);
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }

    Rep(i, n) {
        if (data[i-1] * 2 < data[i]) {
            data[i] = data[i-1] * 2;
        }
    }
    for (int i = n-1; i > 0; i--) {
        data[i-1] = min(data[i-1], data[i]);
    }

    /*
    rep(i, n) {
        cout << data[i] << " ";
    }cout << endl;
    */

    string yui = to_bit(l);
    //cout << yui << endl;

    for (int i = n; i < yui.size()+1; i++) {
        data.pb(data.back() * 2);
    }

    //rep(i, data.size()) cout << data[i] << " "; cout << endl;

    vvi dp(yui.size()+2, vi(2, INF));

    dp[yui.size()][1] = data[yui.size()];
    dp[yui.size()][0] = 0;
    for (int i = yui.size(); i > 0; i--) {
        if (yui[i-1] == '1') {
            dp[i-1][0] = dp[i][0] + data[i-1];
            dp[i-1][1] = dp[i][1];
        } else {
            dp[i-1][0] = dp[i][0];
            dp[i-1][1] = min(dp[i][1], dp[i][0] + data[i-1]);
        }
    }

    cout << min(dp[0][0], dp[0][1]) << endl;

    return 0;
}

