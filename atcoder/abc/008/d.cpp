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
#define Int(x) int x; scanf("%lld", &x);
#define int2(x, y) int x, y; scanf("%lld %lld", &x, &y);
#define fir first
#define sec second
#define ffir first.first
#define fsec first.second
#define sfir second.first
#define ssec second.second

//int dxy[5] = {0, 1, 0, -1, 0};
// assign avl ncm dij geo2 kruskal graph uf lca BIT

map< int , map< int , map< int , map< int, int> > > > dp;
int w, h, n;
vi x, y;

int solve(int a, int b, int i, int j)
{
    if (dp[a][b][i].find(j) != dp[a][b][i].end()) {
        return dp[a][b][i][j];
    }
    int ret = 0;
    rep(k, n) {
        if (a <= x[k] && x[k] <= i && 
                b <= y[k] && y[k] <= j) {
            ret = max(ret, (i - a) + (j - b) + 1 +
                    solve(a, b, x[k]-1, y[k]-1) +
                    solve(a, y[k]+1, x[k]-1, j) +
                    solve(x[k]+1, b, i, y[k]-1) +
                    solve(x[k]+1, y[k]+1, i, j) );
        }
    }
    return dp[a][b][i][j] = ret;
}


signed main()
{
    cin >> w >> h >> n;
    rep(i, n) {
        int2(a, b);
        x.pb(a);
        y.pb(b);
    }

    std::cout << solve(1, 1, w, h) << std::endl;

    return 0;
}
