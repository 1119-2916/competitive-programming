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

    vi data(n);
    rep(i, n) cin >> data[i];

    int ans = 0, pos = -1, cnt = 0;
    bool state = data[0] < data[1];
    rep(i, n-1) {
        if (data[i] != data[i+1]) {
            state = data[i] < data[i+1];
            cnt = 2;
            pos = i+1;
            break;
        }
    }
    if (pos == -1) {
        cout << 1 << endl;
        return 0;
    }

    for (int i = pos+1; i < n; i++) {
        if (data[i-1] == data[i]) {
            ;
        } else if (state == (data[i-1] < data[i])) {
            cnt++;
        } else {
            state = !state;
            ans = max(cnt, ans);
            cnt = 2;
        }
    }

    ans = max(ans, cnt);

    cout << ans << endl;

    return 0;
}
