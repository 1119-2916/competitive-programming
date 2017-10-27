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
 
//int dxy[5] = {0, 1, 0, -1, 0};
// assign
 
signed main()
{
    Int(n);
    vi d(n*3);
    rep(i, n*3) {
        cin >> d[i];
    }
    sort(all(d));

    int ans = 0;

    int i = 0, j = (3 * n)-1;
    for (int i = 0; i < n; i++) {
        ans += d[j-1];
//        cout << j-1 << endl;
        j -= 2;
    }
    
    cout << ans << endl;



    return 0;
}

