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
    Int(m);

    vb used(n+1, false);

    vi input(m);

    rep(i, m) {
        cin >> input[i];
    }

    for (int i = m-1; i >= 0; i--) {
        if (!used[input[i]]) {
            cout << input[i] << endl;
            used[input[i]] = true;
        }
    }

    Rep(i, n+1) {
        if (!used[i]) {
            cout << i << endl;
        }
    }

    return 0;
}

