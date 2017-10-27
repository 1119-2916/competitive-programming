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
#define fir first
#define sec second
#define ffir first.first
#define fsec first.second
#define sfir second.first
#define ssec second.second

//int dxy[5] = {0, 1, 0, -1, 0};
// assign avl ncm dijkstra geo2 kruskal graph uf lca BIT
// matrix dinic

int fact[1145140];
double pascal_table[1001][1001];

void make_pascal()
{
    pascal_table[0][0] = 1.0;
    rep(i, 1000) {
        for (int j = 0; j <= i; j++) {
            pascal_table[i+1][j] += pascal_table[i][j] / 2;
            pascal_table[i+1][j+1] += pascal_table[i][j] / 2;
        }
    }
}

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

int table(int n)
{
    int sum = 1;
    fact[0] = 1;
    Rep(i, n+2) {
        sum *= i;
        sum %= MOD;
        fact[i] = sum;
    }
}

int mod_fact(int n, int p, int &e)
{
    e = 0;
    if (n == 0) return 1;
    int res = mod_fact(n / p, p, e);
    e += n / p;

    if (n / p % 2 != 0) return res * (p - fact[n % p]) % p;
    return res * fact[n % p] % p;
}

/*
 * 必ずtable()を呼んでから使う.
 * n = 1001000くらいで
 */
int mod_comb(int n, int k, int p) {
    if (n < 0 || k < 0 || n < k) return 0;
    int e1, e2, e3;
    int a1 = mod_fact(n, p, e1), a2 = mod_fact(k, p, e2), a3 = mod_fact(n-k, p, e3);
    if (e1 > e2 + e3) return 0;
    return a1 * mod_inverse(a2 * a3 % p, p) % p;
}

int ncm(int n, int r)
{
    if (r == 0) return 1;
    return (n-r+1) * ncm(n, r-1) / r;
}


signed main()
{
    make_pascal();

    /* {{{
    rep(i, 10) {
        rep(j, i+1) {
            cout << pascal_table[i][j] << " ";
        }cout << endl;
    }
     }}} */ 
    int2(n, d);
    int2(a, b);
    a = abs(a); b = abs(b);
    if (a % d || b % d) {
        puts("0.0");
        return 0;
    }

    a /= d; b /= d;
    int rest = n - (a + b);
    if (a + b > n || rest % 2) {
        puts("0.0");
        return 0;
    }

    double ans = 0;
    for (int i = 0; i <= rest; i += 2) {
        double tmp = pascal_table[n][a + i];
        int j = rest - i;
        tmp *= pascal_table[a + i][i / 2] * pascal_table[b + j][j / 2];
//        std::cout << tmp << std::endl;
        ans += tmp;
    }
    printf("%.10lf\n", ans);


    return 0;
}



