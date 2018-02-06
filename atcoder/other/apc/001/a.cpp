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
// // assign avl ncm dijkstra geo2 kruskal graph uf lca BIT
// matrix dinic next_combination topcoder lcm vi st gin
// cusum segtree

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

    int2(x, y);

    if (lcm(x, y) == x) {
        cout << -1 << endl;
    } else {
        cout << x * (y - 1) << endl;
    }



    return 0;
}
