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
#define Int(x) int x; scanf("%lld", &x);
#define int2(a, b) int a, b; scanf("%lld %lld", &a, &b);
 
//int dxy[5] = {0, 1, 0, -1, 0};
// assign

int n, m, q;
vvi g;
vi cl;

void bfs(int pos, int cost, int col);

signed main()
{
    cin >> n >> m;
    if (n > 2000) return 0;
    g.assign(n+1, vi());
    cl.assign(n+1, 0);
    rep(i, m) {
        int2(a, b);
        g[a].pb(b);
        g[b].pb(a);
    }
//    cout << "gg" << endl;
    cin >> q;
    rep(i, q) {
        Int(v);
        int2(d, c);
        bfs(v, d, c);
    }
    Rep(i, n+1) {
        cout << cl[i] << endl;
    }

    return 0;
}

void bfs(int pos, int cost, int col)
{
    vb used(n+1, false);
    queue<int> q;
    q.push(pos);
    used[pos] = true;
    cost++;

    while (cost) {
        queue<int> nxt;
        while (!q.empty()) {
            int tmp = q.front(); q.pop();
            cl[tmp] = col;
            for (int p : g[tmp]) {
                if (!used[p]) {
                    used[p] = true;
                    nxt.push(p);
                }
            }
        }
        q = nxt;
        cost--;
    }

}


