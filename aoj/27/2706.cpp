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
 
int gcd(int a, int b);


signed main()
{
    Int(p);
    Int(q);

    while (p && q) {
        int base = gcd(p, q);
        q /= base;
        for (int i = 2; i * i <= q; i++) {
            if (!(q % i)) {
                int ret = q / i;
                while (!(ret % i)) {
                    q /= i;
                    ret /= i;
                }
            }
        }
        cout << q << endl;
        p = 0; q = 0;
    }

    return 0;
}

int gcd(int a, int b)
{
    if (!b) {
        return a;
    } else {
        gcd(b, a%b);
    }
}
