#include <bits/stdc++.h>

using namespace std;

#define int long long 
#define i_i pair<int, int>
#define vp vector<i_i>

signed main()
{
    int n, k;
    cin >> n >> k;
    vp data(n);
    for (int i = 0; i < n; i++) {
        cin >> data[i].first >> data[i].second;
    }

    int pos = 1, ans = 0, nin = 0, now = 0;
    for (int i = 0; i < n; i++) {
        //std::cout << pos << " " << nin << " " << now << 
        //    " " << ans << std::endl;
        int dist = abs(pos - data[i].second);
        int time = data[i].first - now;
        if (nin && (time >= pos - 1 + data[i].second - 1)) {
            ans += nin * (pos - 1);
            nin = 0;
        }
        if (dist > time) {
            cout << -1 << endl;
            return 0;
        }
        ans += nin * time;
        nin++;
        if (nin > k) {
            cout << -1 << endl;
            return 0;
        }
        pos = data[i].second;
        now = data[i].first;
    }

    ans += nin * (pos - 1);
    std::cout << ans << std::endl;
    return 0;
}
    

    
