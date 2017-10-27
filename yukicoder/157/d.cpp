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
        st = i;
        ans += solve(i, 0);
    }
    cout << ans/4 << endl;

    return 0;
}

int solve(int pos, int d)
{
    if (d == 4) {
        if (pos == st) {
            return 1;
        } else {
            return 0;
        }
    }
    int ret = 0;
    rep(i, n) {
        if (graph[pos][i]) {
            ret += solve(i, d+1);
        }
    }
    return ret;
}
