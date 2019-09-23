#include <bits/stdc++.h>

using namespace std;

#define int long long
#define rep(i, N) for (int i = 0; i < N; i++)
#define vi vector<int>

using lll = __int128_t;

pair<lll, lll> crt(lll a1, lll m1, lll a2, lll m2)
{
    auto normal = [](lll x, lll m) { return x >= -x ? x % m : m - (-x) % m; };
    auto modmul = [&normal](lll a, lll b, lll m) { return normal(a, m) * normal(b, m) % m; };
    auto extgcd = [](lll a, lll b, lll &x, lll &y) {
        for (lll u = y = 1, v = x = 0; a;) {
            lll q = b / a;
            swap(x -= q * u, u);
            swap(y -= q * v, v);
            swap(b -= q * a, a);
        }
        return b;
    };
    lll k1, k2;
    lll g = extgcd(m1, m2, k1, k2);
    if (normal(a1, g) != normal(a2, g))
        return {-1, -1};
    else {
        lll l = m1 / g * m2;
        lll x = a1 + modmul(modmul((a2 - a1) / g, k1, l), m1, l);
        return {x, l};
    }
}

pair<lll, lll> crt(vector<lll> a, vector<lll> m)
{
    lll mod = 1, ans = 0;
    lll n = a.size();
    rep(i, n) {
        tie(ans, mod) = crt(ans, mod, a[i], m[i]);
        if (ans == -1) return {-1, -1};
    }
    return {ans, mod};
}

pair<int, int> get(int pos, int num, vi &b)
{
    int step = 0, first = -1, second = -1;
    int n = b.size();
    for (int i = 0; i <= n + n; i++) {
        if (num == pos) {
            first = i;
            break;
        }
        num = b[num-1];
    }
    if (first == -1) return {-1, -1};
    for (int i = first+1; i <= n + n + n + n; i++) {
        num = b[num-1];
        if (num == pos) {
            second = i;
            break;
        }
    }
    return {second - first, first};
}

signed main()
{
    for (int i = 1010001000; i < 2010001000; i++) {
        int p = i;
        for (int j = 2; j * j <= p; j++) {
            if (p % j == 0) {
                p = 0;
                break;
            }
        }
        if (p) {
            cout << p << endl;
        }
    }

    return 0;
}

