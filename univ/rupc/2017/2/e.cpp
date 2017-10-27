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
#define int2(x, y) int x, y; scanf("%lld %lld", &x, &y);
#define UF uftree
 
//int dxy[5] = {0, 1, 0, -1, 0};
// assign

class uftree 
{
    public:
        int size;
        vector<int> par, rank;
        uftree(int n) : size(n), par(n), rank(n) {
            for (int i = 0; i < size; i++) {
                par[i] =  i;
                rank[i] = 0;
            }
        }
        int find(int x) {
            if (par[x] == x) {
                return x;
            } else {
                return par[x] = find(par[x]);
            }
        }
        void unite(int x, int y) {
            x = find(x);
            y = find(y);
            if (x == y) {
                return ;
            }

            if (rank[x] < rank[y]) {
                par[x] = y;
            } else {
                par[y] = x;
                if (rank[x] == rank[y]) {
                    rank[x]++;
                }
            }
        }
        bool same(int x, int y) {
            return find(x) == find(y);
        }
};

struct edge {
    int from, to, len, cost;
};
int n, m;
struct edge data[10000];
pair<double, int> funami[10000];

void make(double x);
bool solve();

signed main()
{
    cin >> n >> m;
    rep(i, m) {
        cin >> data[i].from >> data[i].to >> 
            data[i].len >> data[i].cost;
    }

    double l = 0.0, r = 1.0;
    while (r - l > 0.000001) {
        double ans = (r + l) / 2;
        make(ans);
        //cout << ans << " ";
        if (solve()) {
            r = ans;
        } else {
            l = ans;
        }
    }
    printf("%.10lf\n", l);

    return 0;
}

bool solve()
{
    UF kyoko(n);
    double sum = 0.0;
    for (int i = m -1; i >= 0; i--) {
        if (kyoko.same( data[funami[i].second].from, 
                    data[funami[i].second].to)) {
            sum += funami[i].first;
        } else {
            kyoko.unite(data[funami[i].second].from,
                    data[funami[i].second].to);
        }
    }
    //cout << sum << endl;
    if (sum > 0) return false;
    else return true;
}


void make(double x)
{
    for (int i = 0; i < m; i++) {
        funami[i].first = data[i].cost - data[i].len * x;
        funami[i].second = i;
    }
    sort(funami, funami + m);
}
