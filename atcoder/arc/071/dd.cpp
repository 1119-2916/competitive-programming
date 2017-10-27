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
#define Int(x) int x; scanf("%lld", &x);
#define int2(x, y) int x, y; scanf("%lld %lld", &x, &y);
 
//int dxy[5] = {0, 1, 0, -1, 0};
// assign
 
signed main()
{
    int2(n, m);
    vi x(n), y(m);
    rep(i, n) cin >> x[i];
    rep(i, m) cin >> y[i];

    vi xr, yr;

    Rep(i, n) {
        rep(j, n-i) {
            xr.pb(x[j+i]-x[j]);
//            cout << xr[xr.size()-1] << endl;
        }
    }

    Rep(i, m) {
        rep(j, m-i) {
            yr.pb(y[j+i]-y[j]);
 //           cout << yr[yr.size()-1] << endl;
        }
    }

    int ans = 0;
    rep(i, xr.size()) {
        rep(j, yr.size()) {
            ans += xr[i] * yr[j];
            ans %= MOD;
        }
    }

    cout << ans % MOD << endl;



    return 0;
}

