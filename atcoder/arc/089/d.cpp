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
// cmd

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

    int2(n, k);
    vvi white(k*2+1, vi(k*2+1, 0)), black(k*2+1, vi(k*2+1, 0));

    rep(i, n) {
        int2(a, b);
        a = a % (k * 2) + 1;
        b = b % (k * 2) + 1;
        char col; cin >> col;
        //cout << a << " " << b << endl;
        if (col == 'W') {
            white[a][b]++;
        } else {
            black[a][b]++;
        }
    }
    rep(i, white.size()) {
        Rep(j, white[i].size()) {
            white[i][j] += white[i][j-1];
        }
    }
    rep(j, white.size()) {
        Rep(i, white[j].size()) {
            white[i][j] += white[i-1][j];
        }
    }
   // rep(i, white.size()) { rep(j, white[i].size())
    //    cout << white[i][j] << " "; cout << endl; }

    rep(i, black.size()) {
        Rep(j, black[i].size()) {
            black[i][j] += black[i][j-1];
        }
    }
    rep(j, black.size()) {
        Rep(i, black[j].size()) {
            black[i][j] += black[i-1][j];
        }
    }
   // rep(i, black.size()) { rep(j, black[i].size())
    //    cout << black[i][j] << " "; cout << endl; }

    int ans = 0;
    rep(i, k) {
        rep(j, k) {
            int tmp = 0;
            tmp += cusum(white, 0, 0, i, j);
            tmp += cusum(white, i, j, i+k, j+k);
            tmp += cusum(white, i+k, j+k, k*2, k*2);
            tmp += cusum(white, 0, j+k, i, k*2);
            tmp += cusum(white, i+k, 0, k*2, j);

            tmp += cusum(black, i, 0, i+k, j);
            tmp += cusum(black, 0, j, i, j+k);
            tmp += cusum(black, i, j+k, i+k, k*2);
            tmp += cusum(black, i+k, j, k*2, j+k);

            ans = max(ans, tmp);

            tmp = 0;
            tmp += cusum(black, 0, 0, i, j);
            tmp += cusum(black, i, j, i+k, j+k);
            tmp += cusum(black, i+k, j+k, k*2, k*2);
            tmp += cusum(black, 0, j+k, i, k*2);
            tmp += cusum(black, i+k, 0, k*2, j);

            tmp += cusum(white, i, 0, i+k, j);
            tmp += cusum(white, 0, j, i, j+k);
            tmp += cusum(white, i, j+k, i+k, k*2);
            tmp += cusum(white, i+k, j, k*2, j+k);

            ans = max(ans, tmp);
     //       std::cout << tmp << std::endl;
        }
    }
    cout << ans << endl;



    return 0;
}




