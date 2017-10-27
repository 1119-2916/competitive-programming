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
#define mp make_pair
#define i_i pair<int, int>
#define vi vector<int>
#define vvi vector<vi >
#define vb vector<bool>
#define vvb vector<vb >
#define vp vector< i_i >
#define all(a) (a).begin(), (a).end()
#define Int(x) int x; scanf("%lld", &x);
 
//int dxy[5] = {0, 1, 0, -1, 0};
// assign
 
signed main()
{
    Int(n);

    vi c(n);

    rep(i, n) {
        cin >> c[i];
    }

    sort(all(c));

    int pt = 1, bef = c[0], cnt = 1;

    vp cs;

    while (pt < n) {

        if (bef != c[pt]) {
            cs.pb(mp(bef, cnt));
            cnt = 1;
            bef = c[pt++];
        } else {
            cnt++;
            pt++;
        }

    }

    cs.pb(mp(bef, cnt));

    int ret = 0, less = 0;

    rep(i, cs.size()) {
        if (cs[i].second % 2) {
            ret++;
        } else {
            less++;
        }
    }

    cout << ret + less - (less % 2) << endl;

    return 0;
}

