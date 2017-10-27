#include <bits/stdc++.h>

using namespace std;

#define INF 1001000100010001000
#define MOD 1000000007
#define EPS 1e-6
#define int long long
#define double long double
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

    int3(a, b, c);
    int3(d, e, f);

    double ans = 0.0;
    int sato = 0, wt = 0;

    rep(i, 101) {
        if (i * 100 * a > f) {
            break;
        }
        rep(j, 101) {
            if (!i && !j) continue;
            if (i * 100 * a + j * 100 * b > f) {
                break;
            }
            std::cout << i << " " << j << std::endl;
            int water = i * 100 * a + j * 100 * b;
            int yui = (f - water);
            yui = min(yui, (i*a+j*b) * e);
            for (int k = 0; k <= yui; k += d) {
                if (k + water > f) break;
                int st = (yui - ((yui - k) % c));
                std::cout <<  " " << st << " " << water << std::endl;
                if (ans > EPS) {
                    if (ans < (double)st / (double)(st + water)) { 
                        ans = (double)st / (double)(st + water);
                        sato = st;
                        wt = st + water;
                    }
                } else {
                    if (sato * (st + water) < st * wt) {
                        ans = (double)st / (double)(st + water);
                        sato = st;
                        wt = st + water;
                    }
                }
            }
        }
    }
    cout << wt << " " << sato << endl;

    return 0;
}

