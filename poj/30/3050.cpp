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
 
int dxy[5] = {0, 1, 0, -1, 0};
// assign

int board[5][5];
string make;
set<string> yui;
set<string> kyoko;

void dfs(int x, int y, string state)
{
    if (state.size() == 6) {
        yui.insert(state);
        return ;
    }
    string akari = state + (char)(x + '0') + (char)(y + '0')
        + (char)(state.size() + '0');
    if (kyoko.find(akari) != kyoko.end()) {
        return ;
    }
    kyoko.insert(akari);
    rep(i, 4) {
        int nx = x + dxy[i], ny = y + dxy[i+1];
        if (0 <= nx && nx < 5 && 0 <= ny && ny < 5) {
            dfs(nx, ny, state + (char)((char)board[nx][ny]+'0'));
        }
    }
}

signed main()
{
    rep(i, 5) {
        rep(j, 5) {
            scanf("%lld", &board[i][j]);
            //cin >> board[i][j];
        }
    }
    rep(i, 5) {
        rep(j, 5) {
            dfs(i, j, "");
        }
    }
    cout << yui.size() << endl;

    return 0;
}

