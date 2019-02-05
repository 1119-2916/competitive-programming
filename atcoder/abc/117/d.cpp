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

int mmnmm(int num)
{
    int ret = 0;
    while (num) {
        num /= 2;
        ret++;
    }
    return ret;
}

int dp[100][2];

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int2(n, k);
    vector<int> data(n);
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }
    
    int ans = 0;
    int keta = 42;
    vp funami;

    while (keta >= 1ll) {
        int yui = (1ll << (keta-1));
        int cnt = 0;
        rep(i, data.size()) {
            cnt += !!(data[i] & yui);
        }
        funami.pb({cnt * yui, (n-cnt)*yui});
        keta--;
    }

    /*
    rep(i, funami.size()) {
        std::cout << funami[i].fir << " " << funami[i].sec << std::endl;
    }
    */

    for (int i = 42, ptr = 0; i > 0; i--, ptr++) {
        if (k > 1ll << (i-1)) {
            if (k & 1ll << (i-1)) {
                dp[i][1] = max(dp[i][1], dp[i+1][1] + funami[ptr].sec);
                dp[i][0] = max(dp[i][0], dp[i+1][1] + funami[ptr].fir);
                dp[i][0] = max(dp[i][0], dp[i+1][0] + funami[ptr].sec);
                dp[i][0] = max(dp[i][0], dp[i+1][0] + funami[ptr].fir);
            } else {
                dp[i][0] = max(dp[i][0], dp[i+1][1] + funami[ptr].fir);
                dp[i][0] = max(dp[i][0], dp[i+1][0] + funami[ptr].sec);
                dp[i][0] = max(dp[i][0], dp[i+1][0] + funami[ptr].fir);
            }
        } else {
            dp[i][0] = max(dp[i][0], dp[i+1][1] + funami[ptr].fir);
            dp[i][0] = max(dp[i][0], dp[i+1][0] + funami[ptr].fir);
        }
        cout << funami[ptr].fir << " " << funami[ptr].sec << endl;
    }

    /*
    Rep(i, 5) {
        std::cout << dp[i][0] << " " << dp[i][1] << std::endl;
    }
    */

    std::cout << max(dp[1][0], dp[1][1]) << std::endl;

    return 0;
}
