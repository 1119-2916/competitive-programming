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
 
signed main()
{
    int2(sx, sy);
    int2(gx, gy);
    int2(t, v);
    int tm = t * v;
    Int(n);
    bool ans = false;
    rep(i, n) {
        int2(a, b);
        int tmp1 = (sx - a)*(sx - a) + (sy - b)*(sy - b),
            tmp2 = (a - gx)*(a - gx) + (b - gy)*(b - gy);
        if (sqrt(tmp1) + sqrt(tmp2) < (double)tm + EPS) {
            ans = true;
        }
    }
    cout << ( (ans) ? "YES" : "NO" ) << endl;


    return 0;
}

