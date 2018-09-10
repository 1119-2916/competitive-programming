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
// cmd


struct PartiallyPersistentUnionFind
{
  vector< int > data;
  vector< int > last;
  vector< vector< pair< int, int > > > add;
 
  PartiallyPersistentUnionFind() {}
 
  PartiallyPersistentUnionFind(int sz) : data(sz, -1), last(sz, 1e9), add(sz)
  {
    for(auto &vs : add) vs.emplace_back(-1, -1);
  }
 
  bool unite(int t, int x, int y)
  {
    x = find(t, x);
    y = find(t, y);
    if(x == y) return false;
    if(data[x] > data[y]) swap(x, y);
    data[x] += data[y];
    add[x].emplace_back(t, data[x]);
    data[y] = x;
    last[y] = t;
    return true;
  }
 
  int find(int t, int x)
  {
    if(t < last[x]) return x;
    return find(t, data[x]);
  }
 
  int size(int t, int x)
  {
    x = find(t, x);
    return -prev(lower_bound(begin(add[x]), end(add[x]), make_pair(t, 0ll)))->second;
  }

  bool same(int t, int a, int b)
  {
      return find(t, a) == find(t, b);
  }
};
/**
 * parent : size を負で持つ。負値でなければ参照する親のindexを持つ
 * timestamp : uniteされた時間を持つ
 * history : uniteされる寸前のtimeとsizeを持つ
struct PartiallyPersistentUnionFind
{
    using data_type = int;
    vector<data_type> parent, timestamp;
    vector< vector< pair< data_type, data_type > > > history;

    PartiallyPersistentUnionFind() {}

    PartiallyPersistentUnionFind(int sz)
        : parent(sz, -1), timestamp(sz, 1e9), history(sz)
    {
        for (auto &vs : history) vs.emplace_back(-1, -1);
    }

    bool unite(int t, int x, int y)
    {
        x = find(t, x);
        y = find(t, y);
        if (x == y) return false;
        if (parent[x] > parent[y]) swap(x, y);
        parent[x] += parent[y];
        history[x].emplace_back(t, parent[x]);
        parent[y] = x;
        timestamp[y] = t;
        return true;
    }
    int find(int t, int x)
    {
        if (t < timestamp[x]) return x;
        return find(t, parent[x]);
    }

    int size(int t, int x)
    {
        x = find(t, x);
        return -prev(lower_bound(begin(history[x]), end(history[x]), 
                    make_pair(t, (data_type)0)))->second;
    }
    bool same(int t, int x, int y)
    {
        return find(t, x) == find(t, y);
    }
};
 */


signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int2(n, m);
    PartiallyPersistentUnionFind uf(n);

    int t = 0;
    while (m--) {
        int2(a, b); a--; b--;
        ++t;
        uf.unite(t, a, b);
    }

    Int(q);
    while (q--) {
        int2(a, b); a--; b--;
        int left = 0, right = n+1;
        if (!uf.same(n+1, a, b)) {
            cout << -1 << endl;
            continue;
        }
        while (right - left > 1) {
            int mid = (right + left) / 2;
            if (uf.same(mid, a, b)) {
                right = mid;
            } else {
                left = mid;
            }
        }
        cout << right << endl;
    }

    return 0;
}


