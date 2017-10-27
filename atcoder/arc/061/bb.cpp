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
int dx[] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
int dy[] = {1, 0, -1, 1, 0, -1, 1, 0, -1};
// assign avl ncm dijkstra geo2 kruskal graph uf lca BIT
// matrix

signed main()
{
    int2(h, w);
    Int(n);
    vi ans(10, 0);

    map< i_i, int > funami;
    rep(i, n) {
        int2(a, b);
        rep(j, 9) {
            int nx = a + dx[j], ny = b + dy[j];
            if (1 < nx && nx < h && 1 < ny && ny < w) {
                funami[i_i(nx, ny)]++;
            }
        }
    }
    int sum = (h - 2) * (w - 2);
    auto it = funami.begin();
    while (it != funami.end()) {
        ans[it->sec]++;
        it++;
        sum--;
    }
    cout << sum << endl;
    Rep(i, ans.size()) {
        cout << ans[i] << endl;
    }

    return 0;
}


