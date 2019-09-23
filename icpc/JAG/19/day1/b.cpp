#include <bits/stdc++.h>

using namespace std;

#define int long long 
#define rep(i, N) for (int i = 0; i < N; i++)
#define vi vector<int>

signed main()
{
    int n;
    cin >> n;
    vi data(n);
    rep(i, n) {
        cin >> data[i];
    }

    set<int> pr;
    rep(i, n) {
        int tmp = data[i];
        for (int i = 2; i * i <= tmp; i++) {
            if (tmp % i == 0) {
                while (tmp % i == 0) {
                    tmp /= i;
                }
                pr.insert(i);
            }
        }
        if (tmp >= 2) pr.insert(tmp);
    }

    int ans = 0;
    for (auto i : pr) {
        int p = i, tmp = 0;
        //cout << p << endl;
        rep(j, n) {
            if (data[j] % p == 0) {
                tmp += data[j];
            }
        }
        ans = max(ans, tmp);
    }
    cout << ans << endl;

    return 0;
}

