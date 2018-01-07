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
    vector<int> yui(n), kyoko(n);
    vector<i_i> data(n);
    for (int i = 0; i < n; i++) {
        cin >> yui[i] >> kyoko[i];
        if (yui[i] > kyoko[i]) swap(yui[i], kyoko[i]);
        data[i].fir = yui[i]; data[i].sec = kyoko[i];
    }

    sort(all(yui)); sort(all(kyoko));
    int ans = (yui.back() - yui[0]) * (kyoko.back() - kyoko[0]);

    bool min_ok = true, max_ok = true;
    if (yui[0] == yui[1]) min_ok = false;
    if (kyoko[n-1] == kyoko[n-2]) min_ok = false;

    sort(all(data));
    swap(data[0].fir, data[0].sec);
    sort(all(data));

    int emin = INF, emax = 0;
    rep(i, n-1) {
        if (data[i].sec == yui[0] && min_ok) continue;
        if (data[i].sec == kyoko[n-1] && max_ok) continue;
        /*
        emin = min({emin, data[i+1].fir, data[i].sec});
        emax = max({emax, data[n-1].fir, data[i].sec});
        ans = min(ans, (kyoko[n-1] - yui[0]) * (emax - emin));
        */
        emin = min({emin, data[i].sec});
        emax = max({emax, data[i].sec});
        ans = min(ans, (kyoko[n-1] - yui[0]) * 
                (max(emax, data[n-1].fir) - min(emin, data[i+1].fir)));
    }
    emin = min(emin, data[n-1].sec);
    emax = max(emax, data[n-1].sec);
    cout << min(ans, (kyoko[n-1] - yui[0]) * (emax - emin)) << endl;

    /*
    swap(data[0].fir, data[0].sec);
    sort(all(data));
    rep(i, n) cout << data[i].fir << " " << data[i].sec << endl;

    int ans2 = kyoko.back() - yui[0], funami = data[0].fir,
        toshino = data[n-1].fir;

    ans = min(ans, ans2 * (toshino - funami));
    rep(i, n) {
        if (data[i].sec == yui[0] && min_ok) continue;
        if (data[i].sec == kyoko[n-1] && max_ok) continue;
        toshino = min(toshino, data[i].sec);
        funami = max(funami, data[i].sec);
        cout << ans2 * (toshino - funami) << endl;
        ans = min(ans, ans2 * (toshino - funami));
    }
    cout << ans << endl;
    */

    return 0;
}
