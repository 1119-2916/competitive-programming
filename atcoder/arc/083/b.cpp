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
    vvi data(n, vi(n));
    rep(i, n) {
        rep(j, n) {
            cin >> data[i][j];
        }
    }

    vvi graph = data;
    rep(i, n) {
        graph[i][i] = 0;
    }
    rep(k, n) {
        rep(i, n) {
            rep(j, n) {
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }

    bool ok = true;
    rep(i, n) {
        rep(j, n) {
            if (graph[i][j] != data[i][j]) {
                ok = false;
                break;
            }
        }
        if (!ok) break;
    }
    if (!ok) {
        std::cout << -1 << std::endl;
        return 0;
    }

    int ans = 0;
    rep(i, n) {
        rep(j, n) {
            int tmp = graph[i][j];
            bool yui = false;
            rep(k, n) {
                if (i == k || j == k) continue;
                //std::cout << i << " " << k << " " << j << std::endl;
                if (tmp == graph[i][k] + graph[k][j]) {
                    yui = true;
                    break;
                }
            }
            if (!yui) {
                ans += graph[i][j];
            }
        }
    }
    std::cout << ans / 2 << std::endl;


    return 0;
}
