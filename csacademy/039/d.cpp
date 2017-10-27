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
// assign avl ncm dijkstra geo2 kruskal graph uf lca BIT
// matrix

signed main()
{
    Int(n);
    int seg[8] = {-1, -1, 1, 7, 4, 2, 0, 8};

    if (n < 0) {
        cout << -1 << endl;
        return 0;
    } else if (n <= 7) {
        std::cout << seg[n] << std::endl;
        return 0;
    }

    int len = n / 7 + 1;
    int less = 7 - (n % 7);
    if (less == 7) {
        less = 0;
        len--;
    }
    string ans;
    rep(i, len) ans.pb('8');

//    std::cout << less << std::endl;

    if (less == 0) {
        std::cout << ans << std::endl;
    } else if (less == 1) {
        //ans[1] = '0';
        ans[0] = '6';
        std::cout << ans << std::endl;
    } else if (less == 5) {
        ans[0] = '1';
        std::cout << ans << std::endl;
    } else if (less == 6) {
        ans[0] = '1';
        ans[1] = '0';
        std::cout << ans << std::endl;
    } else {
        ans[0] = '2';
        less -= 2;
        int ptr = 1;
        if (less < len) {
            while (less) {
                ans[ptr++] = '0';
                less--;
            }
        } else {
            cout << 22 << endl;
            return 0;
        }
        std::cout << ans << std::endl;
    }

    return 0;
}
