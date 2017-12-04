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
    vi table(n+3, 0);
    int ans = 0;
    for (int i = 2; i < n+2; i++) {
        if (table[i] == 0) {
            table[i] = 1;
            for (int j = 2; i*j < n+2; j++) {
                table[i*j] = max(table[i*j], j);
            }
        }
        ans = max(table[i], ans);
    }
    cout << ans << endl;
    cout << table[2];
    for (int i = 3; i < n+2; i++) {
        cout << " " << table[i];
    }
    cout << endl;

    return 0;
}

