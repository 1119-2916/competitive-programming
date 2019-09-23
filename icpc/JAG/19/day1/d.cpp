#include <bits/stdc++.h>

using namespace std;

#define int __int128_t
#define rep(i, N) for (int i = 0; i < N; i++)
#define vi vector<int>

pair<int, int> crt(int a1, int m1, int a2, int m2)
{
    auto normal = [](int x, int m) { return x >= -x ? x % m : m - (-x) % m; };
    auto modmul = [&normal](int a, int b, int m) { return normal(a, m) * normal(b, m) % m; };
    auto extgcd = [](int a, int b, int &x, int &y) {
        for (int u = y = 1, v = x = 0; a;) {
            int q = b / a;
            swap(x -= q * u, u);
            swap(y -= q * v, v);
            swap(b -= q * a, a);
        }
        return b;
    };
    int k1, k2;
    int g = extgcd(m1, m2, k1, k2);
    if (normal(a1, g) != normal(a2, g))
        return {-1, -1};
    else {
        int l = m1 / g * m2;
        int x = a1 + modmul(modmul((a2 - a1) / g, k1, l), m1, l);
        return {x, l};
    }
}

pair<int, int> crt(vi a, vi m)
{
    int mod = 1, ans = 0;
    int n = a.size();
    rep(i, n) {
        tie(ans, mod) = crt(ans, mod, a[i], m[i]);
        if (ans == -1) return {-1, -1};
    }
    return {ans, mod};
}

pair<int, int> get(int pos, int num, const vi &b)
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

bool check(vi &data)
{
    rep(i, data.size()) {
        if (data[i] != i + 1) return false;
    }
    return true;
}

void rotate(vi &target, vi &base)
{
    int n = base.size();
    vi tmp(n);
    rep(i, n) {
        tmp[i] = base[target[i]-1];
    }
    target = tmp;
}

int valid(vi &target, vi &base)
{
    for (int i = 0; i < 101000; i++) {
        if (check(target)) return i;
        rotate(target, base);
    }
    return -1;
}

void solve(vi target, vi base)
{
    int n = target.size();
    vi a(n), m(n);
    rep(i, n) {
        auto t = get(i+1, target[i], base);
        if (t.first == -1) {
            //cout << -1 << endl;
            return ;
        }
        a[i] = t.second;
        m[i] = t.first;
    }
    //rep(i, n) cout << a[i] << " "; cout << endl;
    //rep(i, n) cout << m[i] << " "; cout << endl;

    auto t = crt(a, m);
    if (t.first == -1) {
        //cout << -1 << endl;
    } else {
        //cout << " === validation === " << endl;
        int pp = valid(target, base);
        if (pp != t.first && pp != -1) {
            cout << " found!! " << endl;
            cout << pp << endl;
        }
        //cout << t.first << endl;
    }
}

signed main()
{
    /*
    int n;
    cin >> n;
    vi target(n), base(n);
    rep(i, n) {
        cin >> target[i];
    }
    rep(i, n) {
        cin >> base[i];
    }
    */
    int n;
    cin >> n;
    vi from(n), to(n);
    for (int i = 0; i < n; i++) {
        from[i] = i + 1;
        to[i] = i + 1;
    }

    do {
        do {
            solve(from, to);
        } while (next_permutation(to.begin(), to.end()));
    } while (next_permutation(from.begin(), from.end()));

    //solve(target, base);

    return 0;
}
