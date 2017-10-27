#include <bits/stdc++.h>

using namespace std;

#define INF 1001000100010001000
#define MOD 1000000007
#define EPS 1e-10
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
    int st = 0, wt = 0;

    if (e == 100) {
        if (c <= f) {
            std::cout << c << " " << c << std::endl;
        } else {
            std::cout << "0 0" << std::endl;
        }
        return 0;
    }

    rep(i, 101000) {
        if (i * 100 * a > f) {
            break;
        }
        rep(j, 101000) {
            if (!i && !j) continue;
            if (i * 100 * a + j * 100 * b > f) {
                break;
            }
            //std::cout << i << " " << j << std::endl;
            int tmp = f - i * 100 * a - j * 100 * b;
            tmp = min(tmp, e * (i*a+j*b) );
            //std::cout << tmp << std::endl;
            int yui = 0;
            for (int k = 0; k <= tmp; k += d) {
                yui = tmp - ((tmp - k) % c);
                //std::cout << " " << yui << std::endl;
                if (ans < (double)yui / 
                        (double)( (i*a*100)+(j*b*100) + yui)) {
                    ans = (double)yui /
                        (double)( (i*a*100)+(j*b*100) + yui);
                    st = yui;
                    wt = (i*a*100)+(j*b*100) + yui;
                }
            }
        }
    }
    cout << wt << " " << st << endl;

    return 0;
}

