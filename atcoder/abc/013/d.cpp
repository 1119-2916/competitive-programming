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
    int2(n, m);
    Int(d);

    vi state(n);
    rep(i, n) {
        state[i] = i;
    }

    rep(i, m) {
        Int(tmp);
        swap(state[tmp-1], state[tmp]);
    }
    /*
     * {{{
    vp calc(n);
    rep(i, n) {
        calc[i].sec = state[i];
        calc[i].fir = i;
    }
    sort(all(calc));
    rep(i, n) {
        state[i] = calc[i].sec;
    }
    */ // }}}

    vvi solve(30, vi(n));
    rep(i, n) {
        solve[0][state[i]] = i;
    }
    rep(i, 29) {
        rep(j, n) {
            solve[i+1][j] = solve[i][solve[i][j]];
        }
    }

    vi ans(n);
    rep(i, n) {
        ans[i] = i;
    }

    for (int i = 0; (1 << i) <= d; i++) {
        if (d & (1 << i)) {
 //           cout << "num : "<< (1 << i) << endl;
            vi nxt(n);
            rep(j, n) {
 //               std::cout << solve[i][j] << std::endl;
                nxt[j] = solve[i][ans[j]];
            }
            ans = nxt;
        }
    }
    rep(i, n) {
        std::cout << ans[i] + 1 << std::endl;
    }
   
    /*
    rep(i, 30) {
        rep(j, n) {
            std::cout << solve[i][j] << " ";
        }cout << endl;
    }
    */

    return 0;
}



