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
int z = 0; 
//int dxy[5] = {0, 1, 0, -1, 0};
// assign
 
signed main()
{
    Int(cs);
    rep(loop, cs) {
        cout << "Case #" << loop + 1 << ": ";

        int2(n, k);
        int s = n, l = n;
        map<int, int> funami;
        funami[n] = 1;
        while (k) {
            int ns, nl, tmp = l;
            int cnt = funami[tmp];
            if (k <= funami[tmp]) {
                cout << max(z, ((tmp-1)/2+((tmp-1)%2)));
                cout << " " << ((tmp-1)/2) << endl;
                break;
            }
            ns = max(z, ((tmp-1)/2));
            nl = max(z, ((tmp-1)/2+((tmp-1)%2)));
            funami[ns] += cnt; funami[nl] += cnt;
            funami[tmp] -= cnt; k -= cnt;

            tmp = s; cnt = funami[tmp];
            if (k <= funami[tmp]) {
                cout << max(z, ((tmp-1)/2+((tmp-1)%2)));
                cout << " " << ((tmp-1)/2) << endl;
                break;
            }
            ns = max(z, ((tmp-1)/2));
            nl = max(z, ((tmp-1)/2+((tmp-1)%2)));
            funami[ns] += cnt; funami[nl] += cnt;
            funami[tmp] -= cnt; k -= cnt;

            s = ns; l = nl;
        }
    }

    return 0;
}

