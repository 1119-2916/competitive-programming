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
// BIT avl cusum dijkstra dinic geo2 gin graph kruskal lca lcm matrix ncm next_combination segtree st tmp topcoder uf vi 

bool solve(vvi &data, int pos)
{
//    cout << "call : " << pos << endl;
    vb state(data.size(), false);
    rep(i, data.size()) if (data[i][pos]) state[i] = true;

    for (int i = pos-1; i >= 0; i--) {
//    rep(yui, state.size()) cout << state[yui] << " "; cout << endl;
        rep(j, state.size()) {
            if (state[j] && data[j][i]) {
//                cout << "num : " << j << endl;
                rep(k, data.size()) {
                    if (data[k][i]) state[k] = true;
                }
            }
        }
    }

    bool ret = true;
    rep(i, state.size()) ret &= state[i];
    return ret;
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n;
    while (cin >> n, n) {
        vvi data(n, vi(31, 0));
        rep(i, n) {
            Int(tmp);
            rep(j, tmp) {
                Int(hoge);
                data[i][hoge] = 1;
            }
        }
//        for (vi i : data) {for (int j : i) cout << j << " "; cout << endl;}

        int ans = -1;
        rep(i, 31) {
            if (solve(data, i)) {
                ans = i;
                break;
            }
        }
        cout << ans << endl;
    }

    return 0;
}



