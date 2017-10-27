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
#define mp make_pair
#define i_i pair<int, int>
#define vi vector<int>
#define vvi vector<vi >
#define vb vector<bool>
#define vvb vector<vb >
#define vp vector< i_i >
#define all(a) (a).begin(), (a).end()
#define Int(x) int x; scanf("%lld", &x);
 
//int dxy[5] = {0, 1, 0, -1, 0};
// assign
 
signed main()
{
    int n, m;
    while (cin >> n >> m, n) {
        vi data(n);
        rep(i, n) {
            cin >> data[i];
        }
        sort(all(data));
        int pt = 1;
        vi graph(2, 0);
        rep(i, n) {
            if (pt * m > data[i]) {
                graph[pt]++;
            } else {
                pt++;
                i--;
                graph.pb(0);
            }
        }
        int ma = -1;
        rep(i, graph.size()) {
            ma = max(ma, graph[i]);
        }
        double ans = 0.0, diag = (graph.size() - 2);
        Rep(i, graph.size()-1) {
            ans += (graph.size()-1 - i) / diag *
                (double)graph[i] / (double)ma;
        }
        cout << ans + 0.01 << endl;
    }

    return 0;
}

