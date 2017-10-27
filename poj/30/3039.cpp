#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>

using namespace std;

#define INF 1001000100010001000
#define MOD 1000000007
#define EPS 1e-10
#define int long long
#define rep(i, N) for (int i = 0; i < N; i++)
#define Rep(i, N) for (int i = 1; i < N; i++)
#define For(i, a, b) for (int i = (a); i < (b); i++)
#define pb push_back
#define eb emplece_back
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

//int dxy[5] = {0, 1, 0, -1, 0};
// assign avl ncm dijkstra geo2 kruskal graph uf lca BIT
// matrix dinic next_combination topcoder lcm

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int2(a, b);
    double targ = a / (double)b;
    double ans = targ;
    int aa = 0, bb = 1;

    if (ans > abs( 1 - targ)) {
        ans = abs( 1 - targ);
        aa = 1; bb = 1;
    }

    Rep(i, 32768) {
        if (i % b == 0) {
            int tmp = i / b;
            if (ans > abs( a * tmp + 1 / (double)i - targ)) {
                ans = abs( a * tmp + 1 / (double)i - targ);
                aa = a * tmp + 1; bb = i;
            }
            if (ans > abs( a * tmp - 1 / (double)i - targ)) {
                ans = abs( a * tmp - 1 / (double)i - targ);
                aa = a * tmp - 1; bb = i;
            }
            continue;
        }
        for (int j = 1; j < i; j++) {
            if (i % b == 0 && j % a == 0) continue;
            if (ans > abs( j / (double)i - targ)) {
                ans = abs( j / (double)i - targ);
                aa = j; bb = i;
            }
        }
    }

    cout << aa << " " << bb << endl;
    
    return 0;
}
