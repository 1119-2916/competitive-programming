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

    int2(n, m);
    vi data(n);
    rep(i, n) cin >> data[i];

    vp node(m);
    rep(i, m) {
        cin >> node[i].fir >> node[i].sec;
        if (node[i].fir > node[i].sec) {
            swap(node[i].fir, node[i].sec);
        }
    }
    sort(all(node));

    vi table(n+1, 0);
    table[0] = 1;
    int len = 0;
    Rep(i, n) {
        bool ok = false;
        for (int j = len; j >= 0; j--) {
            i_i targ(table[j], data[i]);
            if (targ.fir > targ.sec) {
                swap(targ.fir, targ.sec);
            }
           // std::cout << targ.fir << " " << targ.sec << std::endl;
            auto tmp = lower_bound(all(node), targ);
            if (*tmp == targ) {
                table[j+1] = data[i];
                len = j+1;
                ok = true;
                break;
            }
        }
        if (!ok) {
            std::cout << 0 << std::endl;
            return 0;
        }
        //std::cout << len << std::endl;
    }
    std::cout << 1 << std::endl;

    return 0;
}


