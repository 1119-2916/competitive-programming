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

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
// // assign avl ncm dijkstra geo2 kruskal graph uf lca BIT
// matrix dinic next_combination topcoder lcm vi st gin
// cusum segtree

int h, w, d, k;
vp data;
vvb used;
priority_queue<i_i> len;

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    cin >> h >> w >> d >> k;
    used.assign(h, vb(w, false));
    rep(i, d) {
        int2(a, b);
        data.pb({a, b});
        used[a][b] = true;
    }

    Rep(i, d-1) {
        int tmp = abs(data[i].fir - data[i-1].fir) +
            abs(data[i].sec - data[i-1].sec) + 
            abs(data[i].fir - data[i+1].fir) +
            abs(data[i].sec - data[i+1].sec) -
            abs(data[i-1].fir - data[i+1].fir) -
            abs(data[i-1].sec - data[i+1].sec);
        len.push({tmp, i});
    }

    //int nxt = 0, nx = 100, ny = 100, dist = 1, cnt = 0;
    rep(i, k) {
        i_i tmp = len.top(); len.pop();
        int p = tmp.sec;
        int nx = (data[p-1].fir + data[p+1].fir) / 2;
        int ny = (data[p-1].sec + data[p+1].sec) / 2;
        cout << data[i].fir << " " << data[i].sec << " ";
        cout << nx << " " << ny << endl;
    }

    return 0;
}



