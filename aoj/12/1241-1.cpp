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
    while (n) {
        int ret = 0;
        for (int a = 1; a*a <= n; a++) {
            if (n - a*a == 0) {
                ret++;
            } else {
                for (int b = a; a*a + b*b <= n; b++) {
                    if (n - a*a - b*b == 0) {
                        ret++;
                    } else {
                        for (int c = b; a*a + b*b + c*c <= n; c++) {
                            if (n - a*a - b*b - c*c == 0) {
                                ret++;
                            } else {
                                for (int d = c; a*a + b*b + c*c + d*d <= n; d++) {
                            if (n - a*a - b*b - c*c - d*d == 0) {
                                ret++;
                            }
                                }
                            }
                        }
                    }
                }
            }
        }
        cout << ret << endl;
        cin >> n;
    }

    return 0;
}

