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
    vi data(m);

    int ni = 0, yon = 0, cnt = 0, ichi = 0;
    rep(i, m) {
        cin >> data[i];
        cnt += data[i] / 8LL;
        data[i] %= 8;
        if (data[i] == 0) {
            ;
        } else if (data[i] == 1) {
            ichi++;
        } else if (data[i] == 2) {
            ni++;
        } else if (data[i] == 3) {
            ni++;
            ichi++;
        } else if (data[i] == 4) {
            yon++;
        } else if (data[i] == 5) {
            yon++;
            ichi++;
        } else if (data[i] == 6) {
            yon++;
            ni++;
        } else if (data[i] == 7) {
            yon++;
            ni++;
            ichi++;
        }
    }

    if (yon * 2 <= ni) {
        cnt += yon;
        ni -= yon * 2;
    } else if (yon * 2 <= ichi + ni) {
        cnt += yon;
        ichi -= yon * 2 - ni;
        ni = 0;
    } else {
        int tmp = (ichi + ni) / 2 + (ichi + ni) % 2;
        ichi = ni = 0;
        yon -= tmp;
        cnt += tmp;
        cnt += yon / 2 + yon % 2;
    }
    yon = 0;
//    std::cout << ichi << " " << ni << " " << yon << std::endl;
    if (ni) {
        int tmp = ni / 3;
        ni %= 3;
        cnt += tmp;
        ichi -= tmp;
        if (ni) {
            ichi -= 3 - ni;
            cnt++;
            ni = 0;
        }
    }
    if (ichi >= 1) {
        cnt += ichi / 4 + (!!(ichi % 4));
    }

    if (cnt <= n) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}
