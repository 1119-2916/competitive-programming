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

int n, h, a, b, c, d, e;
 
int bs(int v, int l, int r);

signed main()
{
    cin >> n >> h >> a >> b >> c >> d >> e;
    int ans = INF;

    for (int i = 0; i <= n; i++) {
        int u = bs(i, 0, n+1);
        ans = min(ans, i * a + u * c);
    }
    cout << ans << endl;


    return 0;
}


int bs(int v, int l, int r)
{
    int mid = (l + r) / 2, life = h + v * b, ret;
    if ( (mid * d + life) - e * (n - v - mid) > 0) {
        if (r - l == 1) {
            return mid;
        }
        ret = min(mid, bs(v, l, mid));
    } else {
        if (r - l == 1) {
            return INF;
        }
        ret = bs(v, mid, r);
    }
    return ret;
}









