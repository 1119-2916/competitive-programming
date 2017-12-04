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
#define Int(x) int x; scanf("%lld", &x);
#define int2(x, y) int x, y; scanf("%lld %lld", &x, &y);
#define int3(x, y, z) Int(x); int2(y, z);
#define fir first
#define sec second
#define ffir first.first
#define fsec first.second
#define sfir second.first
#define ssec second.second

//int dxy[5] = {0, 1, 0, -1, 0};
// assign avl ncm dijkstra geo2 kruskal graph uf lca BIT
// matrix dinic next_combination topcoder

signed main()
{
    int3(n, q, c);

    vector< vvi > state(c+1, vvi(101, vi(101, 0)));
    rep(i, n) {
        int3(x, y, k);
        state[k][x][y]++;
    }

    rep(i, c+1) {
        rep(j, 101) {
            Rep(k, 101) {
                state[i][j][k] += state[i][j][k-1];
            }
        }
    }
    rep(i, c+1) {
        rep(k, 101) {
            Rep(j, 101) {
                state[i][j][k] += state[i][j-1][k];
            }
        }
    }
/*
    rep(i, c+1) {
        rep(k, 5) {
            rep(j, 5) {
                std::cout << state[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl << endl;
    }*/

    while (q--) {
        int3(br, xs, ys);
        int2(xu, yu);
        int ans = 0;
        rep(i, c+1) {
            int tmp = state[i][xu][yu] - state[i][xu][ys-1]
                -state[i][xs-1][yu] + state[i][xs-1][ys-1];
//            std::cout << "tmp : " << tmp << std::endl;
            ans += tmp * ((i + br) % (c+1));
        }
        std::cout << ans << std::endl;
    }
    return 0;
}


