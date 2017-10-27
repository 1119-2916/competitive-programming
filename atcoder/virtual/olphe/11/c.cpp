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

    vb table(1001, true);
    table[0] = table[1] = false;
    for (int i = 2; i < 1001; i++) {
        if (table[i]) {
            for (int j = 2; j * i < 1001; j++) {
                table[i*j] = false;
            }
        }
    }
    int ans = 1;
    rep(i, 1001) {
        if (table[i]) {
            int tmp = i;
            while (tmp < 1001) {
                cout << "? " << tmp << endl;
                string ret;
                cin >> ret;
                if (ret == "N") {
                    break;
                }
                tmp *= i;
            }
            ans *= tmp / i;
        }
    }
    std::cout << "! " << ans << std::endl;

    return 0;
}
