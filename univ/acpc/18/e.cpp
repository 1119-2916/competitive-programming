#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < n; i++) 
#define Rep(i, n) for (int i = 1; i < n; i++)
#define pb emplace_back
#define vi vector<int>
#define in(a, b, c) a <= b && b < c


signed main()
{
    int n; cin >> n;
    vi data(n);
    vi funami(n);
    rep(i, n) cin >> data[i];
    rep(i, n-1) {
        funami[i] = data[i+1] - data[i];
    }

 /*   rep(i, n) {
    cout << funami[i] << " ";
    }
    cout << endl;*/

    int ans = 0;
    rep(i, n-1) {
        if (i % 2) {
            if (funami[i] > 0) {
                if (i + 1 < n-1 && funami[i] < -funami[i+1]) {
                    funami[i+2] += funami[i+1];
                    funami[i+1] *= -1;
                } else {
                    funami[i+1] += funami[i];
                    funami[i] *= -1;
                }
                ans++;
            }
        } else {
            if (funami[i] < 0) {
                if (i + 1 < n-1 && funami[i] > -funami[i+1]) {
                    funami[i+2] += funami[i+1];
                    funami[i+1] *= -1;
                } else {
                    funami[i+1] += funami[i];
                    funami[i] *= -1;
                }
                ans++;
            }
        }
    }

    //cout << ans << endl;

    rep(i, n-1) {
        funami[i] = data[i+1] - data[i];
    }
    int cnt = 0;
    rep(i, n-1) {
        if (i % 2) {
            if (funami[i] < 0) {
                funami[i+1] += funami[i];
                funami[i] *= funami[i]-1;
                cnt++;
            }
        } else {
            if (funami[i] > 0) {
                funami[i+1] += funami[i];
                funami[i] *= funami[i]-1;
                cnt++;
            }
        }
    }

//    cout << cnt << endl;

    cout << min(ans, cnt) << endl;

    return 0;
}

