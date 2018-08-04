#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define Rep(i, n) for (int i = 1; i < (n); i++)
#define int long long 
#define pii pair<int, int>
#define fir first
#define sec second
#define pb push_back

signed main()
{
    int n, m;

    int _ = 1;
    while (cin >> n >> m, _--) {
//    while (cin >> n >> m, n) {

        int ans = 0;
        vector<pii> data(0);
        rep(i, m) {
            int a, b;
            cin >> a >> b;
            if (b > a) {
                data.pb({b, -a});
            }
        }

        if (data.size() == 0) {
            cout << n + 1 << endl;
            continue;
        }

        //sort(data.begin(), data.end());
        rep(i, data.size())  data[i].sec *= -1;
        sort(data.begin(), data.end());
        rep(i, data.size()) cout << data[i].fir << " " << data[i].sec << endl;
        int back = data[0].sec;
        ans += data[0].fir;
        //cout << back << endl << ans << endl;
        Rep(i, data.size()) {
            ans += data[i].fir - data[i-1].fir;
            if (data[i-1].fir < data[i].sec) {
                ans += (data[i-1].fir - back) * 2;
                back = data[i].sec;
            } else {
                back = min(back, data[i].sec);
            }
            //cout << "back : " << back << endl;
            //cout << "ans : " << ans << endl;
        }
       // cout << back << endl;

        ans += (data.back().fir - back) * 2;
        ans += (n + 1) - data.back().fir;

        cout << ans << endl;
    }

    return 0;
}

