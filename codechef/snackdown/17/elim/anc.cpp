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
//

typedef struct node {
    struct node * f;
    vector< struct node *> t;
    int d, id;
}node;

void dfs(node *tree, int dep)
{
    tree->d = dep;
    for (auto i : tree->t) {
        dfs(i, dep+1);
    }
}

void calcdfs(node *tree)
{
    cout << tree->id << " " << tree->d << endl;
    for (auto i : tree->t) {
        calcdfs(i);
    }
}

signed main()
{
    Int(dataset);
    while (dataset--) {
        Int(n);
        vector< node > tree1(n);
        Rep(i, n) {
            int2(a, b);
            a--; b--;
            tree1[a].t.pb(&tree1[b]);
            tree1[b].f = &tree1[a];
        }
        vector< node > tree2(n);
        Rep(i, n) {
            int2(a, b);
            a--; b--;
            tree2[a].t.pb(&tree2[b]);
            tree2[b].f = &tree2[a];
        }
        rep(i, n) {
            tree1[i].id = i+1;
            tree2[i].id = -i-1;
        }
        dfs(&tree1[0], 1);
        dfs(&tree2[0], 1);
        vi ans(n, 1); ans[0] = 0;
        cout << endl;
        Rep(i, n) {
            for (auto j : tree2[i].t) {
                cout << i+1 << endl;
                tree1[i].t.pb(j);
                j->f = &tree1[i];
            }
        }

        dfs(&tree1[0], 1);
        calcdfs(&tree1[0]);
    }
    return 0;
}



