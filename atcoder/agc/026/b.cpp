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

//最大公約数
int gcd(int x, int y) { return y ? gcd(y, x%y) : x; }
//最小公倍数
int lcm(int x, int y) { return x / gcd(x, y) * y; }
//最大公約数 複数個
int gcd(const vector<int> &v) {
    int ret = v[0];
    for (int i = 1; i < v.size(); i++)
        ret = gcd(ret, v[i]);
    return ret;
}
//最小公倍数 複数個
int lcm(const vector<int> &v) {
    int ret = v[0];
    for (int i = 1; i < v.size(); i++)
        ret = lcm(ret, v[i]);
    return ret;
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    Int(t);
    while (t--) {
        int2(a, b); int2(c, d);
        if (a < b) {
            cout << "No" << endl;
            continue;
        }
        if (d < b) {
            cout << "No" << endl;
            continue;
        }
        if (b <= c) {
            std::cout << "Yes" << std::endl;
            continue;
        }

        int g = gcd(b, d);
        if (b - g + a % g > c) {
            std::cout << "No" << std::endl;
        } else {
            std::cout << "Yes" << std::endl;
        }
    }

    return 0;
}
