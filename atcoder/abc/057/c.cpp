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
 
int calc(int a, int b);
signed main()
{
    Int(n);

    vi pr;

    for (int i = 1; i * i <= n; i++) {
        if (!(n % i)) {
            pr.pb(i);
        }
    }

    int ans = calc(1, n);
    for (int i : pr) {
        ans = min(ans, calc(i, n/i));
    }
    cout << ans << endl;

    return 0;
}

int calc(int a, int b)
{
    int aa = 0, bb = 0;
    while (a) {
        aa++; a /=10;
    }
    while (b) {
        bb++; b /= 10;
    }
    return max(aa, bb);
}

