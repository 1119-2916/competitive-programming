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
    int n;
    cin >> n;
    vi input(n);
    rep(i, n) {
        cin >> input[i];
    }
    vi ans(n, 0);

    Rep(i, n+1) {
        int can = i*2;
        for (int j = i * 2, dist = 0; j < n; j++, dist++) {
            if (input[j-1] > (i * 2) + (dist * 2)) {
                can++;
            } else {
                break;
            }
        }
        ans[i-1] = min(can, n);
    }
//    rep(i, n) { cout << ans[i] << endl;}

    int ret = 1;
    rep(i, n) {
        ret *= (ans[i] - i);
        ret %= MOD;
    }
    cout << ret << endl;



    return 0;
}

