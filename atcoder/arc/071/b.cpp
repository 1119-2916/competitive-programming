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
    n--, m--;
    vi x(n), y(m);

    Int(bef);
    rep(i, n) {
        Int(tmp);
        x[i] = tmp - bef;
        bef = tmp;
    }
    cin >> bef;
    rep(i, m) {
        Int(tmp);
        y[i] = tmp - bef;
        bef = tmp;
    }

     /*{{{
    rep(i, n) {
        cout << x[i] << " ";
    }cout << endl;
    rep(i, m) {
        cout << y[i] << " ";
    }cout << endl;
     }}}*/

    int xsum = 0;
    if (n % 2) {
        int pos = n;
        rep(i, n / 2) {
            xsum += (pos * x[i]) % MOD;
            pos += (n - (i+1) * 2);
            xsum %= MOD;
        }
        xsum += (pos * x[n/2]);
        xsum %= MOD;

        pos = n;
        rep(i, n / 2) {
            xsum += (pos * x[n - i - 1]) % MOD;
            pos += (n - (i+1) * 2);
            xsum %= MOD;
        }

       // cout << xsum << endl;
    } else {
        int pos = n;
        rep(i, n / 2) {
            xsum += (pos * x[i]) % MOD;
            pos += (n - (i+1) * 2);
            xsum %= MOD;
        }

        pos = n;
        rep(i, n / 2) {
            xsum += (pos * x[n - i - 1]) % MOD;
            pos += (n - (i+1) * 2);
            xsum %= MOD;
        }
        //cout << xsum << endl;
    }

    int ysum = 0;
    if (m % 2) {
        int pos = m;
        rep(i, m / 2) {
            ysum += (pos * y[i]) % MOD;
            pos += (m - (i+1) * 2);
            ysum %= MOD;
        }
        ysum += (pos * y[m/2]);
        ysum %= MOD;

        pos = m;
        rep(i, m / 2) {
            ysum += (pos * y[m - i - 1]) % MOD;
            pos += (m - (i+1) * 2);
            ysum %= MOD;
        }

        //cout << xsum << endl;
    } else {
        int pos = m;
        rep(i, m / 2) {
            ysum += (pos * y[i]) % MOD;
            pos += (m - (i+1) * 2);
            ysum %= MOD;
        }

        pos = m;
        rep(i, m / 2) {
            ysum += (pos * y[m - i - 1]) % MOD;
            pos += (m - (i+1) * 2);
            ysum %= MOD;
        }
//        cout << ysum << endl;
    }
    cout << (xsum * ysum) % MOD << endl;





    return 0;
}

