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

    vvi add(m+2), rem(m+2);


    rep(i, n) {
        Int(a);
        Int(b);
        add[a].pb(i);
        rem[b+1].pb(i);
    }

    Rep(i, m+1) {
        set<int> ans;
        for (int j = 1; i * j < m+1; j++) {
            for (int a : add[i*j]) {
                ans.insert(a);
            }
        }
        cout << ans.size() << endl;
    }


    return 0;
}

