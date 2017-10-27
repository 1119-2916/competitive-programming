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
#define Edge pair< i_i, int>
#define all(a) (a).begin(), (a).end()
#define Int(x) int x; scanf("%lld", &x);
#define int2(x, y) int x, y; scanf("%lld %lld", &x, &y);
#define fir first
#define sec second
#define ffir first.first
#define fsec first.second
#define sfir second.first
#define ssec second.second
 
//int dxy[5] = {0, 1, 0, -1, 0};
// assign
 
signed main()
{
    int n;
    while (cin >> n, n) {
        vp yui(n);
        rep(i, n) {
            cin >> yui[i].fir >> yui[i].sec;
            yui[i].sec *= -1;
        }
        Int(m);
        rep(i, m) {
            i_i kyoko;
            cin >> kyoko.fir >> kyoko.sec;
            kyoko.sec *= -1;
            yui.pb(kyoko);
        }

        sort(all(yui));
        vi funami(1010, 0);
        rep(i, n+m) {
            int yuikyo = 0;
            rep(j, -yui[i].sec) {
                yuikyo = max(yuikyo, funami[j]);
            }
            funami[-yui[i].sec] = yuikyo+1;
        }
        int yuruyuri = 0;
        rep(i, 1010) {
            yuruyuri = max(yuruyuri, funami[i]);
        }
        cout << yuruyuri << endl;
    }

    return 0;
}

