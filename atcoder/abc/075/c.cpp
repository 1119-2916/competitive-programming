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

vvb graph;
vb used;
int n, m;

void dfs(int pos)
{
    used[pos] = true;
    rep(i, n) {
        if (pos == i) continue;
        if (graph[pos][i] && !used[i]) {
            dfs(i);
        }
    }
}

int solve() 
{
    used = vb(n, false);
    dfs(0);
    rep(i, n) {
        if (!used[i]) {
            return 1;
        }
    }
    return 0;
}


signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    cin >> n >> m;

    graph = vvb(n, vb(n, false));

    rep(i, m) {
        int2(a, b);
        graph[a-1][b-1] = true;
        graph[b-1][a-1] = true;
    }

    int ans = 0;
    rep(i, n) {
        for (int j = 0; j < i; j++) {
            if (graph[i][j]) {
                graph[i][j] = false;
                graph[j][i] = false;
                ans += solve();
                graph[i][j] = true;
                graph[j][i] = true;
            }
        }
    }

    cout << ans << endl;

    return 0;
}
