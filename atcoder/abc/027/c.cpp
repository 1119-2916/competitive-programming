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
    int cnt = 0;
    for (int i = n; i ; i/=2) cnt++;

    int x = 1;
    if (cnt % 2) {
        int i;
        for (i = 0; ; i++) {
            if (i % 2) {
                x *= 2;
            } else {
                x = 2 * x + 1;
            }
            if (x > n) {
                break;
            }
        }
        if (i % 2) {
            cout << "Takahashi" << endl;
        } else {
            cout << "Aoki" << endl;
        }
    } else {
        int i;
        for (i = 0; ; i++) {
            if (i % 2) {
                x = 2 * x + 1;
            } else {
                x *= 2;
            }
            if (x > n) {
                break;
            }
        }
        if (i % 2) {
            cout << "Takahashi" << endl;
        } else {
            cout << "Aoki" << endl;
        }
    }

    return 0;
}

