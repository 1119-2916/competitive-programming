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
#define Decimal fixed << setprecision(10)

//int dxy[5] = {0, 1, 0, -1, 0};
// // assign avl ncm dijkstra geo2 kruskal graph uf lca BIT
// matrix dinic next_combination topcoder lcm vi st gin
// cusum segtree

/*
 * table は半開区間2次元累積和配列
 */
int cusum(vvi &table, int minx, int miny, int maxx, int maxy)
{
    return table[maxx][maxy] + table[minx][miny]
        - table[maxx][miny] - table[minx][maxy];
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int3(n, m, q);
    vvi table(n, vi(m, 0));
    vvi cnt(n+1, vi(m+1, 0));
    rep(i, n) {
        string tmp; cin >> tmp;
        rep(j, tmp.size()) {
            table[i][j] = tmp[j] - '0';
            cnt[i+1][j+1] = tmp[j] - '0';
        }
    }
//    rep(i, n) {rep(j, m) cout << table[i][j] << " "; cout << endl;}

    rep(i, n) {
        rep(j, m) {
            cnt[i+1][j+1] += cnt[i+1][j] + cnt[i][j+1] - cnt[i][j];
        }
    }
//    rep(i, n+1) {rep(j, m+1) cout << cnt[i][j] << " "; cout << endl;} 
    //cout << endl;

    vvi tate(n+1, vi(m, 0));
    Rep(i, n+1) {
        Rep(j, m) {
            tate[i][j] = (table[i-1][j-1] && table[i-1][j]);
        }
    }
//    rep(i, n+1) {rep(j, m) cout << tate[i][j] << " "; cout << endl;}
    rep(i, n) {
        rep(j, m-1) {
            tate[i+1][j+1] += tate[i+1][j] + tate[i][j+1] - tate[i][j];
        }
    }
//    rep(i, n+1) {rep(j, m) cout << tate[i][j] << " "; cout << endl;}
    //cout << endl;

    vvi yoko(n, vi(m+1, 0));
    Rep(i, n) {
        Rep(j, m+1) {
            yoko[i][j] = (table[i-1][j-1] && table[i][j-1]);
        }
    }
//    rep(i, n) {rep(j, m+1) cout << yoko[i][j] << " "; cout << endl;}
    rep(i, n-1) {
        rep(j, m) {
            yoko[i+1][j+1] += yoko[i+1][j] + yoko[i][j+1] - yoko[i][j];
        }
    }
//    rep(i, n) {rep(j, m+1) cout << yoko[i][j] << " "; cout << endl;}
    //cout << endl;

    while (q--) {
        int2(sx, sy);
        int2(ex, ey);

        //cout << cusum(cnt, sx-1, sy-1, ex, ey) << endl; 
        //cout << cusum(tate, sx-1, sy-1, ex, ey-1) << endl;
        //cout << cusum(yoko, sx-1, sy-1, ex-1, ey) << endl;

        cout << cusum(cnt, sx-1, sy-1, ex, ey) - 
                cusum(tate, sx-1, sy-1, ex, ey-1) -
                cusum(yoko, sx-1, sy-1, ex-1, ey) << endl;

        //cout << endl;
    }

    return 0;
}
