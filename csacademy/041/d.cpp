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
#define int3(x, y, z) Int(x); int2(y, z);
#define fir first
#define sec second
#define ffir first.first
#define fsec first.second
#define sfir second.first
#define ssec second.second

//int dxy[5] = {0, 1, 0, -1, 0};
// assign avl ncm dijkstra geo2 kruskal graph uf lca BIT
// matrix dinic next_combination topcoder

signed main()
{
    Int(n);
    Int(funami);
    int seca, secb;
    vp ans;

    Rep(i, n) {
        Int(tmp);
        if (i == 1) seca = tmp;
        ans.pb(i_i(1, tmp));
    }

    cin >> funami;
    cin >> funami;
    secb = funami;
    Rep(i, n-1) {
        Int(tmp);
        ans.pb(i_i(funami, tmp));
        funami = tmp;
    }
    if (seca != secb) {
        std::cout << -1 << std::endl;
        return 0;
    }
    std::cout << ans.size() << std::endl;
    rep(i, ans.size()) {
        std::cout << ans[i].fir << " " << ans[i].sec << std::endl;
    }



    return 0;
}

