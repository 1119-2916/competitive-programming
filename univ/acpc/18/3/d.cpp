#include <bits/stdc++.h>

using namespace std;

#define int long long 
#define INF 1001000100010001000
#define rep(i, n) for (int i = 0; i < n; i++) 
#define pb emplace_back

signed main(void)
{
    int n; cin >> n;
    vector<string> input(n);
    rep(i, n) {
        cin >> input[i];
    }

    vector<int> alp(30, INF);
    int ans = 0;
    rep(i, n) {
        ans = min(ans + 1, alp[input[i][0]-'a']);
        alp[input[i][0]-'a'] = ans;
//        cout << ans << endl;
    }

    cout << ans << endl;


    return 0;
}

