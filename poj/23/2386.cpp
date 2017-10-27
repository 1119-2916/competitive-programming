#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
#include <stack>
#include <cstdlib>
#include <string>
#include <set>
#include <map>

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
#define Edge pair< int, i_i >
#define all(a) (a).begin(), (a).end()
#define Int(x) int x; scanf("%lld", &x);
#define int2(x, y) int x, y; scanf("%lld %lld", &x, &y);
#define fir first
#define sec second
#define ffir first.first
#define fsec first.second
#define sfir second.first
#define ssec second.second
 
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {1, 0, -1, 1, -1, 1, 0, -1};
// assign

int n, m;
vector<string> yui;
vvb used;

void dfs(int a, int b)
{
//    cout << "(" << a << "," << b << ")" << endl;
    used[a][b] = true;
    rep(i, 8) {
        int ni = a + dx[i], nj = b + dy[i];
        if (0 <= ni && ni < n &&
                0 <= nj && nj < m) {
            if (!used[ni][nj] && yui[ni][nj] == 'W') {
                dfs(ni, nj);
            }
        }
    }
}

signed main()
{
    cin >> n >> m;
    yui = vector<string>(n);
    rep(i, n) {
        cin >> yui[i];
    }

    used = vvb(n, vb(m, false));

    int ans = 0;
    rep(i, n) {
        rep(j, m) {
            if (!used[i][j] && yui[i][j] == 'W') {
                dfs(i, j);
                ans++;
                /*
                rep(i, n) {
                    rep(j, m) {
                        cout << used[i][j] << " ";
                    }cout << endl;
                }
                */
            }

        }
    }
    cout << ans << endl;

    return 0;
}

