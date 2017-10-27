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

    int2(n, m);
    int2(a, b);

    vector<string> yui(n);
    rep(i, n) {
        cin >> yui[i];
    }

    int joge = 0, sayu = 0, kyoko = 0, other = 0;
    bool jogefl = true;
    for (int i = 0; i < n/2; i++) {
        if (yui[i] != yui[n-i-1]) {
            jogefl = false;
            break;
        }
    }
    bool sayufl = true;
    for (int j = 0; j < m/2; j++) {
        for (int i = 0; i < n; i++) {
            if (yui[i][j] != yui[i][m-j-1]) {
                sayufl = false;
                break;
            }
        }
    }
    /*
    if (jogefl && sayufl) {
        kyoko--;
    } else if (jogefl) {
        joge--;
    } else if (sayufl) {
        sayu--;
    }
    */

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (yui[i][j] == 'S') {
                if (yui[i][j] == yui[n-i-1][j] && 
                        yui[i][j] == yui[i][m-j-1] && 
                        yui[i][j] == yui[n-i-1][m-j-1]) {
                    kyoko++;
                } else if (yui[i][j] == yui[n-i-1][j] &&
                        yui[i][j] == yui[i][m-j-1] &&
                        yui[i][j] != yui[n-i-1][m-j-1]) {
                    joge++;
                    sayu++;
                } else if (yui[i][j] == yui[n-i-1][j] &&
                        (yui[i][j] != yui[i][m-j-1] || 
                        yui[i][j] != yui[n-i-1][m-j-1]) ) {
                    joge++;
                } else if (yui[i][j] == yui[i][m-j-1] && 
                        (yui[i][j] != yui[n-i-1][j] || 
                         yui[i][j] != yui[n-i-1][m-j-1]) ) {
                    sayu++;
                } else {
                    other++;
                }
            }
        }
    }

    //cout << kyoko << " " << joge << " " << sayu << endl;
    kyoko /= 4; joge /= 2; sayu /= 2;
    //cout << kyoko << " " << joge << " " << sayu << endl;

    if (jogefl && sayufl) {
        int ans = a + b;
        ans += (kyoko-1) * (a + b) + kyoko * max(a, b);
        ans += max(a * joge, b * sayu);
        cout << ans << endl;
        //kyoko--;
    } else if (jogefl) {
        joge--;
        int ans = a + b;
        ans += kyoko * (a + b) + kyoko * max(a, b);
        ans += max(a * joge, b * sayu);
        cout << ans << endl;
    } else if (sayufl) {
        sayu--;
        int ans = a + b;
        ans += kyoko * (a + b) + kyoko * max(a, b);
        ans += max(a * joge, b * sayu);
        cout << ans << endl;
    } else {
        int ans = a + b;
        ans += kyoko * (a + b) + kyoko * max(a, b);
        ans += max(a * joge, b * sayu);
        cout << ans << endl;
    }



    return 0;
}
