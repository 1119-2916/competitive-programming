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

//int dxy[5] = {0, 1, 0, -1, 0};
// 01Trie BIT CHT DFT FFT avl cmd cusum dijkstra dinic geo2 gin graph kruskal lca lcm matrix ncm next_combination ppuf segtree st tmp topcoder uf vi 

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
};

bool solve(vvi &ans, int num)
{
    bool fl = true;
    int n = ans.size();
    rep(i, n-1) {
        for (int j = i+1; j < n; j++) {
            if (!ans[i][j]) fl = false;
        }
    }
    if (fl) return false;

    UnionFind uf(ans.size());
    rep(i, n-1) {
        for (int j = i+1; j < n; j++) {
            if (!ans[i][j] && !uf.same(i, j)) {
                ans[i][j] = num;
                uf.unite(i, j);
            }
        }
    }
    return true;
}

bool solve2(vvi &ans, int num, int st)
{
    bool fl = true;
    int n = ans.size();
    rep(i, n-1) {
        for (int j = i+1; j < n; j++) {
            if (!ans[i][j]) fl = false;
        }
    }
    if (fl) return false;

    for (int i = st; i < n-1; i++) {
        ans[i][i+1] = num;
        for (int j = i + 3; j < n; j += 2) {
            ans[i][j] = num;
        }
    }
    return false;
}

bool add(vvi &ans, int s, int t, int num)
{
    int n = ans.size();
    if (s < n && t < n) {
        ans[s][t] = num;
        return true;
    }
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    Int(n);

    vvi ans(n, vi(n, 0));

    int num = 1;
    for (int i = 0; i < n; i += 4) {
        bool fl = false;
        fl |= add(ans, i, i+1, num);
        for (int j = i + 3; j < n; j++) {
            fl |= add(ans, i, j, num);
            fl |= add(ans, i+2, j, num);
        }
        for (int j = i + 4; j < n; j++) {
            fl |= add(ans, i+1, j, num);
            fl |= add(ans, i+3, j, num);
        }
        if (fl) num++;
    }

    /*
    for (int i = n % 2; i < n-1; i++) {
        if (solve2(ans, num, i)) {
            num++;
        }
    }
    while (solve(ans, num)) {
        num++;
    }

    rep(i, n-1) {
        for (int j = i+1; j < n; j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    for (int i = n % 2; i < n-1; i++) {
        ans[i][i+1] = 1;
        for (int j = i + 3; j < n; j += 2) {
            ans[i][j] = 1;
        }
    }

    for (int i = n % 2; i < n-1; i++) {
        ans[i][i+1] = 1;
        for (int j = i + 3; j < n; j += 2) {
            ans[i][j] = 1;
        }
    }

    */
    while (solve(ans, num)) {
        num++;
    }

    rep(i, n-1) {
        for (int j = i+1; j < n; j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
