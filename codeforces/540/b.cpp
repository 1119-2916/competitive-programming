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

    Int(n);
    vector<int> data(n);
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }

    vi mmn, mm;
    mmn.pb(0); mm.pb(0);
    rep(i, n) {
        if (i % 2) {
            int tmp = mmn.back();
            mmn.pb(tmp + data[i]);
        } else {
            int tmp = mm.back();
            mm.pb(tmp + data[i]);
        }
    }

    rep(i, mmn.size()) cout << mmn[i] << " ";
    cout << endl;
    rep(i, mm.size()) cout << mm[i] << " ";
    cout << endl;

    int ans = 0;
    rep(i, n) {
        int yui = 0, kyoko = 0;
        yui = mmn[i/2];
        kyoko = mm[i/2];
        yui += (mm.back() - mm[i/2]);
        kyoko += (mmn.back() - mmn[i/2]);
        if (yui == kyoko) ans++;
        cout << yui << " " << kyoko << endl;
    }

    std::cout << ans << std::endl;

    return 0;
}
