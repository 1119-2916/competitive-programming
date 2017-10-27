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
#define all(a) (a).begin(), (a).end()
#define Int(x) int x; scanf("%lld", &x);
#define int2(x, y) int x, y; scanf("%lld %lld", &x, &y);
 
//int dxy[5] = {0, 1, 0, -1, 0};
// assign
 
signed main()
{
    Int(n);
    vi data(n);
    rep(i, n) cin >> data[i];
    int ans = -INF;

    rep(i, n) {
        int tmp = -INF, ptr = 0;
        rep(j, n) {
            if (i == j) continue;
            int sum = 0;
            for (int k = min(i, j)+1; k <= max(i, j); k += 2) {
                sum += data[k];
            }
            if (tmp < sum) {
                tmp = sum; ptr = j;
            }
        }
        //cout << i << " " << ptr << " " << tmp << " ";
        int funami = 0;
        for (int k = min(i, ptr); k <= max(i, ptr); k += 2)
            funami += data[k];
        //cout << funami << endl;
        ans = max(ans, funami);
    }
    cout << ans << endl;






    return 0;
}

