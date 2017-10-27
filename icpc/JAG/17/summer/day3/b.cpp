#include <bits/stdc++.h>

using namespace std;

#define int long long
#define INF 1001000100010001000
#define vi vector<int>

signed main()
{
    int s, t, n;
    cin >> s >> t >> n;

    vi data(n);
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }

    vi sum(n, 0);
    sum[0] = data[0];
    for (int i = 1; i < n; i++) {
        sum[i] += sum[i-1] + data[i];
    }
    int yui = INF;
    for (int i = 0; i < n; i++) {
        yui = min(yui, sum[i]);
        //cout << sum[i] << " ";
    }
    //cout << endl;

    int ans = 0, dist = s - t;
    //cout << dist << " " << sum[n-1] << endl;
    if (dist > -yui && sum[n-1] < 0) {
        int tmp = (dist + yui) / (-sum[n-1]) + !!((dist + yui)%(-sum[n-1]));
        ans += tmp * n;
        dist += tmp * sum[n-1];
    } else if (sum[n-1] >= 0 && s - t > -yui) {
        cout << -1 << endl;
        return 0;
    }
    //cout << dist << " " << ans << endl;

    for (int i = 0; i < n; i++)  {
        if (dist + sum[i] <= 0) {
            cout << ans + i+1 << endl;
            return 0;
        }
    }
    
    return 0;
}
