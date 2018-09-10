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
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vi >
#define vb vector<bool>
#define vvb vector<vb >
#define vp vector< pii >
#define all(a) (a).begin(), (a).end()
#define Int(x) int x; cin >> x;
#define int2(x, y) Int(x); Int(y);
#define int3(x, y, z) Int(x); int2(y, z);
#define in(x, a, b) ((a) <= (x) && (x) < (b))
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

    int2(n, k);
    vi aa, bb;
    for (int i = 0; i < n; i++) {
        Int(tmp);
        if (tmp < 0) aa.pb(-tmp);
        else bb.pb(tmp);
    }
    
    int ans = INF;
    sort(all(aa));

    rep(i, aa.size()) {
        int tmp = INF;
        if (i < k && k - i - 1 < bb.size()) {
            tmp = aa[i] * 2;
            tmp += bb[k - i - 1 - 1];
        } else if (i >= k) {
            tmp = aa[i];
        }
        cout << tmp << endl;
        ans = min(ans, tmp);
    }

    if (bb.size() >= k) ans = min(ans, bb[k-1]);

    cout << ans << endl;

    return 0;
}
