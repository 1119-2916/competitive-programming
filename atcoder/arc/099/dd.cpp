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
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vi >
#define vb vector<bool>
#define vvb vector<vb >
#define vp vector< pii >
#define all(a) (a).begin(), (a).end()
#define Int(x) int x; cin >> x;
#define int2(x, y) Int(x); Int(y);
#define int3(x, y, z) Int(x); int2(y, z);
#define in(x, a, b) ((a) <= (x) && (x) < (b))
#define fir first
#define sec second
#define ffir first.first
#define fsec first.second
#define sfir second.first
#define ssec second.second
#define Decimal fixed << setprecision(10)

//int dxy[5] = {0, 1, 0, -1, 0};
// cmd

int ketawa(int a)
{
    int ret = 0;
    while (a) {
        ret += a % 10;
        a /= 10;
    }
    return ret;
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    cout << Decimal;
    int a = 1999999999999;
    rep(i, 130) {
        cout << a << " " << ketawa(a) << " " << (double)(a)/(double)(ketawa(a)) << endl;
        a += 1000000000000;
    }
    /*
    cout << Decimal;
    int a = 1_99999_99999_99;
    rep(i, 130) {
        cout << a << " " << ketawa(a) << " " << (double)(a)/(double)(ketawa(a)) << endl;
        a += 1_00000_00000_00;
    }
    */

    /*
    Int(n);
    Rep(i, n+2) {
        cout << i << " " << ketawa(i) << " " << (double)(i)/(double)(ketawa(i)) << endl;
    }
    */

    /*
    int n = 1099;
    cout << n << " " << ketawa(n) << " " << (double)(n)/(double)(ketawa(n)) << endl;
    n = 1199;
    cout << n << " " << ketawa(n) << " " << (double)(n)/(double)(ketawa(n)) << endl;
    n = 1299;
    cout << n << " " << ketawa(n) << " " << (double)(n)/(double)(ketawa(n)) << endl;
    n = 1399;
    cout << n << " " << ketawa(n) << " " << (double)(n)/(double)(ketawa(n)) << endl;
    n = 1499;
    cout << n << " " << ketawa(n) << " " << (double)(n)/(double)(ketawa(n)) << endl;
    n = 1599;
    cout << n << " " << ketawa(n) << " " << (double)(n)/(double)(ketawa(n)) << endl;
    n = 1699;
    cout << n << " " << ketawa(n) << " " << (double)(n)/(double)(ketawa(n)) << endl;
    n = 1799;
    cout << n << " " << ketawa(n) << " " << (double)(n)/(double)(ketawa(n)) << endl;
    n = 1899;
    cout << n << " " << ketawa(n) << " " << (double)(n)/(double)(ketawa(n)) << endl;
    n = 1999;
    cout << n << " " << ketawa(n) << " " << (double)(n)/(double)(ketawa(n)) << endl;

    n = 2099;
    cout << n << " " << ketawa(n) << " " << (double)(n)/(double)(ketawa(n)) << endl;
    n = 2199;
    cout << n << " " << ketawa(n) << " " << (double)(n)/(double)(ketawa(n)) << endl;
    n = 2299;
    cout << n << " " << ketawa(n) << " " << (double)(n)/(double)(ketawa(n)) << endl;
    n = 2399;
    cout << n << " " << ketawa(n) << " " << (double)(n)/(double)(ketawa(n)) << endl;
    n = 2499;
    cout << n << " " << ketawa(n) << " " << (double)(n)/(double)(ketawa(n)) << endl;
    n = 2599;
    cout << n << " " << ketawa(n) << " " << (double)(n)/(double)(ketawa(n)) << endl;
    n = 2699;
    cout << n << " " << ketawa(n) << " " << (double)(n)/(double)(ketawa(n)) << endl;
    n = 2799;
    cout << n << " " << ketawa(n) << " " << (double)(n)/(double)(ketawa(n)) << endl;
    n = 2899;
    cout << n << " " << ketawa(n) << " " << (double)(n)/(double)(ketawa(n)) << endl;
    n = 2999;
    cout << n << " " << ketawa(n) << " " << (double)(n)/(double)(ketawa(n)) << endl;
    */

    return 0;
}
