#include <bits/stdc++.h>

using namespace std;

#define INF 1001000100010001000
#define int long long 
#define rep(i, n) for (int i = 0; i < n; i++)
#define vi vector<int>

signed main()
{
    int n, m;
    cin >> n >> m;

    vi data(n);
    rep(i, n) {
        cin >> data[i];
    }

    int head = INF, res = 0, yui = 0;
    rep(i, n) {
        if (i) {
            if (data[i] < data[i-1]) {
                if (res >= data[i]) {
                    res += data[i];
                    yui += data[i];
                    cout << head << endl;
                } else {
                    head--;
                    res = (m - yui - res) % data[i];
                    yui += data[i];
                    cout << head << endl;
                }
            } else { // data[i] >= data[i-1]
                head = (m - yui) / data[i] + 1;
                res = (m - yui) % data[i];
                yui += data[i];
                cout << head << endl;
            }
        } else {
            head = m / data[i] + 1;
            res = m % data[i];
            yui += data[i];
            cout << head << endl;
        }
        cout << head << " " << res << " " << yui << endl;
    }

    return 0;
}


