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
    rep(i, n) {
        cin >> x[i];
    }
    rep(i, m) {
        cin >> y[i];
    }

    vi xr(n-1), yr(m-1);

    int sum = 0, ans = 0;

    xr[0] = xr.size();
    xr[xr.size()-1] = xr[0];

    for (int i = 1; i < (n-1)/2 + (n-1) % 2; i++) {
        xr[i] = xr[i-1] + (xr.size() - (i * 2));
        xr[xr.size()-1 - i] = xr[i];
    }

    rep(i, xr.size()) { 
        //cout << xr[i] << endl;
        //cout << x[i+1] << x[i] << endl;
        xr[i] *= x[i+1] - x[i];
        sum += (xr[i] % MOD);
        //cout << xr[i] << endl;
        sum %= MOD;
    }
//    cout << sum << endl;

    yr[0] = yr.size();
    yr[yr.size()-1] = yr[0];

    for (int i = 1; i < (m-1)/2 + (m-1) % 2; i++) {
        yr[i] = yr[i-1] + (yr.size() - (i * 2));
        yr[yr.size()-1 - i] = yr[i];
    }

    rep(i, yr.size()) {
        yr[i] *= y[i+1] - y[i];
        ans += (yr[i] * sum) % MOD;
        ans %= MOD;
    }

    cout << ans << endl;



    return 0;
}

