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

    vector<string> st(3);
    rep(i, 3) {
        cin >> st[i];
    }
    int n = st[0].size();

    vvi cnt(3, vi(26, 0));
    rep(i, 3) {
        rep(j, n) {
            cnt[i][st[i][j] - 'A']++;
        }
    }

    /*
    rep(i, 3) {
        rep(j, n) {
            cout << cnt[i][j] << " " ;
        }
        cout << endl;
    }
    */

    int left = 0, right = 0;
    rep(i, 26) {
        int yui = min(cnt[2][i], cnt[0][i]), 
            kyoko = max(0LL, cnt[2][i] - cnt[1][i]);
        if (cnt[2][i] > cnt[1][i] + cnt[0][i]) {
            cout << "NO" << endl;
            return 0;
        }
        left += kyoko; right += yui;
    }

    //cout << left << " " << right << endl;

    if (left <= n/2 && n/2 <= right) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
