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
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vi >
#define vb vector<bool>
#define vvb vector<vb >
#define vp vector< pii >
#define all(a) (a).begin(), (a).end()
#define Int(x) int x; cin >> x;
#define int2(x, y) Int(x); Int(y);
#define int3(x, y, z) Int(x); int2(y, z);
#define in(x, a, b) ((a) <= (x) && (x) < (b))
#define fir first
#define sec second
#define ffir first.first
#define fsec first.second
#define sfir second.first
#define ssec second.second
#define Decimal fixed << setprecision(10)

//int dxy[5] = {0, 1, 0, -1, 0};
// 01Trie BIT CHT DFT FFT avl cmd cusum dijkstra dinic geo2 gin graph kruskal lca lcm matrix ncm next_combination ppuf segtree st tmp topcoder uf vi 

/*
 * table は半開区間2次元累積和配列
 */
int cusum(vvi &table, int minx, int miny, int maxx, int maxy)
{
    return table[maxx][maxy] + table[minx][miny]
        - table[maxx][miny] - table[minx][maxy];
}

void pscheck(vvi &data, int x, int y)
{
    vvi sum(data.size()+1, vi(data[0].size()+1, 0));
    rep(i, data.size()) {
        rep(j, data[0].size()) {
            sum[i+1][j+1] = sum[i+1][j] + data[i][j];
        }
    }
    rep(i, data.size()) {
        rep(j, data[0].size()) {
            sum[i+1][j+1] += sum[i][j+1];
        }
    }

    auto check = [&](int a, int b, int x, int y) {
        int ret = 0;
        for (int i = a; i < x; i++) {
            for (int j = b; j < y; j++) {
                //cout << data[i][j] << " ";
                ret += data[i][j];
            }
            //cout << endl;
        }
        return ret;
    };

    for (int i = 0; i + x < data.size(); i++) {
        for (int j = 0; j + y < data[0].size(); j++) {
            cout << " : " << i << " " << j << endl;
            int tmp = check(i, j, x+i, y+j);
            cout << tmp << " " << cusum(sum, i, j, i+x, j+y) << endl;
            assert(tmp == cusum(sum, i, j, i+x, j+y));
        }
    }
}

void ascheck(vvi &data)
{
    int s = 0;
    rep(i, data.size()) {
        rep(j, data[i].size()) {
            s += data[i][j];
        }
    }
    assert(s >= 0);
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    //int2(X, Y); int2(x, y);
    int X, Y, x, y;
    while (cin >> X >> Y >> x >> y) {
        if (X / x > 2 || Y / y > 2) {
            std::cout << "No" << std::endl;
        } else {
            int pts = (X / x) * (Y / y), n = x * y;
            if ((X * Y - pts) - n * pts < 0) {
                std::cout << "No" << std::endl;
            } else {
                std::cout << "Yes" << std::endl;
                vvi ans(X, vi(Y, 1));
                ans[(x+X%x)/2][(y+Y%y)/2] = -n;
                if (X / x == 2) {
                    reverse(all(ans));
                    ans[(x+X%x)/2][(y+Y%y)/2] = -n;
                }
                if (Y / y == 2) {
                    rep(i, ans.size()) {
                        reverse(all(ans[i]));
                    }
                    ans[(x+X%x)/2][(y+Y%y)/2] = -n;
                    if (X / x == 2) {
                        reverse(all(ans));
                        ans[(x+X%x)/2][(y+Y%y)/2] = -n;
                    }
                }
                rep(i, ans.size()) {
                    rep(j, ans[0].size()) {
                        std::cout << ans[i][j] << " ";
                    }
                    cout << endl;
                }
                ascheck(ans);
                pscheck(ans, x, y);
            }
        }
    }

    return 0;
}
