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

    int2(n, c);
    vi funami(202000, 0);
    vector<vp> toshino(c+1, vp());
    rep(i, n) {
        int3(a, b, d);
        toshino[d].pb({a, b});
    }
    vp query;
    rep(i, toshino.size()) {
        cout << i << endl;
        sort(all(toshino[i]));
        int p = 0, r = 1;
        while (r < toshino[i].size()) {
            if (toshino[i][r-1].sec == toshino[i][r].fir) {
                r++;
            } else {
                query.pb({toshino[i][p].fir, toshino[i][r-1].sec});
                p = r;
                r++;
            }
        }
        query.pb({toshino[i][p].fir, toshino[i][r-1].sec});
    }

    cout << "query" << endl;
    rep(i, query.size()) {
        cout << query[i].fir << " " << query[i].sec << endl;
    }

    Rep(i, funami.size()) {
        funami[i] += funami[i-1];
    }

    int ans = 0;
    rep(i, funami.size()) {
        ans = max(ans, funami[i]);
    }

    cout << ans << endl;

    return 0;
}
