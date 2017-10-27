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

vb table(50002, false);
vi prime;

void sieve();
i_i calc(int n);
 
signed main()
{
    sieve();
    Int(m);
    Int(a);
    Int(b);
    while (m) {
        for (int num = m; num >= 0; num--) {
            i_i p = calc(num);
            if (p.first) {
                if (b * p.first - a * p.second >= 0) {
                    cout << p.first << " " << p.second << endl;
                    break;
                }
            }
        }
        cin >> m >> a >> b;
    }

    return 0;
}


i_i calc(int n)
{
    int ret = 0, a, b;
    bool state = false;
    for (int p : prime) {
        if (!(n % p) && ret < 3) {
            if (state) {
                b = p;
            } else {
                state = true;
                a = p;
            }
            ret++;
        } else if (ret >= 3) {
            return i_i(0, 0);
        }
    }
    if (ret == 2 && a * b == n) {
        return i_i(a, b);
    } else if (ret == 1 && a * a == n) {
        return i_i(a, a);
    } else {
        return i_i(0, 0);
    }
}

void sieve()
{
    for (int i = 2; i < 50001; i++) {
        if (!table[i]) {
            prime.pb(i);
            for (int j = 2; i * j < 50001; j++) {
                table[i*j] = true;
            }
        }
    }
}

