#include <bits/stdc++.h>

using namespace std;

#define int long long 
#define rep(i, N) for (int i = 0; i < N; i++)
#define vi vector<int>

signed main()
{
    int n;
    cin >> n;
    int zx, zv;
    cin >> zx >> zv;
    rep(i, n) {
        int x, v; cin >> x >> v;
        if (zv == v) {
            cout << -1 << endl;
        } else {
            double t = (double)(x - zx) / (double)(zv - v);
        }
    }

    return 0;
}

