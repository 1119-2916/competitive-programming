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

    Int(k);
    int n = pow(2, k);
    vector<int> data(n);
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }
    vector< vector<double> > table(n, vector<double>(n));
    rep(i, n) {
        rep(j, n) {
            double tmp = (data[j] - data[i]) / 400.0;
            //std::cout << tmp << std::endl;
            tmp = pow(10.0, tmp) + 1.0;
            table[i][j] = 1.0 / tmp;
        }
    }
    /*
    rep(i, n) {
        rep(j, n) {
            std::cout << table[i][j] << " ";
        }
        cout << endl;
    }
    */
    vector< vector<double> > dp(k+1, vector<double>(n, 0.0));
    rep(i, n) {
        dp[0][i] = 1.0;
    }
    
    Rep(i, k+1) {
        rep(j, n) {
            double tmp1 = 0.0, tmp2 = 0.0;
            bool dotch = false;
            for (int l = (((1 << 11)-1)<<i) & j, cnt = 0;
                    cnt < pow(2, i); cnt++) {
                //std::cout << l+cnt << std::endl;
                if (l+cnt != j) {
                    if (cnt < pow(2, i-1)) {
                        tmp1 += table[j][l+cnt] * dp[i-1][l+cnt];
                    } else {
                        tmp2 += table[j][l+cnt] * dp[i-1][l+cnt];
                    }
                } else {
                    if (cnt < pow(2, i-1)) {
                        dotch = false;
                    } else {
                        dotch = true;
                    }
                }
            }
            //std::cout << i << " " << j << " " << tmp << std::endl;
            if (dotch) {
                dp[i][j] = dp[i-1][j] * tmp1;
            } else {
                dp[i][j] = dp[i-1][j] * tmp2;
            }
        }
    }
    rep(i, n) {
        printf("%.10lf\n", dp[k][i]);
        //std::cout << dp[k][i] << std::endl;
    }

    return 0;
}
