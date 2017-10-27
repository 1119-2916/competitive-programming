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

    int2(n, k);
    vi w(n), p(n);
    rep(i, n) cin >> w[i] >> p[i];
    vector<double> solt(n), water(n);
    rep(i, n) {
        solt[i] = (double)(w[i] * p[i]) / 100.0;
        water[i] = (double)w[i];
        //std::cout << solt[i] << " " << water[i] << std::endl;
    }

    double l = 0.0, r = 1.0;
    rep(loop, 10000) {
        double mid = (l + r) / 2.0;
        vector<double> data(n);
        //std::cout << mid << std::endl;
        rep(i, n) {
            data[i] = solt[i] - (water[i] * mid);
        }
        sort(all(data));
        reverse(all(data));
        /*
        rep(i, n) {
            std::cout << data[i] << " ";
        }
        cout << endl;
        */
        double olphe = 0.0;
        rep(i, k) {
            olphe += data[i];
        }
        //std::cout << olphe << std::endl;
        if (olphe < 0.00) {
            r = mid;
        } else {
            l = mid;
        }
    }
    printf("%.10lf\n", l * 100);

    return 0;
}




