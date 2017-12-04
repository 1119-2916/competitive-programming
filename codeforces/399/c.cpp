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
    int n, k, x;
    cin >> n >> k >> x;
    vi input(n);
    rep(i, n) {
        cin >> input[i];
    }
    if (k) {
        sort(all(input));
        for (int i = 0; i < n; i += 2) {
            input[i] ^= x;
        }
        k--;
    }
    if (k % 2) {
        sort(all(input));
        for (int i = 0; i < n; i += 2) {
            input[i] ^= x;
        }
    }
    sort(all(input));
    cout << input[n-1] << " " << input[0] << endl;

    return 0;
}

