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

    Int(n);
    vector<string> st(2);
    cin >> st[0] >> st[1];

    int ans, ptr = 0;
    bool bef;
    if (st[0][0] == st[1][0]) {
        ans = 3;
        bef = false;
        ptr = 1;
    } else {
        ans = 6;
        bef = true;
        ptr = 2;
    }
    for (; ptr < n; ptr++) {
        if (st[0][ptr] == st[1][ptr]) {
            if (bef) {
                bef = false;
            } else {
                ans *= 2;
            }
        } else {
            if (bef) {
                ptr++;
                bef = false;
                ans *= 3;
            } else {
                ptr++;
                ans *= 2;
            }
            bef = true;
        }
        ans %= MOD;
    }
    std::cout << ans << std::endl;







    return 0;
}



