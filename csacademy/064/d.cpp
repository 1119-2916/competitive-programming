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
#define Int(x) int x; cin >> x;
#define int2(x, y) Int(x); Int(y);
#define int3(x, y, z) Int(x); int2(y, z);
#define fir first
#define sec second
#define ffir first.first
#define fsec first.second
#define sfir second.first
#define ssec second.second
#define Decimal fixed << setprecision(10)

//int dxy[5] = {0, 1, 0, -1, 0};
// cmd

signed main()
{
    Int(n);
    if (n % 2) {
        if (n < 1000) {
            rep(i, (n-1)/2) {
                cout << 1 << endl;
                Int(tmp);
            }
            cout << 1 << endl;
        } else {
            rep(i, 500) {
                cout << 1 << endl;
                Int(tmp);
            }
        }
    } else {
        int enem = n/2;
        while (n > 0) {
            int ptr = 0;
            while (pow(2, ptr+1) <= min(enem, n/2)) ptr++;
            cout << pow(2, ptr) << endl;
            n -= pow(2, ptr);
            if (n) {
                cin >> enem;
                n -= enem;
            }
        }
    }

    return 0;
}
