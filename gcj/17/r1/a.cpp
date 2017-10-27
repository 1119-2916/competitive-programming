#include <bits/stdc++.h>
 
using namespace std;
 
#define INF 1001000100010001000
#define MOD 1000000007
#define pi 3.141592653589
#define EPS 1e-10
#define int long long
#define double long double
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
 
//int dxy[5] = {0, 1, 0, -1, 0};
// assign
 
signed main()
{
    Int(dataset);

    Rep(state, dataset+1) {
        cout << "Case #" << state << ": ";

        int2(n, k);
        vector < i_i > c(n);
        rep(i, n) {
            cin >> c[i].first >> c[i].second;
        }

        sort(all(c));
        reverse(all(c));

        vector< vector <double> > dp(k+1, 
                vector <double> (n, 0.0));

        Rep(i, k+1) {
            rep(j, n) {
                if (i == 1) {
                    dp[i][j] = max(dp[i][j], 
                            c[j].first * c[j].first * pi +
                            c[j].first * (double)2.0 * c[j].second * pi);
                } else {
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j-1] + 
                            c[j].first * (double)2.0 * c[j].second * pi);
                }
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }

        printf("%.10Lf\n", dp[k][n-1]);
    }

        //double ans = 0.0;
        //rep(i, k) {




    return 0;
}

