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
    int2(n, m);
    vi a(n);
    rep(i, n) {
        cin >> a[i];
    }
    vi pow;
    int k = 1;
    while (1) {
        pow.pb(k);
        k *= m;
        if (k > 1000100010001000) {
            break;
        } else if(k == 1) {
            break;
        }
    }

    //for (int i : pow) cout << i << " "; cout << endl;

    int ans = 0;
    vi sum(n, 0);
    map<int, int> s;
    s[0] = 1;
    sum[0] = a[0];
    s.insert(i_i(sum[0], 1));
    for (int i : pow) {
        if (i == sum[0]) {
            ans++;
        }
    }
    Rep(i, n) {
        sum[i] += sum[i-1] + a[i];
        for (int j : pow) {
            if (s.find(sum[i] - j) != s.end()) {
                ans += s[sum[i] - j];
            }
        }
        if (s.find(sum[i]) != s.end()) {
            s[sum[i]]++;
        } else {
            s.insert(i_i(sum[i], 1));
        }
    }
    cout << ans << endl;
    return 0;
}
