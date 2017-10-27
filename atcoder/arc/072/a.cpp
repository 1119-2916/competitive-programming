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
#define int2(x, y) int x, y; scanf("%lld %lld", &x, &y);
 
//int dxy[5] = {0, 1, 0, -1, 0};
// assign
//
vi data;
 
signed main()
{
    Int(n);

    data.assign(n, 0);

    rep(i,n) {
        cin >> data[i];
    }

    int sum = 0, ans = 0;

    rep(i, n) {
        sum += data[i];
        if (i % 2) {
            if (sum >= 0) {
                ans += sum + 1;
                sum = -1;
            }
        } else {
            if (sum <= 0) {
                ans += -(sum - 1);
                sum = 1;
            }
        }
        //cout << ans << endl;;
        //cout << sum << " " ;
    }
//    cout << ans << endl;



    sum = 0; int ansb = 0;
                
    rep(i, n) {
        sum += data[i];
        if (i % 2) {
            if (sum <= 0) {
                ansb += -(sum - 1);
                sum = 1;
            }
        } else {
            if (sum >= 0) {
                ansb += sum + 1;
                sum = -1;
            }
        }
        //cout << ansb << endl;
    }

    cout << min(ans, ansb) << endl;



    return 0;
}

