#include <bits/stdc++.h>

using namespace std;

#define INF 1001000100010001000
#define MOD 1000000007
#define EPS 1e-10
#define int long long
#define rep(i, N) for (int i = 0; i < N; i++)
#define Rep(i, N) for (int i = 1; i < N; i++)
#define For(i, a, b) for (int i = (a); i < (b); i++)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define i_i pair<int, int>
#define vi vector<int>
#define vvi vector<vi >
#define vb vector<bool>
#define vvb vector<vb >
#define vp vector< i_i >
#define all(a) (a).begin(), (a).end()
#define Int(x) int x; cin >> x;
#define int2(x, y) Int(x); Int(y);
#define int3(x, y, z) Int(x); int2(y, z);
#define fir first
#define sec second
#define ffir first.first
#define fsec first.second
#define sfir second.first
#define ssec second.second
#define Decimal fixed << setprecision(10)

//int dxy[5] = {0, 1, 0, -1, 0};
// cmd

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int2(n, x);
    vector<int> data(n);
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }
    vi ans(n, 0);
    int cnt = x;
    Rep(i, n) {
        cnt += min(x, data[i] - data[i-1]);
    }
    ans[n-1] = cnt;
    ans[0] = x;

    vi diff;
    diff.pb(x);
    Rep(i, n) {
        diff.pb(data[i]-data[i-1]);
    }
    ///*
    rep(i, diff.size()) {
        cout << diff[i] << " ";
    }
    cout << endl;
    //*/

    for (int i = n-2; i >= 1; i--) {
        cout << "call : " << i << " ";
        int tmp = INF, ptr = 0;
        rep(j, i+1) {
            if (tmp > (min(x, diff[j]) + min(x, diff[j+1]) - x)) {
                tmp = (min(x, diff[j]) + min(x, diff[j+1]) - x);
                ptr = j;
            }
        }
        cout << tmp << "ptr " << ptr << endl;
        ans[i] = cnt -= max(tmp, 0LL);
        diff[ptr] += diff[ptr+1];
        for (int j = ptr+1; j < i+1; j++) {
            diff[j] = diff[j+1];
        }
        ///*
        rep(j, i+1) {
            cout << diff[j] << " ";
        }
        cout << endl;
        //*/
    }

    rep(i, n) {
        cout << ans[i] << endl;
    }

    return 0;
}


