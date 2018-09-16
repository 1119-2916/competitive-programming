#include<bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < n; i++)
#define int long long
#define fir first
#define sec second

signed main(void)
{
    cout << 10 << endl;
    rep(i, 10) {
        cout << 100000 << endl;
        vector<pair<int, char>> data;
        char ch = 'A', add = 0;
        rep(i, 100000 / 2) {
            data.push_back(make_pair(1000000000, ch + add));
            add = (add + 1) % 26;
            cout << data[i].sec << " " << data[i].fir << endl;
        }
        reverse(data.begin(), data.end());
        rep(i, data.size()) {
            cout << data[i].sec << " " << data[i].fir << endl;
        }
    }

    return 0;
}
