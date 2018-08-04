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
    int n, m, ans = 0;
    cin >> n >> m;

    vector<pii> data(0);
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        if (b > a) {
            data.pb({b, a});
        }
    }

    if (data.size() == 0) {
        cout << n + 1 << endl;
        return 0;
    }

    sort(data.begin(), data.end());
    //rep(i, data.size()) cout << data[i].fir << " " << data[i].sec << endl;
    int back = data[0].sec;
    ans += data[0].fir;
    Rep(i, data.size()) {
        ans += data[i].fir - data[i-1].fir;
        if ( (data[i-1].fir - back) * 2 + (data[i].fir - data[i].sec) * 2
                <= (data[i].fir - min(back, data[i].sec)) * 2) {
            ans += (data[i-1].fir - back) * 2;
            back = data[i].sec;
        } else {
            back = min(back, data[i].sec);
        }
        //cout << " i = " << i << " : " << back << endl;
    }

    ans += (data.back().fir - back) * 2;
    ans += (n + 1) - data.back().fir;

    cout << ans << endl;
    return 0;
}

