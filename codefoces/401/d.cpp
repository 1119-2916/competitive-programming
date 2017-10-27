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
    vector< string > input(n), ans(n, "");
    rep(i, n) {
        cin >> input[i];
    }
    
    ans[n-1] = input[n-1];
    for (int i = n-1; i > 0; i--) {
        if (ans[i].compare(input[i-1]) < 0) {
            rep(j, min(input[i-1].size(), ans[i].size()) ) {
                if (input[i-1][j] > ans[i][j]) {
                    ans[i-1] = input[i-1].substr(0, j);
                    break;
                }
            }
            if (ans[i-1] == "") {
                ans[i-1] = ans[i];
            }
        } else {
            ans[i-1] = input[i-1];
        }
    }
    rep(i, n) {
        cout << ans[i] << endl;
    }

    return 0;
}

