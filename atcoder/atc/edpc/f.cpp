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
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vi >
#define vb vector<bool>
#define vvb vector<vb >
#define vp vector< pii >
#define all(a) (a).begin(), (a).end()
#define Int(x) int x; cin >> x;
#define int2(x, y) Int(x); Int(y);
#define int3(x, y, z) Int(x); int2(y, z);
#define in(x, a, b) ((a) <= (x) && (x) < (b))
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

    string s, t;
    cin >> s >> t;

    vvi dp(s.size()+1, vi(t.size()+1, 0));

    rep(i, s.size()) {
        rep(j, t.size()) {
            if (s[i] == t[j]) 
            dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j]+1);
            dp[i+1][j+1] = max({dp[i+1][j+1],
                    dp[i][j+1], dp[i+1][j]});
        }
    }
    /*
    rep(i, dp.size()) {
        rep(j, dp[i].size()) {
            std::cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    */
    //cout << endl;

    int p1 = s.size(), p2 = t.size();
    string ans;
    while (p1 != 0 && p2 != 0) {
        //cout << p1 << " " << p2 << endl;
        if (dp[p1][p2] == dp[p1-1][p2]) p1--;
        else if (dp[p1][p2] == dp[p1][p2-1]) p2--;
        else {
            ans.pb(s[p1-1]);
            p1--; p2--;
        }
    }
    //cout << p1 << " " << p2 << endl;
    reverse(all(ans));

    std::cout << ans << std::endl;

    return 0;
}
