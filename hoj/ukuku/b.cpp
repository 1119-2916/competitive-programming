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
#define Edge pair< int, i_i >
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
    int2(n, q);
    vi day(n, 0);
    multiset<int> funamiYui;
    vector<decltype(funamiYui)::iterator> toshinoKyoko(n, funamiYui.end());

    while (q--) {
        Int(tmp);
        if (tmp == 1) {
            int2(a, b);
            if (toshinoKyoko[b] == funamiYui.end()) {
                toshinoKyoko[b] = funamiYui.insert(a);
            } else if (*toshinoKyoko[b] <= a) {
                funamiYui.erase(toshinoKyoko[b]);
                toshinoKyoko[b] = funamiYui.insert(a);
            }
        } else {
            // 音速でクエリを処理する.
            Int(a);
            decltype(funamiYui)::iterator it = funamiYui.lower_bound(a);
            cout << distance(it, funamiYui.end()) << endl;
        }
    }

    return 0;
}

