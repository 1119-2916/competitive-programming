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
    int n, m, ans = 0;
    vi path;
    cin >> n >> m;
    vvb graph(n, vb(n, false));
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        graph[a-1][b-1] = true;
        graph[b-1][a-1] = true;
    }
    rep(i, n) { path.pb(i); }
    do {
        int bef = 0, ret = 1;
        //rep(i, n) { cout << path[i]; } cout << endl;
        Rep(i, n) {
            if (!graph[bef][path[i]]) {
                ret = 0;
                break;
            }
            bef = path[i];
        }
        ans += ret;
    } while (next_permutation(path.begin()+1, path.end()));

    cout << ans << endl;

    return 0;
}

