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
#include <boost/multiprecision/cpp_dec_float.hpp>

namespace mp = boost::multiprecision;
//int dxy[5] = {0, 1, 0, -1, 0};
// assign avl ncm dijkstra geo2 kruskal graph uf lca BIT
// matrix dinic next_combination topcoder lcm

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int2(sx, sy);
    int2(gx, gy);
    if (sy > gy) {
        swap(sy, gy);
        swap(sx, gx);
    }

    //if (sx == gx || sy == gy) while (1);

    //std::cout << sx << " " << sy << " " << gx << " " << gy << std::endl;
    vp data;
    if (sy == gy) {
        if (sx > gx) {
            swap(sx, gx);
        }
        Int(n);
        rep(i, n) {
            i_i tmp;
            cin >> tmp.fir >> tmp.sec;
            if (sx <= tmp.fir && tmp.fir <= gx && 
                    sy <= tmp.sec && tmp.sec <= gy) {
                //double ans = (gx - sx) * 100;
                 mp::cpp_dec_float_100 diff = 
                     (1.0L - 3.141592653589793238L / 2.0L);
                mp::cpp_dec_float_100 ans = (gx - sx) * 5.0L;
                //std::cout << ans << " " << diff << std::endl;
        //printf("%.15Lf\n", 20.0L * (ans - diff));
                  //  (1.0L - 3.141592653589793238L / 2.0L)));
                //printf("%.15Lf\n", ans - diff);
                cout << std::setprecision(std::numeric_limits
                        <decltype(x)>::digits10 + 1)
              << 20.0L * (ans - diff) << endl;
                return 0;
            }
        }
        printf("%.15Lf\n", (gx - sx) * 100.0L);
        return 0;
    }

    if (sx == gx) {
        if (sy > gy) {
            swap(sy, gy);
        }
        Int(n);
        rep(i, n) {
            i_i tmp;
            cin >> tmp.fir >> tmp.sec;
            if (sx <= tmp.fir && tmp.fir <= gx && 
                    sy <= tmp.sec && tmp.sec <= gy) {
                //double ans = (gy - sy) * 100;
                double diff = (1.0L - 3.141592653589793238L / 2.0L);
                //std::cout << ans << " " << diff << std::endl;
        printf("%.15Lf\n", 20.0L * ((gx - sx) * 5.0L - diff));
                //    (1.0L - 3.141592653589793238L / 2.0L)));
                //printf("%.15Lf\n", ans - diff);
                return 0;
            }
        }
        printf("%.15Lf\n", (gy - sy) * 100.0L);
        return 0;
    }

    if (sx < gx) {

        Int(n);
        rep(i, n) {
            i_i tmp;
            cin >> tmp.fir >> tmp.sec;
            if (sx <= tmp.fir && tmp.fir <= gx && 
                    sy <= tmp.sec && tmp.sec <= gy) {
                data.pb(tmp);
            }
        }
        sort(all(data));
        /*
        rep(i, data.size()) {
            std::cout << data[i].fir << " " << data[i].sec << std::endl;
        }
        */
        vi dp(200003, INF);
        dp[0] = -1;
        rep(i, data.size()) {
            auto s = upper_bound(all(dp), data[i].sec);
            *s = data[i].sec;
        }
        int len = 0;
        rep(i, dp.size()) {
            if (dp[i] == INF) {
                len = i-1;
                break;
            }
            //printf("%d ", dp[i]);
            //cout << dp[i] << " ";
        }
        //puts("");
        //cout << endl;
        //cout << len << endl;

        double ans = (gx - sx + gy - sy) * 100;
        double diff = 20.0 * len - len * 20.0 * 3.141592653589793238 / 4.0;
        //std::cout << ans << " " << diff << std::endl;
        //printf("%27.15Lf\n", diff);
        //printf("%.15Lf\n", ans - diff);
        printf("%.15Lf\n", 20.0L * ((gx - sx + gy - sy) * 5.0L -
                    (double)len * (1.0L - 3.141592653589793238L / 4.0L)));

    } else {

        Int(n);
        rep(i, n) {
            i_i tmp;
            cin >> tmp.fir >> tmp.sec;
            if (gx <= tmp.fir && tmp.fir <= sx && 
                    sy <= tmp.sec && tmp.sec <= gy) {
                tmp.fir *= -1;
                data.pb(tmp);
            }
        }
        sort(all(data));
        /*
        rep(i, data.size()) {
            std::cout << data[i].fir << " " << data[i].sec << std::endl;
        }
        */
        vi dp(200003, INF);
        dp[0] = -1;
        rep(i, data.size()) {
            auto s = upper_bound(all(dp), data[i].sec);
            *s = data[i].sec;
        }
        int len = 0;
        rep(i, dp.size()) {
            if (dp[i] == INF) {
                len = i-1;
                break;
            }
            //cout << dp[i] << " ";
        }
        //cout << endl;
        //cout << len << endl;

        double ans = (sx - gx + gy - sy) * 5.0L;
        double diff = (double)len * (1.0L - 3.141592653589793238L / 4.0L);
        //std::cout << ans << " " << diff << std::endl;
        //printf("%27.15Lf\n", diff);
        //printf("%.15Lf\n", ans - diff);
        printf("%.15Lf\n", 20.0L * (ans - diff));
                   // (double)len * (1.0L - 3.141592653589793238L / 4.0L)));
    }

    return 0;
}




