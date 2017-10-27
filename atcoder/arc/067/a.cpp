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
#define int2(x, y) int x, y; scanf("%lld %lld", &x, &y);
 
//int dxy[5] = {0, 1, 0, -1, 0};
// assign
 
signed main()
{
    Int(n);
    vi num(n+1), cnt(n+1, 1);
    rep(i, n+1) { num[i] = i; }

    Rep(i, n+1) {
        if (num[i] != 1) {
            int tmp = num[i];
            for (int j = 1; j * tmp <= n; j++) {
                if (!(num[tmp*j] % tmp)) {
                    cnt[tmp]++;
                    num[tmp*j] /= tmp;
                }
            }
        }
    }
    int ans = 1;
    Rep(i, n+1) {
        ans *= cnt[i];
        ans %= MOD;
    }

    cout << ans << endl;


    return 0;
}

