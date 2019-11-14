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
    vector<pii> data(n);
    for (int i = 0; i < n; i++) {
        cin >> data[i].fir;
        data[i].sec = i;
    }
        
    int p = -1;
    vi ans;
    rep(_, k+1) {
        sort(all(data));
        reverse(all(data));
        int np = -1;
        rep(i, n) {
            if (p != data[i].sec) {
                data[i].fir--;
                ans.pb(data[i].sec);
                np = data[i].sec;
            }
        }
        p = np;
    }

    rep(i, n) {
        if (data[i].fir < 0) {
            std::cout << -1 << std::endl;
            return 0;
        }
    }

    std::cout << ans.size() << std::endl;
    rep(i, ans.size()) {
        cout << ans[i]+1 << " ";
    }
    cout << endl;

    return 0;
}