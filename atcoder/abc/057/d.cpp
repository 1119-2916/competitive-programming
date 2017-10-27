#include <bits/stdc++.h>
 
using namespace std;
 
#define INF 1001000100010001000
#define MOD 1000000007
#define MAXMOD 4611664614458057389
#define EPS 1e-7
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

int gcd(int a, int b) { if (b == 0) return a; return gcd(b, a%b); }

int extgcd(int a, int b, int &x, int &y)
{
    int d = a;
    if (b != 0) {
        d = extgcd(b, a % b, y, x);
        y -= (a / b) * x;
    } else { x = 1; y = 0; }
    return d;
}

int repow(int x, int n, int mod)
{
    if (n == 0) return 1;
    int res = repow(x * x % mod, n / 2, mod);
    if (n & 1) res = res + x % mod;
    return res;
}

int mod_inverse(int a, int m)
{
    int x, y;
    extgcd(a, m, x, y);
    return ( m + x % m ) % m;
}

int ncmmod(int n, int m, int mod)
{
    int res = 1;
    rep(i, m) res = (res * ((n - i) % mod)) % mod;
    Rep(i, m+1) res = (res * mod_inverse(i, mod)) % mod;
    return res;
}

int ncm(int n, int r)
{
    if (r == 0) return 1;
    return (n-r+1) * ncm(n, r-1) / r;
}


signed main()
{
    Int(n);
    int2(a, b);
    
    vi data(n);
    rep(i, n) cin >> data[i];

    sort(all(data));
    reverse(all(data));

    if (data[0] != data[a-1] && a != 1) {
        double out = 0.0;
        rep(i, a) out += data[i];
        printf("%.10lf\n", out / a);

        int x = 0, y = 0;
        rep(i, n) {
            if (data[a-1] == data[i]) x++;
        }
        rep(i, a) {
            if (data[a-1] == data[i]) y++;
        }
        cout << ncm(x, y) << endl;
    } else {
        double out = 0.0;
        rep(i, a) out += data[i];
        printf("%.10lf\n", out / a);
        int cnt = 0;
        rep(i, n) {
            if (data[0] == data[i]) cnt++;
        }
        int ans = 0;
        for (int i = a-1; i < b; i++) {
            if (data[0] == data[i]) {
                ans += ncm(cnt, i+1);
//                cout << ";" << ans << endl;
            }
        }
        cout << ans << endl;
    }

    return 0;
}

