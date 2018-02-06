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
// // assign avl ncm dijkstra geo2 kruskal graph uf lca BIT
// matrix dinic next_combination topcoder lcm vi st gin
// cusum segtree

struct UnionFind {
    vector<int> parent;
    int size;
    UnionFind(int n) :parent(n, -1), size(n) {}
    bool unite(int x, int y) {
        x = root(x); y = root(y);
        if (x == y)return false;
        if (sizeOf(x) < sizeOf(y))swap(x, y);
        parent[x] += parent[y]; parent[y] = x; size--;
        return true;
    }
    bool same(int x, int y) { return root(x) == root(y); }
    int root(int x) { return parent[x] < 0 ? x : parent[x] = root(parent[x]); }
    int sizeOf(int x) { return -parent[root(x)]; }
    bool solve() {
        return (sizeOf(0) == parent.size());
    }
};

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    priority_queue<i_i> funami;
    int2(n, m);
    vector<int> data(n);
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }
    
    UnionFind uf(n);
    rep(i, m) {
    //cout << uf.solve() << endl;
        int2(a, b);
        uf.unite(a, b);
    }

    vector< priority_queue<int> > toshino(n, priority_queue<int>());
    rep(i, n) {
        toshino[uf.root(i)].push(-data[i]);
    }
    rep(i, n) {
        if (toshino[i].size()) {
            funami.push({-toshino[i].size(), i});
        }
    }
    /*
    rep(i, n) {
        cout << toshino[i].size() << " ";
    }cout << endl;
    */
    //cout << uf.solve() << endl;

    int ans = 0, cnt = 0;
    while (funami.size() > 1) {
        i_i a, b;
        a = funami.top();
        funami.pop();
        b = funami.top();
        funami.pop();
        ans += -toshino[a.sec].top(); toshino[a.sec].pop();
        ans += -toshino[b.sec].top(); toshino[b.sec].pop();
        if (toshino[a.sec].size() < toshino[b.sec].size()) {
            while (toshino[a.sec].size()) {
                toshino[b.sec].push(toshino[a.sec].top());
                toshino[a.sec].pop();
            }
            if (toshino[b.sec].size()) 
                funami.push({-toshino[b.sec].size(), b.sec});
        } else {
            while (toshino[b.sec].size()) {
                toshino[a.sec].push(toshino[b.sec].top());
                toshino[b.sec].pop();
            }
            if (toshino[a.sec].size()) 
                funami.push({-toshino[a.sec].size(), a.sec});
        }
        uf.unite(a.sec, b.sec);
    }

    if (uf.solve()) {
        cout << ans << endl;
    } else {
        cout << "Impossible" << endl;
    }

    return 0;
}


