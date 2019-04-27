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

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    Int(n);

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    
    vi ad(30, 0);
    rep(i, n) {
        rep(j, ad.size()) {
            if (a[i] & (1 << j)) ad[j]++;
        }
    }

    int ans = 0, carry = 0;
    rep(i, b.size()) {
        int yui = 0, carry = 0;
        rep(j, ad.size()) {
            if (b[i] & (1 << j)) {
                yui += (1 << j) * ((carry + n - ad[j]) % 2);
                carry = ad[j];
            } else {
                yui += (1 << j) * ((carry + ad[j]) % 2);
                carry = 0;
            }
        }
        ans ^= yui;
    }

    std::cout << ans << std::endl;

    return 0;
}
