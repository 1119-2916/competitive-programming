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

double p, ans, ret;
int n;
vector< vector< i_i > > g;

int cnt;

void solve(int pos, int bef, double per);
void dfs(int pos, int bef, double per);
double calc(int pos, int bef, double per);

signed main()
{
    cin >> p >> n;
    g.assign(n+1, vector< i_i >());
    rep(i, n-1) {
        int2(a, b);
        Int(c);
        g[a].pb(mp(b, c));
        g[b].pb(mp(a, c));
    }

    solve(1, 0, p);
    //printf("%.10lf\n", ans);
    dfs(1, 0, 1.0);
    printf("%.10lf\n", ans + ret);

    //printf("%.10lf\n", ret);

    return 0;
}


void solve(int pos, int bef, double per)
{
    //cout << pos << endl;

    if (per < EPS) return ;
    for (i_i i : g[pos]) {
        if (i.first == bef) continue;
        solve(i.first, pos, per * p);
        ans += per * (double)i.second;
    }
}
        
void dfs(int pos, int bef, double per)
{
    if (per < EPS) return;
    ret += per * ans;
    for (i_i i : g[pos]) {
        if (i.first == bef) continue;
        dfs(i.first, pos, per * p);
    }
}

double calc(int pos, int bef, double per)
{
   // cout << cnt++ << endl;
    if (per < EPS) return 0.0;
    for (i_i i : g[pos]) {
        if (i.first == bef) continue;
        ans += per * i.second + calc(i.first, pos, per * p) * per;
    }
    return ans;
}



