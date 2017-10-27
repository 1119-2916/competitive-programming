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
#define Edge pair< i_i, int>
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
// assign

int solve(int a,int b,int c,int d,int e,int f)
{
    return (d / a) * (e / b) * (f / c);
}

signed main()
{
    int2(d, e); int2(f, a); int2(b, c);

    int ans = 0;

    ans = max(ans, solve(a, b, c, d, e, f));
    ans = max(ans, solve(a, c, b, d, e, f));
    ans = max(ans, solve(b, a, c, d, e, f));
    ans = max(ans, solve(b, c, a, d, e, f));
    ans = max(ans, solve(c, a, b, d, e, f));
    ans = max(ans, solve(c, b, a, d, e, f));

    cout << ans << endl;

    return 0;
}


