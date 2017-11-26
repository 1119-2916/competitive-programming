#include <bits/stdc++.h>

using namespace std;

#define int long long
#define vi vector<int>

signed main()
{
    int n, h, w;
    cin >> n >> h >> w;

    vi data(n);
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }

    int ans = 0;
    for (int i = 0; i < n; i += 2) {
        int l1 = w - data[i], r1 = data[i];
        int l2 = data[i+1], r2 = w - data[i+1];
        ans += (min(l1, l2) + min(r1, r2)) * h;
    }
    cout << ans << endl;

    return 0;
}

