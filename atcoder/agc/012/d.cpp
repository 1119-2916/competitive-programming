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

int ncmmod(int n, vi &m, int mod)
{
    int res = 1;
    Rep(i, n+1) res = (res * ( i % mod) ) % mod;
    //cout << "res:" << res << endl;
    for (int p : m) {
        //rep(i, p) res = (res * ((n - i) % mod)) % mod;
        Rep(i, p+1) res = (res * mod_inverse(i, mod)) % mod;
    }
    //Rep(i, m+1) res = (res * mod_inverse(i, mod)) % mod;
    return res;
}

int n, x, y;

signed main()
{
    cin >> n >> x >> y;
    vector< i_i > it(n);
    rep(i, n) {
        cin >> it[i].first >> it[i].second;
    }
    sort(all(it));
    /* 
    cout << "======" << endl;
    rep(i, n) {
        cout << it[i].first << " " <<  it[i].second << endl;
    }
    cout << "======" << endl;
    */
    vector < pair<int, i_i> > cl;
    int col = it[0].first, cnt = 1, min = it[0].second;
    for (int i = 1; i < n; i++) {
        if (col != it[i].first) {
            cl.pb( mp(min, mp(cnt, col)) );
            col = it[i].first;
            cnt = 1;
            min = it[i].second;
        } else if (min + it[i].second > x) {
            //cl.pb( mp(col, mp(cnt, min)) );
            while (i < n && col == it[i].first) {
                i++;
            }
            i--;
        } else {
            cnt++;
        }
    }
    cl.pb( mp(min, mp(cnt, col)) );
    //cout << "nnn" << endl;
    /*
    rep(i, cl.size()) {
        cout << cl[i].first << " " << 
            cl[i].second.first << " " << cl[i].second.second << endl;
    }
    */
    //if (cl.size() == 1) { cout << 1 << endl; return 0; }
    sort(all(cl));
    vi div;
    min = cl[0].first;
    div.pb(cl[0].second.first);
    cnt = cl[0].second.first;
    //cout << min << " " << div[0] << " " << cnt << endl;
    Rep(i, cl.size()) {
        if (min + cl[i].first > y) {
            break;
        } else {
            cnt += cl[i].second.first;
            div.pb(cl[i].second.first);
        }
    }
    /*
    cout << "====" << endl;
    for (int i : div) cout << i << endl;
    cout << "cnt" << cnt << endl;
    */
    cout << ncmmod(cnt, div, MOD) << endl;

    return 0;
}

