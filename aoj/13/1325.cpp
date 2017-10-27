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
    Int(s);

    while (s--) {
        int2(p, q);
        int cnt = 0;
        rep(i, 301) {
            rep(j, 301) {
                int m = i - 150, n = j - 150;
                if (m*m + n*n < 2) continue;
                if (!((m*p+n*q)%(m*m+n*n)) && 
                    !((m*q-n*p)%(m*m+n*n))) {
                    //cout << m << " " << n << endl;
                    cnt++;
                }
            }
        }
        if (cnt == 4) {
            cout << 'P' << endl;
        } else {
            cout << 'C' << endl;
        }
    }

    return 0;
}

