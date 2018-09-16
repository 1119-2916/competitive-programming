#include<bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < n; i++)
#define int long long

signed main(void)
{
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<pair<int, int>> input;
        rep(i, n) {
            int a, b; cin >> a >> b;
            //input.emplace_back({a, 1});
            //input.emplace_back({b, -1});
            input.push_back({a, 1});
            input.push_back({b, -1});
        }
        sort(input.begin(), input.end());
        int ans = 0, yui = 0;
        rep(i, input.size()) {
            yui += input[i].second;
            ans = max(ans, yui);
        }
        cout << ans << endl;
    }
    return 0;
}
