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
 
//int dxy[5] = {0, 1, 0, -1, 0};
// assign
 
int n, m;
int g[301][301];
int r[301][301];

signed main()
{
    cin >> n >> m;
    fill(g[0], g[301], INF);
    rep(i, m) {
        int2(a, b);
        Int(co);
        g[a][b] = co;
        g[b][a] = co;
    }

    Rep(j, n+1) {
        Rep(k, n+1) {
            r[j][k] = (j != 1 && k != 1) ? g[j][k] : INF;
        }
    }

    Rep(k, n+1) {
        Rep(i, n+1) {
            Rep(j, n+1) {
                r[i][j] = min(r[i][j], r[i][k] + r[k][j]);
            }
        }
    }

    int ans = INF;
    Rep(i, n) {
        for (int j = i+1; j < n+1; j++) {
            ans = min(ans, g[1][i] + r[i][j] + g[j][1]);
        }
    }

    cout << ((ans != INF) ? ans : -1 )<< endl;

    return 0;
}

