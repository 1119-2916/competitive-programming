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
 
signed main()
{
    int2(n, m);
    n %= 6;
    vb a(3, false);
    a[m] = true;
 //       rep(i, 3) cout << a[i] << " "; cout << endl;
    for (int i = n; i > 0; i--) {
        if (i%2) {
            bool tmp = a[0];
            a[0] = a[1];
            a[1] = tmp;
        } else {
            bool tmp = a[1];
            a[1] = a[2];
            a[2] = tmp;
        }
//        rep(i, 3) cout << a[i] << " "; cout << endl;
    }
    rep(i, 3) {
        if (a[i]) {
            cout << i << endl;
        }
    }
    return 0;
}

