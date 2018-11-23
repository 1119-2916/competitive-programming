#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < n; i++)

using namespace std;

signed main()
{
    int a, b;
    cin >> a >> b;

    while (a) {

        vector<int> d(a, 0), c(b, 0);
        rep(i, a) {
            cin >> d[i];
        }
        rep(i, b) {
            cin >> c[i];
        }

        rep(i, a) {
            rep(j, b) {
                if (d[i] == c[j]) {
                    c[j] = 0;
                    break;
                }
            }
        }

        int ans = 0;
        rep(i, a) {
            ans += d[i];
        }
        rep(i, b) {
            ans += c[i];
        }

        cout << ans << endl;
        cin >> a >> b;
    }

    return 0;
}
