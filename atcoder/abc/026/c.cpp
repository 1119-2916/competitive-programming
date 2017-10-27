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

vvi g(21);
int n;
int solve(int p);

signed main()
{
    cin >> n;
    rep(i, n-1) {
        Int(tmp);
        g[tmp].pb(i+2);
    }
    cout << solve(1) << endl;
    return 0;
}

int solve(int p)
{
    if (g[p].size()) {
        int mi = INF, ma = -INF;
        for (int i : g[p]) {
            int tmp = solve(i);
            mi = min(mi, tmp);
            ma = max(ma, tmp);
        }
        return mi + ma + 1;
    } else {
        return 1;
    }
}

