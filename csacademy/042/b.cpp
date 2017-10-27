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
    string s, a, b;
    cin >> s >> a >> b;

    rep(i, s.size() - a.size()+1) {
        bool ok = true;
        rep(j, a.size()) {
            if (s[i + j] != a[j]) {
                ok = false;
                break;
            }
        }
        if (ok) {
            rep(j, a.size()) {
                s[i+j] = b[j];
            }
            i += a.size()-1;
        } else {
            ok = true;
            rep(j, b.size()) {
                if (s[i + j] != b[j]) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                rep(j, b.size()) {
                    s[i+j] = a[j];
                }
                i += b.size()-1;
            }
        }
    }
    std::cout << s << std::endl;




    return 0;
}




