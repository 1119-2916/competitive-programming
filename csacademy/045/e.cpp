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

    if (n < 7) {
        std::cout << n << std::endl;
    } else if (n < 9) {
        std::cout << 7 << std::endl;
    } else {
        std::cout << 8 << std::endl;
    }
    for (int i = 0; i < n / 6; i++) {
        std::cout << "001101";
    }

    if (n % 6 == 1) {
        std::cout << 0 << std::endl;
    } else if (n % 6 == 2) {
        std::cout << "00" << std::endl;
    } else if (n % 6 == 3) {
        std::cout << "001" << std::endl;
    } else if (n % 6 == 4) {
        std::cout << "0011" << std::endl;
    } else if (n % 6 == 5) {
        std::cout << "00110" << std::endl;
    } else {
        cout << endl;
    }
        


    return 0;
}
