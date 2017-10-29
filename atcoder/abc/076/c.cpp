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
#define Int(x) int x; cin >> x;
#define int2(x, y) Int(x); Int(y);
#define int3(x, y, z) Int(x); int2(y, z);
#define fir first
#define sec second
#define ffir first.first
#define fsec first.second
#define sfir second.first
#define ssec second.second

//int dxy[5] = {0, 1, 0, -1, 0};
// cmdG

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    string st, yui;
    cin >> st >> yui;

    string ans = "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";
    for (int i = st.size() - yui.size(); i >= 0; i--) {
        bool ok = true;
        string tmp;
        for (int j = 0; j < i; j++) {
            if (st[j] == '?') {
                tmp.pb('a');
            } else {
                tmp.pb(st[j]);
            }
        }
        for (int j = 0; j < yui.size(); j++) {
            if (!(st[i+j] == yui[j] || st[i+j] == '?')) {
                ok = false;
                break;
            } else {
                tmp.pb(yui[j]);
            }
        }
        for (int j = i + yui.size(); j < st.size(); j++) {
            if (st[j] == '?') {
                tmp.pb('a');
            } else {
                tmp.pb(st[j]);
            }
        }
        if (ok) {
            ans = (ans > tmp) ? tmp : ans;
        }
    }

    if (ans == "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz") {
        cout << "UNRESTORABLE" << endl;
    } else {
        cout << ans << endl;
    }


    return 0;
}


