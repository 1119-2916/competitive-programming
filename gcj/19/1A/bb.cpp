#include <bits/stdc++.h>

using namespace std;

#define INF 1010001000
#define MOD 1000000007
#define EPS 1e-10
#define rep(i, N) for (int i = 0; i < N; i++)
#define Rep(i, N) for (int i = 1; i < N; i++)
#define For(i, a, b) for (int i = (a); i < (b); i++)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vi >
#define vb vector<bool>
#define vvb vector<vb >
#define vp vector< pii >
#define all(a) (a).begin(), (a).end()
#define Int(x) int x; cin >> x;
#define int2(x, y) Int(x); Int(y);
#define int3(x, y, z) Int(x); int2(y, z);
#define in(x, a, b) ((a) <= (x) && (x) < (b))
#define fir first
#define sec second
#define ffir first.first
#define fsec first.second
#define sfir second.first
#define ssec second.second
#define Decimal fixed << setprecision(10)

int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
// cmd

bool dfs(vvi &table, int x, int y)
{
    for (int i = 0; i < 8; i++) {
        int nx = ((x + dx[i] + (int)table.size())) % (int)table.size(), 
            ny = ((y + dy[i] + (int)table[0].size())) % (int)table[0].size();
        if (table[x][y] < table[nx][ny] && x != nx && y != ny && x-y != nx-ny && x+y != nx+ny) {
            table[nx][ny] = table[x][y] + 1;
            if (table[nx][ny] == table[0].size() * table.size()) return true;
            if (dfs(table, nx, ny)) {
                return true;
            }
        }
    }
}

void solve(int r, int c, int a, int b)
{
    vvi table(r, vi(c, INF));
    int stx = a, sty = b;
    table[stx][sty] = 1;
    if (!dfs(table, stx, sty)) {
        cout << "IMPOSSIBLE";
    } else {
        cout << "POSSIBLE";
        vp ans(r * c);
        rep(i, table.size()) {
            rep(j, table[i].size()) {
                ans[table[i][j]-1] = make_pair(i+1, j+1);
            }
        }
        rep(i, ans.size()) {
            cout << ans[i].fir << " " << ans[i].sec << endl;
        }
    }
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int a = 2, b = 4;
    rep(i, a) rep(j, b)
    solve(a, b, i, j);
    /*
    for (int i = 2; i < 6; i++) {
        for (int j = 2; j < 6; j++) {
            cout << "if (a == " << i << " && b == " << j << 
                ") {\n";
            cout << "cout << \"";
            solve(i, j);
            cout << "\" << endl;" << endl;
            cout << "}" << endl;
        }
    }
    */

    return 0;
}
