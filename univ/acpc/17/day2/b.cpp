#include <bits/stdc++.h>

using namespace std;

#define INF 1001000100010001000
#define int long long 
#define rep(i, N) for (int i = 0; i < N; i++)
#define Int(x) int x; cin >> x;
#define int2(x, y) Int(x); Int(y);
#define vi vector<int>
#define vvi vector< vi >

signed main()
{
    int n;
    cin >> n;

    vvi day(n, vi(361, -1));

    rep(i, n) {
        //cout << endl;
        //cout << i << endl;
        int2(a, b);
        int2(d, c);
        rep(j, d) {
            day[i][(j + ((a - 1) * 30) + b - 1) % 360] = c;
            //cout << day[i][(j + (a * 30) + b) % 360] << " ";
        }
        int st = (a - 1) * 30 + b - 1;
        int en = (st + d - 1) % 360;
        rep(j, 360) {
            int dist = min( (st - j + 360) % 360,
                    (j - en + 360) % 360);
            day[i][j] = max(day[i][j], max(c - dist, 0LL));
            //cout << day[i][j] << " ";
        }
        //cout << endl;
    }

    int ans = INF;
    rep(j, 360) {
        int tmp = 0;
        rep(i, n) {
            tmp = max(tmp, day[i][j]);
        }
        ans = min(ans, tmp);
    }

    cout << ans << endl;

    return 0;
}
