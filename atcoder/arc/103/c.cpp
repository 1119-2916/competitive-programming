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
    
    map<int, int> funami, toshino;
    rep(i, n) {
        if (i % 2) {
            funami[data[i]]++;
        } else {
            toshino[data[i]]++;
        }
    }

    vp yui, kyoko;
    yui.pb({0, 0});
    kyoko.pb({0, 0});
    for (auto i : funami) {
        yui.pb({i.sec, i.fir});
    }
    for (auto i : toshino) {
        kyoko.pb({i.sec, i.fir});
    }

    sort(all(yui));
    reverse(all(yui));
    sort(all(kyoko));
    reverse(all(kyoko));

    /*
    cout << "yui : " << endl;
    rep(i, yui.size()) {
        cout << yui[i].fir << " " << yui[i].sec << endl;
    }

    cout << "kyoko : " << endl;
    rep(i, kyoko.size()) {
        cout << kyoko[i].fir << " " << kyoko[i].sec << endl;
    }
    */

    if (yui[0].sec == kyoko[0].sec) {
        cout << min(n - yui[0].fir - kyoko[1].fir, n - yui[1].fir - kyoko[0].fir) << endl;
    } else {
        cout << n - yui[0].fir - kyoko[0].fir << endl;
    }

    return 0;
}
