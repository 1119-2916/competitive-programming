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
    string s;
    cin >> s;
    reverse(all(s));
    int n = s.size()-1;
    vi data(n);
    rep(i, n) cin >> data[i];
//    reverse(all(data));

    int ans = 1, add = 0;

    rep(i, n) {
        if (data[i]) {
            ans *= 10 - (s[i] - '0' + 1 - add);
 //           cout << 10 - (s[i] - '0' + 1 - add) << " ";
            add = 1;
        } else {
            ans *= (s[i] - '0' + 1 - add);
//            cout << (s[i] - '0' + 1 - add) << " ";
            add = 0;
        }
    }
  //  cout << endl;
    if (data[n-1]) {
        std::cout << ans << std::endl;
    } else {
        std::cout << ans * 2 << std::endl;
    }



    return 0;
}
