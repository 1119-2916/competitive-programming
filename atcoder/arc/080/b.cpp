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
    int2(h, w);
    Int(n);
    vi data(n);
    rep(i, n) cin >> data[i];
    vvi ans(h, vi(w));

    int ptr = 0;
    rep(i, h) {
        if (i % 2) {
            rep(j, w) {
                while (!data[ptr]) {
                    ptr++;
                }
                data[ptr]--;
                ans[i][j] = ptr+1;
                //std::cout << ptr+1 << " ";
            }
        } else {
            for (int j = w-1; j >= 0; j--) {
                while (!data[ptr]) {
                    ptr++;
                }
                data[ptr]--;
                ans[i][j] = ptr+1;
                //std::cout << ptr+1 << " ";
            }
        }
        //std::cout << std::endl;
    }
    rep(i, h) {
        rep(j, w) {
            std::cout << ans[i][j] << " ";
        }cout << endl;
    }




    return 0;
}
