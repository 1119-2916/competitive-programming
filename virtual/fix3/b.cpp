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
// BIT DiscreteFourierTransform FFT avl cmd cusum dijkstra dinic geo2 gin graph kruskal lca lcm matrix ncm next_combination segtree st tmp topcoder uf vi 


signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    Int(testcase);
    while (testcase--) {
        Int(n);
        int3(a, b, c);
        int ans = 0;
        for (int s = 1; s * s <= n; ++s) {
            if (!(n % s)) {
                int x = n / s;
                for (int t = s; t * t <= x; ++t) {
                    if (!(x % t) && (x/t) >= s && (x/t) >= t) {
                        int i = s, j = t, k = x/j;
                        //cout << i << " " << j << " " << k << endl;
                        if (i == j && j == k) {
                            if (i <= a && j <= b && k <= c) ans++;
                        } else if (i == j || j == k || i == k) {
                            if (i == k) swap(j, k);
                            else if (j == k) swap(i, k);
                            if (i <= a && j <= b && k <= c) ans++;
                            if (i <= a && k <= b && j <= c) ans++;
                            if (k <= a && j <= b && i <= c) ans++;
                        } else {
                            if (i <= a && j <= b && k <= c) ans++;
                            if (i <= a && k <= b && j <= c) ans++;
                            if (j <= a && i <= b && k <= c) ans++;
                            if (j <= a && k <= b && i <= c) ans++;
                            if (k <= a && i <= b && j <= c) ans++;
                            if (k <= a && j <= b && i <= c) ans++;
                        }
                    }
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}
