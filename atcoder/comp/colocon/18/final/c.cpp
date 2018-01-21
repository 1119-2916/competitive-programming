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

    Int(n);
    vector<i_i> data(n);
    vi ans(n);
    for (int i = 0; i < n; i++) {
        cin >> data[i].fir;
        data[i].sec = i;
        ans[i] = data[i];
    }
    sort(all(data));
    //rep(i, n) cout << data[i] << " "; cout << endl;

    rep(i, n) {
        for (int j = i+1; j < n; j++) {
            if (data[i] + (j-i)*(j-i) < ans[j]) {
                ans[j] = data[i] + (j-i)*(j-i);
            } else {
                break;
            }
        }
        for (int j = i-1; j >= 0; j--) {
            if (data[i] + (i-j)*(i-j) < ans[j]) {
                ans[j] = data[i] + (i-j)*(i-j);
            } else {
                break;
            }
        }
        rep(i, n) cout << ans[i] << " "; cout << endl;
    }
    rep(i, ans.size()) {
        cout << ans[i] << endl;
    }


    return 0;
}

