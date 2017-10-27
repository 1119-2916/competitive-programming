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
    int sum = 0;
    vi table(m+2, 0);
    rep(i, n) {
        int a, b, c;
        cin >> a >> b >> c;
        table[a] += c;
        table[b+1] -= c;
        sum += c;
    }
    int mi = table[1];
    for (int i = 2; i < m+1; i++) {
        table[i] += table[i-1];
        mi = min(mi, table[i]);
    }
    cout << sum - mi << endl;



    return 0;
}

