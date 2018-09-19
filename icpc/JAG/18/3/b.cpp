#include<bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < n; i++)
#define int long long 
#define fir first
#define sec second
#define all(a) (a).begin(), (a).end()

signed main()
{
    int n; cin >> n;
    vector<pair<int, string>> data(n);
    rep(i, n) {
        string st; cin >> st;
        int a; cin >> a;
        data[i] = make_pair(a, st);
    }
    sort(all(data));

    int m; cin >> m;
    int ptr = 0, yui = -1;
    rep(i, m) {
        string input;
        cin >> input;

        while (1) {
            if (data.size() <= ptr) {
                cout << "No" << endl;
                return 0;
            }
            if (data[ptr].fir == yui) {
                ptr++;
                continue;
            }
            if (data[ptr].sec == input) {
                yui = data[ptr].fir;
                ptr++;
                break;
            } else {
                ptr++;
            }
        }
    }

    cout << "Yes" << endl;
    
    return 0;
}
