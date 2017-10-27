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
 
typedef pair<int, int> i_i;
typedef vector<int> vi;
typedef vector<vi > vvi;
typedef vector<bool> vb;
typedef vector<vb > vvb;
//int dxy[5] = {0, 1, 0, -1, 0};
// assign
 
signed main()
{
    int n, m;
    cin >> n >> m;
    vvb graph(n, vb(n, false));
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        a--;b--;
        graph[a][b] = true;
        graph[b][a] = true;
    }
    rep(i, n) {
        vb used(n, false);
        vb stk(n, false);
        rep(j, n) {
            if (i == j) {
                used[j] = true;
            } else if (graph[i][j]) {
                used[j] = true;
                stk[j] = true;
            }
        }
        int ret = 0;
        rep(k, n) {
            if (stk[k]) {
                rep(j, n) {
                    if (graph[k][j] && !used[j]) {
                        ret++;
                        used[j] = true;
                    }
                }
            }
        }
        cout << ret << endl;
    }
    return 0;
