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
// BIT CHT DiscreteFourierTransform FFT avl cmd cusum dijkstra dinic geo2 gin graph kruskal lca lcm matrix ncm next_combination ppuf segtree st tmp topcoder uf vi 


/**
 * nCm
 * vector<int> v(m, 0);
 * do {
 *  // 
 * } while (next_(v, n));
 */
bool next_combination(std::vector<int>& v, int n) {
    int k = v.size();
    int p = k - 1;
    if (v[p] >= n) return false;
    while (p >= 0 && ++v[p] >= n - (k - p - 1)) --p;
    if (p < 0) return false;
    ++p;
    while (p < k) {
        v[p] = v[p - 1] + 1;
        ++p;
    }
    return true;
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    Int(n);
    vector<int> data(n, 0);
    //rep(i, n) data[i] = i;

    do {
        rep(i, n) {
            cout << data[i] << " ";
        }
        cout << endl;
    } while (next_combination(data, n*2));

    return 0;
}
