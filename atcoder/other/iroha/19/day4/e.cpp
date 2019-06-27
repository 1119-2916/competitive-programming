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
// 01Trie BIT CHT DFT FFT avl cmd cusum dijkstra dinic geo2 gin graph kruskal lca lcm matrix ncm next_combination ppuf segtree st tmp topcoder uf vi 

int fact[1145140];
int pascal_table[100][100];

/*
 * tableをdoubleにしてncmの割合も求められる
 * 1/2して下ってゆくように書き換えてその場で作る.
 */
void make_pascal(int mod)
{
    rep(i, 100) {
        pascal_table[i][0] = 1;
        for (int j = 1; j < i; j++) {
            pascal_table[i][j] = (pascal_table[i-1][j-1] +
                    pascal_table[i-1][j]) % mod;
        }
        pascal_table[i][i] = 1;
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
    if (n & 1) res = res * x % mod;
    return res;
}

int mod_inverse(int a, int m)
{
    int x, y;
    extgcd(a, m, x, y);
    return ( m + x % m ) % m;
}

int table(int n, int p)
{
    int sum = 1;
    fact[0] = 1;
    Rep(i, n+2) {
        sum *= i;
        sum %= p;
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
 * nCr mod p
 * nHr = (n+r-1)Cr
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

int bdp[70][2][70];

int get_keta(int n)
{
    int p = 1, ans = 1;
    while (n > p) {
        ans++; p <<= 1;
    }
    return ans;
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    table(1001000, MOD);
    
    int2(n, k);
    if (!k) {
        cout << 0 << endl;
        return 0;
    }

    int keta = get_keta(k);

    bdp[0][1][0] = 1;
    rep(i, keta) {
        if ((1 << (keta-i-1)) & k) {
            rep(j, keta+1) {
                bdp[i+1][0][j] += bdp[i][1][j];
                bdp[i+1][1][j+1] += bdp[i][1][j];
                bdp[i+1][0][j] += bdp[i][0][j];
                bdp[i+1][0][j+1] += bdp[i][0][j];
            }
        } else {
            rep(j, keta+1) {
                bdp[i+1][1][j] += bdp[i][1][j];
                bdp[i+1][0][j] += bdp[i][0][j];
                bdp[i+1][0][j+1] += bdp[i][0][j];
            }
        }
    }

    vi hoge(70, 0);
    rep(i, keta+1) {
        hoge[i] += bdp[keta][0][i];
        hoge[i] += bdp[keta][1][i];
    }

   //rep(i, keta+1) { std::cout << hoge[i] << " "; } cout << endl;
  
    vvi dp(n+1,    

    return 0;
}