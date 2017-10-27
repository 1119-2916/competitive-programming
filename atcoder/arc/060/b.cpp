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
#define fir first
#define sec second
#define ffir first.first
#define fsec first.second
#define sfir second.first
#define ssec second.second

//int dxy[5] = {0, 1, 0, -1, 0};
// assign avl ncm dij geo2 kruskal graph uf lca BIT

int calc(int b, int n)
{
    if (n) {
        return calc(b, (n / b)) + (n % b);
    } else {
        return 0;
    }
}

signed main()
{
    int2(n, s);
    int ans = INF;
    if (n == s) {
        ans = n+1;
    }
    for (int i = 2; i * i <= n; i++) {
        if (calc(i, n) == s) {
            ans = min(ans, i);
        }
    }
    //std::cout << "OK" << std::endl;
    for (int i = 1; i * i <= n; i++) {
        int b = (n - s) / i + 1;
        if (b < 2) continue;
        if (calc(b, n) == s) {
            ans = min(ans, b);
        }
    }

    if (ans == INF) {
        std::cout << -1 << std::endl;
    } else {
        std::cout << ans << std::endl;
    }

    return 0;
}
