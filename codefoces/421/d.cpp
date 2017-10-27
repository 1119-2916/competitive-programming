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
#define eb emplece_back
#define mp make_pair
#define i_i pair<int, int>
#define vi vector<int>
#define vvi vector<vi >
#define vb vector<bool>
#define vvb vector<vb >
#define vp vector< i_i >
#define Edge pair< i_i, int>
#define all(a) (a).begin(), (a).end()
#define Int(x) int x; scanf("%lld", &x);
#define int2(x, y) int x, y; scanf("%lld %lld", &x, &y);
#define fir first
#define sec second
#define ffir first.first
#define fsec first.second
#define sfir second.first
#define ssec second.second
 
//int dxy[5] = {0, 1, 0, -1, 0};
// assign
 
signed main()
{
    Int(n);
    vi data(n);
    rep(i, n) cin >> data[i];

    vi yui(n, 0);
    int inc = 0, dec = 0, ans = 0;
    rep(i, n) {
        if (data[i] != 1)
            yui[(data[i] - i - 1 + n) % n]++;
        /*
         * 引く数がどんどん増えていく.
         */
        if (data[i] <= i+1) {
            inc++;
        } else {
            dec++;
        }
        ans += abs(data[i] - i - 1);
    }
    int kans = 0, ret = ans;
    
  //  rep(i, n) cout << yui[i] << " "; cout << endl;

    /*
     * 後ろに送るものは必ずdec状態にいる.
     * ただしnは0.
     */
 //   cout << ans << " " << inc << " " << dec << endl;
    Rep(i, n) {
        ans += (inc-1);
        ans -= dec;
        ans -= (n - data[n-i]);
        ans += (data[n-i] -1);
        dec += (data[n-i] == 1) ? 0 : 1;
        inc -= (data[n-i] == 1) ? 0 : 1;
        dec -= yui[i];
        inc += yui[i];
//    cout << ans << " " << inc << " " << dec << endl;
        if (ans < ret) {
            ret = ans;
            kans = i;
        }
    }
    cout << ret << " " << kans << endl;

    return 0;
}

