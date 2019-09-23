#include <bits/stdc++.h>

using namespace std;

#define int long long
#define rep(i, N) for (int i = 0; i < N; i++)
#define vi vector<int>

struct UnionFind {
    vi parent;
    int size;
    UnionFind(int n) :parent(n, -1), size(n) {}
    bool unite(int x, int y) {
        x = root(x); y = root(y);
        if (x == y) return false;
        if (sizeOf(x) < sizeOf(y)) swap(x, y);
        parent[x] += parent[y]; parent[y] = x; size--;
        return true;
    }
    bool same(int x, int y) { return root(x) == root(y); }
    int root(int x) { return parent[x] < 0 ? x : parent[x] = root(parent[x]); }
    int sizeOf(int x) { return -parent[root(x)]; }
};

signed main()
{
    int n, m;
    cin >> n >> m;
    UnionFind uf(m + 1);
    vi tate(n+1, 0), yoko(n+1, 0);
    vi a(m), b(m);
    rep(i, m) {
        cin >> a[i] >> b[i];
        tate[a[i]]++;
        yoko[b[i]]++;
    }

    /*
    vi used_tate(n+1, 0), used_yoko(n+1, 0);
    rep(i, m) {
        if (tate[a[i]] >= 2 && yoko[b[i]] >= 2) {
            tate[a[i]]--; yoko[b[i]]--;
            ans++;
            used[i] = 1;
        }
    }
    rep(i, m) {
        if (!used[i] && (tate[a[i]] >= 2 || yoko[b[i]] >= 2)) {
            ans++;
            if (tate[a[i]] >= 2) {
                tate[a[i]]--;
            } else {
                yoko[b[i]]--;
            }
        }
    }

    cout << ans << " ";
    */

    rep(i, m) {
        rep(j, m) {
            if (a[i] == a[j] || b[i] == b[j]) {
                uf.unite(i, j);
            }
        }
    }

    set<int> st;
    rep(i, m) {
        st.insert(uf.root(i));
    }
    cout << m - st.size() << endl;

    return 0;
}

