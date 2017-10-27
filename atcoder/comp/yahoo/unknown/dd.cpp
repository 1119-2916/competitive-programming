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
    int2(q, k);
    int ans = 0;
    map<int, int> table;

    rep(i, q) {
        int com, d, cnt;
        cin >> com;
        if (com == 1) {
            cin >> d >> cnt;
            if (table.find(d) != table.end()) {
                table[d] += cnt;
            } else {
                table.insert(mp(d,cnt));
            }
            int dist = 0, bef = 0;
            ans = 0;
            for (auto i = table.begin(); i != table.end(); i++) {
                dist += (i->first - bef) * k;
                bef = i->first;
                ans += min(dist, i->second);
                dist -= min(dist, i->second);
            }
        } else {
            cin >> d;
            cout << ans << endl;
        }
    }

    return 0;
}
