#include <bits/stdc++.h>

using namespace std;

#define INF 1010001000
#define MOD 1000000007
#define EPS 1e-10
#define rep(i, N) for (int i = 0; i < N; i++)
#define Rep(i, N) for (int i = 1; i < N; i++)
#define For(i, a, b) for (int i = (a); i < (b); i++)
#define pb push_back
#define eb emplece_back
#define mp make_pair
#define i_i pair<int, int>
#define vi vector<long long int>
#define vvi vector<vi >
#define vb vector<bool>
#define vvb vector<vb >
#define vp vector< i_i >
#define Edge pair< i_i, int>
#define all(a) (a).begin(), (a).end()
#define Int(x) int x; scanf("%d", &x);
#define int2(x, y) int x, y; scanf("%d %d", &x, &y);
#define fir first
#define sec second
#define ffir first.first
#define fsec first.second
#define sfir second.first
#define ssec second.second

//int dxy[5] = {0, 1, 0, -1, 0};
// assign


class DerangementsDiv2 {
    public:

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

        int count(int n, int m)
        {
            /*
            vvi dp(n+m, vi(n+m, 0));
            Rep(i, n+m) {
                dp[0][i] = 1;
            }
            Rep(i, n+m) {
                rep(j, n+m) {
                    long long int sum = 0;
                    rep(k, n+m) {
                        if (i < m && k != i-1) {
                            sum += dp[i-1][k];
                            sum %= MOD;
                        } else if (i >= m) {
                            sum += dp[i-1][k];
                            sum %= MOD;
                        }
                    }
                    dp[i][j] = sum;
                }
            }
            long long int ans = 0;
            rep(i, m+n) {
                if (!n && n+m-1 != i) {
                    ans += dp[n+m-1][i];
                    ans %= MOD;
                } else if (n) {
                    ans += dp[n+m-1][i];
                    ans %= MOD;
                }
            }
            rep(i, n+m) {
                rep(j, n+m) {
                    cout << dp[i][j] << " ";
                }cout << endl;
            }
            return (int)ans;
            */
            if (m) {
                long long int ans = n+m-1;
                Rep(i, m) {
                    ans *= n+m-i;
                    ans %= MOD;
                }
                rep(i, n) {
                    ans *= n - i;
                    ans %= MOD;
                }
                return (int)ans;
            } else {
                long long int ans = n+m;
                Rep(i, n) {
                    ans *= n - i;
                    ans %= MOD;
                }
                return (int)ans;
            }
        }
};


signed main()
{
    DerangementsDiv2 d;
    int2(a, b);
    cout << d.count(a, b) << endl;


    return 0;
}

