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
//
#define MAX_N 500 * 4 
#define MAX_M 500 * 4

i_i par[MAX_N][MAX_M];
int rank[MAX_N][MAX_M];

void init(int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            par[i][j] = i_i(i, j);
            rank[i][j] = 0;
        }
    }
}

i_i find(i_i x) 
{
    if (par[x.fir][x.sec] == x) 
        return x;
    else 
        return par[x.fir][x.sec] = find(par[x.fir][x.sec]);
}

void unite(i_i x, i_i y)
{
    x = find(x); y = find(y);
    if (x == y) return ;
    if (rank[x.fir][x.sec] < rank[y.fir][y.sec]) {
        par[x.fir][x.sec] = y;
    } else {
        par[y.fir][y.sec] = x;
        if (rank[x.fir][x.sec] == rank[y.fir][y.sec])
            rank[x.fir][x.sec]++;
    }
}

bool same(i_i x, i_i y)
{
    return find(x) == find(y);
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int3(n, m, k);
    init(n * 4, m * 4);

    //rep(loop, 10) {
    rep(i, n) {
        rep(j, m) {
            rep(dist, k+1) {
                int nx = dist, ny = k - dist;
                if (0 <= i+nx && i+nx < n && 
                        0 <= j+ny && j+ny < m) {
                    //unite(i_i(i+nx, j+ny), i_i(i, j));
                    unite(i_i(i+nx+n, j+ny+m), i_i(i, j));
                    unite(i_i(i+nx+n+n, j+ny+m+m), i_i(i, j));
                    unite(i_i(i+nx+n+n+n, j+ny+m+m+m), i_i(i, j));

                    unite(i_i(i+nx, j+ny), i_i(i+n, j+m));
                    //unite(i_i(i+nx+n, j+ny+m), i_i(i+n, j+m));
                    unite(i_i(i+nx+n+n, j+ny+m+m), i_i(i+n, j+m));
                    unite(i_i(i+nx+n+n+n, j+ny+m+m+m), i_i(i+n, j+m));

                    unite(i_i(i+nx, j+ny), i_i(i+n+n, j+m+m));
                    unite(i_i(i+nx+n, j+ny+m), i_i(i+n+n, j+m+m));
                    //unite(i_i(i+nx+n+n, j+ny+m+m), i_i(i+n, j+m));
                    unite(i_i(i+nx+n+n+n, j+ny+m+m+m), i_i(i+n+n, j+m+m));

                    unite(i_i(i+nx, j+ny), i_i(i+n+n+n, j+m+m+m));
                    unite(i_i(i+nx+n, j+ny+m), i_i(i+n+n+n, j+m+m+m));
                    //unite(i_i(i+nx+n+n, j+ny+m+m), i_i(i+n, j+m));
                unite(i_i(i+nx+n+n+n, j+ny+m+m+m), i_i(i+n+n+n, j+m+m+m));
                }
                if (0 <= i-nx && i-nx < n && 
                        0 <= j+ny && j+ny < m) {
                    //unite(i_i(i+nx, j+ny), i_i(i, j));
                    unite(i_i(i-nx+n, j+ny+m), i_i(i, j));
                    unite(i_i(i-nx+n+n, j+ny+m+m), i_i(i, j));
                    unite(i_i(i-nx+n+n+n, j+ny+m+m+m), i_i(i, j));

                    unite(i_i(i-nx, j+ny), i_i(i+n, j+m));
                    //unite(i_i(i+nx+n, j+ny+m), i_i(i+n, j+m));
                    unite(i_i(i-nx+n+n, j+ny+m+m), i_i(i+n, j+m));
                    unite(i_i(i-nx+n+n+n, j+ny+m+m+m), i_i(i+n, j+m));

                    unite(i_i(i-nx, j+ny), i_i(i+n+n, j+m+m));
                    unite(i_i(i-nx+n, j+ny+m), i_i(i+n+n, j+m+m));
                    //unite(i_i(i+nx+n+n, j+ny+m+m), i_i(i+n, j+m));
                    unite(i_i(i-nx+n+n+n, j+ny+m+m+m), i_i(i+n+n, j+m+m));

                    unite(i_i(i-nx, j+ny), i_i(i+n+n+n, j+m+m+m));
                    unite(i_i(i-nx+n, j+ny+m), i_i(i+n+n+n, j+m+m+m));
                    //unite(i_i(i+nx+n+n, j+ny+m+m), i_i(i+n, j+m));
                unite(i_i(i-nx+n+n+n, j+ny+m+m+m), i_i(i+n+n+n, j+m+m+m));
                }
                if (0 <= i-nx && i-nx < n && 
                        0 <= j-ny && j-ny < m) {
                    //unite(i_i(i+nx, j+ny), i_i(i, j));
                    unite(i_i(i-nx+n, j-ny+m), i_i(i, j));
                    unite(i_i(i-nx+n+n, j-ny+m+m), i_i(i, j));
                    unite(i_i(i-nx+n+n+n, j-ny+m+m+m), i_i(i, j));

                    unite(i_i(i-nx, j-ny), i_i(i+n, j+m));
                    //unite(i_i(i+nx+n, j-ny+m), i_i(i+n, j+m));
                    unite(i_i(i-nx+n+n, j-ny+m+m), i_i(i+n, j+m));
                    unite(i_i(i-nx+n+n+n, j-ny+m+m+m), i_i(i+n, j+m));

                    unite(i_i(i-nx, j-ny), i_i(i+n+n, j+m+m));
                    unite(i_i(i-nx+n, j-ny+m), i_i(i+n+n, j+m+m));
                    //unite(i_i(i+nx+n+n, j+ny+m+m), i_i(i+n, j+m));
                    unite(i_i(i-nx+n+n+n, j-ny+m+m+m), i_i(i+n+n, j+m+m));

                    unite(i_i(i-nx, j-ny), i_i(i+n+n+n, j+m+m+m));
                    unite(i_i(i-nx+n, j-ny+m), i_i(i+n+n+n, j+m+m+m));
                    //unite(i_i(i+nx+n+n, j+ny+m+m), i_i(i+n, j+m));
                unite(i_i(i-nx+n+n+n, j-ny+m+m+m), i_i(i+n+n+n, j+m+m+m));
                }
                if (0 <= i+nx && i+nx < n && 
                        0 <= j-ny && j-ny < m) {
                    //unite(i_i(i+nx, j+ny), i_i(i, j));
                    unite(i_i(i+nx+n, j-ny+m), i_i(i, j));
                    unite(i_i(i+nx+n+n, j-ny+m+m), i_i(i, j));
                    unite(i_i(i+nx+n+n+n, j-ny+m+m+m), i_i(i, j));

                    unite(i_i(i+nx, j-ny), i_i(i+n, j+m));
                    //unite(i_i(i+nx+n, j-ny+m), i_i(i+n, j+m));
                    unite(i_i(i+nx+n+n, j-ny+m+m), i_i(i+n, j+m));
                    unite(i_i(i+nx+n+n+n, j-ny+m+m+m), i_i(i+n, j+m));

                    unite(i_i(i+nx, j-ny), i_i(i+n+n, j+m+m));
                    unite(i_i(i+nx+n, j-ny+m), i_i(i+n+n, j+m+m));
                    //unite(i_i(i+nx+n+n, j+ny+m+m), i_i(i+n, j+m));
                    unite(i_i(i+nx+n+n+n, j-ny+m+m+m), i_i(i+n+n, j+m+m));

                    unite(i_i(i+nx, j-ny), i_i(i+n+n+n, j+m+m+m));
                    unite(i_i(i+nx+n, j-ny+m), i_i(i+n+n+n, j+m+m+m));
                    //unite(i_i(i+nx+n+n, j+ny+m+m), i_i(i+n, j+m));
                unite(i_i(i+nx+n+n+n, j-ny+m+m+m), i_i(i+n+n+n, j+m+m+m));
                }
            }
        }
    }
    /*
    char yui[4] = {'R', 'Y', 'G', 'B'};
    vector< vvi > solve(4, vvi(n, vi(m, 0)));
    rep(i, 4) {
        rep(j, n) {
            rep(l, m) {
                solve[i][j][l] = find(i_i(j+n*i, l+m*i));
            }
            cout << endl;
        }
        */
    // あとはえいってやれば出来そうな気がしますよね

    return 0;
}







