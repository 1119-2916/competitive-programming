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
 
//int dxy[5] = {0, 1, 0, -1, 0};
// assign

bool used[100000];
vvi tree;
vector< Edge > ve;

int dfs(int par, int pos)
{
    //cout << "(" << par << "," << pos << ")" << endl;
    int ret = 1;
    /*
    cout << "node : ";
    rep(i, tree[pos].size()) { cout << tree[pos][i] << " ";}
    cout << endl;
    */
    rep(i, tree[pos].size()) {
        if (used[tree[pos][i]]) {
            if (ve[tree[pos][i]].sfir == pos && 
                    ve[tree[pos][i]].ssec != par) {
                ret += dfs(pos, ve[tree[pos][i]].ssec);
            } else if (ve[tree[pos][i]].ssec == pos && 
                    ve[tree[pos][i]].sfir != par) {
                ret += dfs(pos, ve[tree[pos][i]].sfir);
            }
        }
    }
    return ret;
}

/*
 * n
 * a1, b1, c1
 * ...
 * an-1, bn-1, cn-1
 * で木が与えられる(a <-> b, cost).
 * パス上の最大コストをコストとする時
 * 全点対のコストの総和を求めよ.
 *
 * ex
9
6 7 7
5 7 2
1 6 2
4 7 10
5 8 2
1 2 8
2 3 8
1 9 10
288
 *
4
1 2 4
1 3 7
1 4 1
20
 *
 *
7
1 2 1
2 3 1
3 4 1
4 5 1
5 6 1
6 7 1
21
 */


signed main()
{
    /*
     * 分割統治のような解き方をする
     * コストが最大の辺E(a-b, cost)を見つけて
     * その辺に対してa側とb側の要素に分けて
     * |a| * |b| * costを再帰的に繰り返す
     */

    Int(n);
    ve = vector< Edge >(n);
    tree = vvi(n+1, vi());
    rep(i, n-1) {
        cin >> ve[i].sfir >> ve[i].ssec >> ve[i].fir;
    }
    sort(all(ve));
    reverse(all(ve));
    rep(i, n-1) {
        tree[ve[i].sfir].pb(i);
        tree[ve[i].ssec].pb(i);
    }


    int ans = 0;
    memset(used, true, sizeof(used));
    rep(i, ve.size()) {
        //cout << i << " ";
        used[i] = false;
        //cout << dfs(ve[i].sfir, ve[i].ssec) << " ";
        //cout << dfs(ve[i].ssec, ve[i].sfir) << " ";
        //cout << dfs(ve[i].sfir, ve[i].ssec) * dfs(ve[i].ssec, ve[i].sfir)
         //   * ve[i].fir << endl;
        ans += dfs(ve[i].sfir, ve[i].ssec) * dfs(ve[i].ssec, ve[i].sfir)
            * ve[i].fir;
    }

    cout << ans << endl;
    return 0;
}

