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
#define eb emplece_back
#define mp make_pair
#define i_i pair<int, int>
#define vi vector<int>
#define vvi vector<vi >
#define vb vector<bool>
#define vvb vector<vb >
#define vp vector< i_i >
#define all(a) (a).begin(), (a).end()
#define Int(x) int x; scanf("%lld", &x);
#define int2(x, y) int x, y; scanf("%lld %lld", &x, &y);
#define fir first
#define sec second
#define ffir first.first
#define fsec first.second
#define sfir second.first
#define ssec second.second

//int dxy[5] = {0, 1, 0, -1, 0};
// assign avl ncm dijkstra geo2 kruskal graph uf lca BIT
// matrix dinic

signed main()
{
    Int(n);
    vi l(n), r(n);
    rep(i, n) {
        cin >> l[i];
    }
    rep(i, n) {
        cin >> r[i];
    }

    vb rcheck(n, false), lcheck(n, false);
    rcheck[n-1] = true; lcheck[0] = true;
    Rep(i, n) {
        if (l[i] != l[i-1]) {
            lcheck[i] = true;
        }
    }

    for (int i = n-1; i > 0; i--) {
        if (r[i] != r[i-1]) {
            rcheck[i-1] = true;
        }
    }

    rep(i, n) {
        if (rcheck[i] && lcheck[i] && 
                r[i] != l[i]) {
            std::cout << 0 << std::endl;
            return 0;
        }
        if (rcheck[i] && !lcheck[i] && 
                r[i] > l[i]) {
            std::cout << 0 << std::endl;
            return 0;
        }
        if (!rcheck[i] && lcheck[i] && 
                r[i] < l[i]) {
            std::cout << 0 << std::endl;
            return 0;
        }
    }
    /*
    rep(i, n) {
        cout << lcheck[i] << " ";
    }
    cout << endl;
    rep(i, n) {
        cout << rcheck[i] << " ";
    }
    cout << endl;
    */


    int ans = 1;
    rep(i, n) {
        if (!rcheck[i] && !lcheck[i]) {
            ans *= min(r[i], l[i]);
            ans %= MOD;
        }
    }
    std::cout << ans << std::endl;

    return 0;
}



