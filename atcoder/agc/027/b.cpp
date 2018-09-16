#include <bits/stdc++.h>
#include <assert.h>

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

    int2(n, x);
    if (n <= 2000) {
        vector<int> data(n);
        for (int i = 0; i < n; i++) {
            cin >> data[i];
        }
        reverse(all(data));

        vi dp(n+1, INF);

        dp[0] = 0;
        rep(i, n) {
            int cost = data[i];
            //        cout << cost << endl;
            for (int j = i+1; j < n+1; j++) {
                if (j != i+1)
                    cost += (j - i) * (j - i) * (data[j-2] - data[j-1]);
                //            cout << "cost :" << data[j-1] << " " << 
                //               data[j-2] << " " << cost << endl;
                dp[j] = min(dp[j], dp[i] + x +
                        cost + (data[j-1] * (j - i + 1LL) * (j - i + 1LL)));
                //            cout << j << " " << dp[j] << " ";
            }
        }
         //          rep(j, dp.size()) {
          //           cout << dp[j] << " " ;
           //     }cout << endl;

        cout << dp[n] + (n * x)<< endl;
    } else {
        assert(0);
    }

    return 0;
}
