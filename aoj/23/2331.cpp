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
    Int(n);
    vi ans(100004, 0);
    ans[0]++;
    rep(i, n) {
        Int(a);
        Int(b);
        ans[a]++;
        ans[b+1]--;
    }
    int ret = 0;
    Rep(i, n+2) {
        ans[i] += ans[i-1];
        if (ans[i] >= i) {
            ret = i;
        }
    }
    cout << ret -1 << endl;

    return 0;
}

