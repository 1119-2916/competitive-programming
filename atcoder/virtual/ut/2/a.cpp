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

bool funami(vi &num, int a, int state)
{
    rep(i, num.size()) {
        if ((state & (1 << i)) == 0) continue;
        if (gcd(num[i], a) != 1) return false;
        rep(j, num.size()) {
            if (i != j && state & (1 << j) &&
                    gcd(num[i], num[j]) != 1) return false;
        }
    }
    return true;
}

bool toshino(vi &num, int a, int state)
{
    rep(i, num.size()) {
        if ((state & (1 << i)) == 0) continue;
        if (gcd(num[i], a) != 1) return false;
    }
    return true;
}


signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int2(a, b);

    vi odd, even;
    for (int i = a; i <= b; i++) {
        if (i % 2) odd.pb(i);
        else even.pb(i);
    }

    set<int> table;
    rep(i, (1 << (int)odd.size())) {
        if (funami(odd, 1, i)) table.insert(i);
    }
    int ans = table.size();
    rep(i, even.size()) {
        for (auto j : table) {
            if (toshino(odd, even[i], j)) ans++;
        }
    }

    std::cout << ans << std::endl;

    return 0;
}
