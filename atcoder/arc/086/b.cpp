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
    vector<int> data(n);
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }

    vector<i_i> ans(0);
    
    auto yui = max_element(all(data)), kyoko = min_element(all(data));

    if (abs(*yui) < abs(*kyoko)) {
        // 負
        //cout << "hu" << endl;
        ans.pb(mp(kyoko - data.begin()+1, n));
        ans.pb(mp(kyoko - data.begin()+1, n));
        for (int i = n; i >= 2; i--) {
            ans.pb(mp(i, i-1));
            ans.pb(mp(i, i-1));
        }
    } else {
        ans.pb(mp(yui - data.begin()+1, 1));
        ans.pb(mp(yui - data.begin()+1, 1));
        Rep(i, n) {
            ans.pb(mp(i, i+1));
            ans.pb(mp(i, i+1));
        }
    }

    cout << ans.size() << endl;
    rep(i, ans.size()) {
        cout << ans[i].fir << " " << ans[i].sec << endl;
    }

    /*
    rep(i, ans.size()) {
        data[ans[i].sec] += data[ans[i].fir];
    }
    rep(i, n) {
        cout << data[i] << " ";
    }
    cout << endl;
    */


    return 0;
}




