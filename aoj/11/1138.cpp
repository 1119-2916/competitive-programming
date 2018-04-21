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
#define vd vector<double>
#define vvd vector<vd >
#define vd vector<double>
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
// BIT avl cmd cusum dijkstra dinic geo2 gin graph kruskal lca lcm matrix ncm next_combination segtree st tmp topcoder uf vi 

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    cout << Decimal;

    while (1) {
        int2(n, m);
        int3(p, a, b);
        a--; b--;
        if (!n) break;
        vvi table(m, vi(m, INF));
        vi uma(n);
        rep(i, n) {
            cin >> uma[i];
        }
        rep(i, p) {
            int3(x, y, z); x--; y--;
            table[x][y] = z;
            table[y][x] = z;
        }

        vvd funami(m, vd(1 << n, (double)INF));
        funami[a][(1 << n)-1] = 0;

        using State = tuple<double, int, int>; //始点からの最短距離 子 親
        priority_queue<State> pq;
        pq.emplace(0.0, a, (1 << n)-1);
    
        while (pq.size()) {
            double d; int v, u; tie(d, v, u) = pq.top(); pq.pop();
            if (funami[v][u] < d) continue;
            rep(i, m) {
                if (table[v][i] == INF) continue;
                rep(j, n) {
                    if (u & (1 << j)) {
                        double ncost = (double)table[v][i] / (double)uma[j];
                        if (funami[i][u - (1 << j)] >
                                funami[v][u] + ncost) {
                            funami[i][u - (1 << j)] = funami[v][u] + ncost;
                            pq.emplace(funami[i][u-(1<<j)], i, u-(1<<j));
                        }
                    }
                }
            }
        }

        double ans = INF+1.0;
        rep(i, funami[b].size()) {
            ans = min(ans, funami[b][i]);
        }
        if (ans < INF) {
            cout << ans << endl;
        } else {
            cout << "Impossible" << endl;
        }
    }

    return 0;
}





