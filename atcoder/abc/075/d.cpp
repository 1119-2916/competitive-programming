#include <bits/stdc++.h>

using namespace std;

#define INF 6001000100010001000
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
#define Int(x) int x; cin >> x;
#define int2(x, y) Int(x); Int(y);
#define int3(x, y, z) Int(x); int2(y, z);
#define fir first
#define sec second
#define ffir first.first
#define fsec first.second
#define sfir second.first
#define ssec second.second

//int dxy[5] = {0, 1, 0, -1, 0};
// assign avl ncm dijkstra geo2 kruskal graph uf lca BIT
// matrix dinic next_combination topcoder lcm

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int2(n, K);
    vp data(n);
    rep(i, n) {
        cin >> data[i].fir >> data[i].sec;
    }

    int ans = INF;
    rep(i, n) {
        rep(j, n) {
            rep(k, n) {
                rep(l, n) {
                    int sx = data[i].fir, sy = data[j].sec,
                        ex = data[k].fir, ey = data[l].sec;
                    int cnt = 0;
                    if (sx > ex || sy > ey) continue;
                    rep(y, n) {
                        if (sx <= data[y].fir && data[y].fir <= ex &&
                                sy <= data[y].sec && data[y].sec <= ey) {
                            cnt++;
                        }
                    }
                    if (cnt >= K) {
                        ans = min(ans, max(0LL, ((ex - sx)*(ey - sy))));
                    }
                }
            }
        }
    }
    cout << ans << endl;







    return 0;
}
