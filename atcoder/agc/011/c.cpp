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
#define Int(x) int x; scanf("%lld", &x);
#define int2(x, y) int x, y; scanf("%lld %lld", &x, &y);
 
//int dxy[5] = {0, 1, 0, -1, 0};
// assign

int used[100001];
vvi g(100001);
bool dfs(int st, int r);
int solve(int st);

signed main()
{
    int2(n, m);

    rep(i, m) {
        int2(u, v);
        g[u-1].eb(v-1);
        g[v-1].eb(u-1);
    }
    memset(used, -1, sizeof(used));

    int ans[3] = {0};
    rep(i, n) {
        if (used[i] == -1) {
            int tmp = solve(i);
            ans[tmp]++;
        }
    }

//    for (int i : ans) {cout << i << " ";} cout << endl;

    cout << ans[0] * ans[0] + (n - ans[0]) * ans[0] + (n - ans[0]) * ans[0]
        + ans[2] * ans[1] * 2 + ans[2] * ans[2] + ans[1] * ans[1] * 2
         << endl;

    return 0;
}

int solve(int st)
{
    if (g[st].size()) {
        return (dfs(st, 1)) ? 1 : 2;
    } else {
        return 0;
    }
}


bool dfs(int st, int r)
{
    bool ret = true;
    if (used[st] != -1) {
        if ((r - used[st] + 1) % 2) {
            return true;
        } else {
            return false;
        }
    } else {
        used[st] = r;
        for (int i : g[st]) {
            if (used[i] != r-1) {
                ret &= dfs(i, r+1);
            }
        }
    }
    return ret;
}

