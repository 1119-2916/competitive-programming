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
 
vvb graph(50, vb(50, false));
int st, n;

int solve(int pos, int d);

   
signed main()
{
    int m;
    cin >> n >> m;
    rep(i, m) {
        int2(a, b);
        graph[a][b] = true;
        graph[b][a] = true;
    }
    int ans = 0;

    rep(i, n) {
        for (int j = 0; j < n; j++) {
            if (i == j) { continue; }
            for (int k = 0; k < n; k++) {
                if (i == k || j == k) { continue; }
                for (int l = 0; l < n; l++) {
                    if (i == l || j == l || k == l) { continue; }
                    if (graph[i][j] && graph[j][k] && graph[k][l] && 
                            graph[l][i] && !graph[i][k] && !graph[j][l]) {
                        ans++;
                        //cout << i << j << k << l << endl;
                    }
                }
            }
        }
    }
    //cout << (ans/8) + ((ans % 8) ? 1 : 0) << endl;
    cout << ans/8 << endl;
    return 0;
}

