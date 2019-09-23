#include <bits/stdc++.h>

#define vi vector<int>
#define int long long
#define rep(i, n) for (int i = 0; i < n; i++) 
#define all(x) (x).begin(), (x).end()

using namespace std;

signed main()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> data(n * 2);
    rep(i, n) {
        int l, r;
        cin >> l >> r;
        data[i*2] = {l, 1};
        data[i*2+1] = {r+1, -1};
    }
    sort(all(data));
    
    rep(i, data.size()) {
        //cout << data[i].first << " " << data[i].second << endl;
        if (i) {
            data[i].second += data[i-1].second;
        }
    }
    /*
    rep(i, data.size()) {
        cout << data[i].first << " " << data[i].second << endl;
    }
    */
    int mx = -1;
    rep(i, data.size()) {
        if (mx < data[i].second) mx = data[i].second;
    }

    if (mx % 2) {
        int ans = 0;
        for (int i = data.size()-1; i >= 0; i--) {
            if (data[ans].second < data[i].second) {
                ans = i;
            }
        }
        cout << (mx-1) * m + (data[ans+1].first-1) << endl;
    } else {
        int ans = data.size()-1;
        rep(i, data.size()) {
            if (data[ans].second < data[i].second) {
                ans = i;
            }
        }
        //cout << data[ans].first << " " << data[ans].second << endl;
        cout << (mx-1) * m + (m - data[ans].first) << endl;
    }


    return 0;
}
