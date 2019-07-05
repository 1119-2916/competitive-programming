#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < n; i++)
#define vi vector<int>

bool clear(vi &data, int x)
{
    return data[0] < x+1;
}

bool check(vi &data, int m, int x)
{
    int lv = 1, step;
    for (step = 1; step < m-1; step++) {
        int p = lower_bound(data.begin(), data.end(), lv) - data.begin();
        if (p) {
            if (data[p] < lv+x) {
                int tmp = max({1, x - abs(lv - data[p]), x - abs(lv - data[p-1])});
                lv += tmp;
            } else {
                lv += max(1, x - abs(lv - data[p-1]));
            }
        } else {
            if (data[p] < lv+x) {
                lv += max(1, x - abs(lv - data[p]));
            } else {
                assert(0);
            }
        }
    }
    return !(data.back() < lv + x);
}

void solve(vi &data, int m)
{
    int left = 0;
    int l = 1, r = 20001000;
    while (r - l > 1) {
        int mid = (r + l) / 2;
        if (clear(data, mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    left = r;
    if (clear(data, 1)) {
        left = 1;
    }
    //cout << left << endl;
    
    if (!check(data, m, left)) {
        cout << -1 << endl;
        return;
    }

    int right = 20001000;
    while (right - left > 1) {
        int mid = (right+left)/2;
        if (check(data, m, mid)) {
            left = mid;
        } else {
            right = mid;
        }
    }
    cout << left << endl;
    return;
}

int main()
{
    int n, m;
    while (cin >> n >> m, n) {
        vi data(n);
        rep(i, n) {
            cin >> data[i];
        }
        solve(data, m);
    }
    return 0;
}
