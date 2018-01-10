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
    int l = 0, r = 100000;
    while (r - l > 1) {
        int mid = (r + l) / 2;
        cout << "Q " << mid << endl;
        Int(tmp);
        if (tmp) l = mid;
        else r = mid;
    }

    int keta = l;
    //Int(keta);
    vi funami(8, 1);
    Rep(i, 8) funami[i] = funami[i-1] + pow(5, i);
    //rep(i, funami.size()) cout << funami[i] << endl;

    int ans = 0;
    for (int i = 7; i >= 0; i--) {
        if (keta >= funami[i]) {
            int tmp = keta / funami[i];
            keta -= tmp * funami[i];
            tmp *= (int)pow(5, i+1);
            ans += tmp;
        }
    }

    cout << "A " << ans << endl;

    return 0;
}
