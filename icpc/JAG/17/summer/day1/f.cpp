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

    string st;
    cin >> st;
    int n = st.size();
    vector< vvi > dp(2, vvi(n+1, vi(26, INF)));

    vi table(26, INF);
    for (int i = n; i > 0; i--) {
        table[st[i-1] - 'a'] = i;
        rep(j, 26) {
            dp[0][i-1][j] = table[j];
        }
    }

    table = vi(26, INF);
    rep(i, n) {
        table[st[i] - 'a'] = i;
        rep(j, 26) {
            dp[1][i+1][j] = table[j];
        }
    }

    /*
    rep(i, n+1) {
        rep(j, 26) {
            cout << dp[0][i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    rep(i, n+1) {
        rep(j, 26) {
            cout << dp[1][i][j] << " ";
        }
        cout << endl;
    }
    */

    Int(q);
    while (q--) {
        string input;
        cin >> input;
        int yui = 0, kyoko = n;
        rep(i, input.size()) {
            yui = dp[0][yui][input[i]-'a'];
            if (yui == INF) {
                break;
            }
        }
        kyoko = yui;
        if (yui == INF) {
            cout << -1 << endl;
            continue;
        }
        for (int i = input.size()-1; i >= 0; i--) {
            kyoko = dp[1][kyoko][input[i]-'a'];
            if (kyoko == INF) {
                break;
            }
        }
        if (kyoko == INF) {
            std::cout << -1 << std::endl;
        } else {
            cout << kyoko+1 << " " << yui << endl;
        }
    }

    return 0;
}



