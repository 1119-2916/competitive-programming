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
// // assign avl ncm dijkstra geo2 kruskal graph uf lca BIT
// matrix dinic next_combination topcoder lcm vi st gin
// cusum segtree


signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    vb funami(30001, false);
    Int(n);

    n -= 3;
    cout << 2 << " " << 3 << " " << 25;
    funami[2] = funami[3] = funami[25] = true;

    int sum = 0;
    while (n > 1) {
        sum += 30;
        for (int i = 4; i + i < sum; i++) {
            if (i % 2 && i % 3 && i % 5) continue;
            if (!funami[i] && !funami[sum - i] && i != sum - i) {
                if (i > 30000 || sum - i > 30000) funami[-10] = false;
                funami[i] = funami[sum - i] = true;
                cout << " " << i << " " << sum - i;
                n -= 2;
            }
            if (n < 2) break;
        }
    }

    sum = 0;
    while (n) {
        sum += 30;
        if (!funami[sum]) {
            cout << " " << sum;
            n--;
        }
    }

    cout << endl;

    return 0;
}



