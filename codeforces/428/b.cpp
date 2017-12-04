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
// matrix dinic next_combination topcoder lcm

signed main()
{
    int2(n, m);

    int lest = 0, cnt = 0;
    rep(i, m) {
        Int(tmp);
        if (lest) {
            if (tmp >= lest) {
                tmp -= lest;
                lest = 0;
                cnt++;
            } else {
                if (tmp <= 2) {
                    lest-=2;
                } else if (tmp <= 4) {
                    lest-=4;
                } else {
                    lest = 0;
                    cnt++;
                }
                continue;
            }
        }
        cnt += tmp / 8LL;
        tmp %= 8;
        if (!tmp) {
            ;
        } else if (tmp <= 2) {
            lest = 6;
        } else if (tmp <= 4) {
            lest = 4;
        } else if (tmp <= 6) {
            lest = 2;
        } else {
            lest = 0;
            cnt++;
        }
    }
    if (lest) {
        cnt++;
    }
    if (cnt <= n) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}
