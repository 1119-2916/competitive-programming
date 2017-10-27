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
#define Edge pair< i_i, int>
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
// assign

int n;
vvi graph;
vi path;
vb used;

bool dfsroot(int pos)
{
    used[pos] = true;
    if (pos == n-1) {
        path.pb(pos);
        return true;
    }
    bool ret = false;
    rep(i, graph[pos].size()) {
        if (!used[graph[pos][i]]) {
            ret |= dfsroot(graph[pos][i]);
        }
    }
    if (ret) {
        path.pb(pos);
    }
    return ret;
}

int dfscnt(int pos)
{
    used[pos] = true;
    int ret = 1;
    rep(i, graph[pos].size()) {
        if (!used[graph[pos][i]]) 
        ret += dfscnt(graph[pos][i]);
    }
    return ret;
}


int snuke, feneck;

signed main()
{
    cin >> n;
    graph = vvi(n);
    rep(i, n-1) {
        int2(a, b);
        graph[a-1].pb(b-1);
        graph[b-1].pb(a-1);
    }

    used = vb(n, false);
    dfsroot(0);
    reverse(all(path));
   /* 
    rep(i, path.size()) {
        cout << path[i] << " ";
    }cout << endl;
    */

    used = vb(n, false);
    rep(i, path.size()) {
        used[path[i]] = true;
    }
    //snuke += (path.size()-1) / 2;
    rep(i, (path.size()) / 2) {
  //      cout << snuke << " ";
 //       cout << path[(path.size()-1 - i)] << endl;
        snuke += dfscnt( path[(path.size()-1 - i)] );
    }
    feneck = n - snuke;
//    cout << snuke << " " << feneck << endl;
    if (snuke < feneck) {
        cout << "Fennec" << endl;
    } else {
        cout << "Snuke" << endl;
    }

    return 0;
}

