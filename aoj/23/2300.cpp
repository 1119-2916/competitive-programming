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
 
//int dxy[5] = {0, 1, 0, -1, 0};
// assign

double solve(int i, int m, double ret);

vector<double> l, a, b;
vi sele;
int n, m;
 
signed main()
{
    cin >> n >> m;

    l.assign(n, 0);
    a.assign(n, 0);
    b.assign(n, 0);

    rep(i, n) {
        cin >> l[i] >> a[i] >> b[i];
    }

    printf("%.10lf\n", solve(0, m, 0.0));

    return 0;
}

double solve(int i, int m, double ret)
{
    double ans = 0.0;
    if (i == n || m == 0) {
        return (!m) ? ret : 0.0;
    } else {
        ans = max(solve(i+1, m, ret), ret);
        rep(j, sele.size()) {
            ret += (l[sele[j]] - l[i]) * (l[sele[j]] - l[i]);
            ret += (a[sele[j]] - a[i]) * (a[sele[j]] - a[i]);
            ret += (b[sele[j]] - b[i]) * (b[sele[j]] - b[i]);
        }
        sele.pb(i);
        ans = max(solve(i+1, m-1, ret), max(ans, ret));
        sele.pop_back();
    }
    return ans;
}


