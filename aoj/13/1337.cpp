#include <bits/stdc++.h>

using namespace std;

#define INF 10010001000
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

//int dxy[5] = {0, 1, 0, -1, 0};
// cmd

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

void solve(int n)
{
    vector<pair<pii, pii>> input(n);
    vector<int> zx, zy;
    zy.eb(0); zx.eb(0);
    rep(i, n) {
        cin >> input[i].ffir >> input[i].fsec
            >> input[i].sfir >> input[i].ssec;
        input[i].ffir++;
        input[i].sfir++;
        input[i].fsec++;
        input[i].ssec++;
        zx.eb(input[i].ffir);
        zy.eb(input[i].fsec);
        zx.eb(input[i].sfir);
        zy.eb(input[i].ssec);
    }
    sort(all(zx));
    zx.erase(unique(all(zx)), zx.end());
    map<int, int> rzx;
    rep(i, zx.size()) rzx[zx[i]] = i;
    //cout << "zx" << endl; rep(i, zx.size()) cout << zx[i] << " ";
    //cout << endl;

    sort(all(zy));
    zy.erase(unique(all(zy)), zy.end());
    map<int, int> rzy;
    rep(i, zy.size()) rzy[zy[i]] = i;
    //cout << "zy" << endl; rep(i, zy.size()) cout << zy[i] << " ";
    //cout << endl;

    vvi tx(zx.size()+1, vi(zy.size()+2, 0)); // x ni heikou
    vvi ty(zx.size()+2, vi(zy.size()+1, 0));
    rep(i, n) {
        tx[rzx[input[i].ffir]][rzy[input[i].fsec]]++;
        tx[rzx[input[i].sfir]][rzy[input[i].fsec]]--;
        tx[rzx[input[i].ffir]][rzy[input[i].ssec]]++;
        tx[rzx[input[i].sfir]][rzy[input[i].ssec]]--;

        ty[rzx[input[i].ffir]][rzy[input[i].fsec]]--;
        ty[rzx[input[i].ffir]][rzy[input[i].ssec]]++;
        ty[rzx[input[i].sfir]][rzy[input[i].fsec]]--;
        ty[rzx[input[i].sfir]][rzy[input[i].ssec]]++;
    }
    rep(j, tx[0].size()) {
        rep(i, tx.size()-1) {
            tx[i+1][j] += tx[i][j];
        }
    }
    rep(i, ty.size()) {
        rep(j, ty[0].size()-1) {
            ty[i][j+1] += ty[i][j];
        }
    }
/*
    cout << "table - y" << endl;
    rep(i, tx.size()) {
        rep(j, tx[i].size()) {
            cout << (tx[i][j] ? 1 : 0) << " ";
        }
        cout << endl;
    }

    cout << "table - x" << endl;
    rep(i, ty.size()) {
        rep(j, ty[i].size()) {
            cout << (ty[i][j] ? 1 : 0) << " ";
        }
        cout << endl;
    }
//*/
    //cout << tx.size() << " " << tx[0].size() << " "
    //     << ty.size() << " " << ty[0].size() << endl;
    UnionFind uf((zx.size() + 3) * (zy.size() + 3));
    int rect = zy.size() + 3;
    rep(i, tx.size()) {
        rep(j, tx[i].size()) {
            if (!tx[i][j]) {
                uf.unite(rect * (i+1) + j, rect * (i+1) + j+1);
            }
        }
    }

    rep(i, ty.size()) {
        rep(j, ty[i].size()) {
            if (!ty[i][j]) {
                uf.unite(rect * i + j+1, rect * (i+1) + j+1);
            }
        }
    }

    //cout << "tx : " << tx.size() << ", " << ty.size() << endl;
    set<int> ans;
    //cout << "result << " << endl;
    rep(i, tx.size()+1) {
        rep(j, ty[0].size()+1) {
            if (!i && !j) {
                //cout << "  0";
                continue;
            }
            //cout << uf.root(i * rect + j) << " ";
            //printf("%3d", uf.root(i * rect + j));
            //cout << uf.root(i * rect + j) << " ";
            ans.insert(uf.root(i * rect + j));
        }
        //cout << endl;
    }

    cout << ans.size() << endl;
}


signed main()
{
    //std::ios::sync_with_stdio(false);
    //std::cin.tie(0);

    Int(n);
    while (n) {
        solve(n);
        cin >> n;
    }

    return 0;
}
