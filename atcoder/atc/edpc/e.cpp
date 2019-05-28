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

    int2(n, w);
    
    //vi dp(101000, INF);
    vector<int> dp(101000, INF);
    dp[0] = 0;

    rep(i, n) {
        int2(yui, kyoko); // weight value
        for (int j = dp.size()-1; j > 0; j--) {
            if (dp[j] != INF) {
                dp[j + kyoko] = min(dp[j + kyoko], 
                        dp[j] + yui);
            }
        }
        dp[kyoko] = min(dp[kyoko], yui);
        /*
        rep(i, 11) std::cout << dp[i] << " ";
        cout << endl;
        */      
    }

    for (int i = dp.size()-1; i >= 0; i--) {
        if (dp[i] <= w) {
            std::cout << i << std::endl;
            break;
        }
    }

    return 0;
}
