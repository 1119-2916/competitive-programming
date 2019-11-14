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
#define eb emplace_back
#define mp make_pair
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vi >
#define vb vector<bool>
#define vvb vector<vb >
#define vp vector< pii >
#define all(a) (a).begin(), (a).end()
#define Int(x) int x; cin >> x;
#define int2(x, y) Int(x); Int(y);
#define int3(x, y, z) Int(x); int2(y, z);
#define in(x, a, b) ((a) <= (x) && (x) < (b))
#define fir first
#define sec second
#define ffir first.first
#define fsec first.second
#define sfir second.first
#define ssec second.second
#define Decimal fixed << setprecision(10)

//int dxy[5] = {0, 1, 0, -1, 0};
// cmd

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    string st;
    cin >> st;

    map<string, int> dp, nxt, nnxt, null;
    dp["first"] = 0;

    rep(i, st.size()) {
        nnxt = null;
        for (auto j = dp.begin(); j != dp.end(); j++) {
            string tmp = ""; tmp += st[i];
            if (j->first != tmp) {
                nxt[tmp] = max(j->second + 1, nxt[tmp]);
            }
            if (i+1 < st.size()) {
                tmp += st[i+1];
                if (j->first != tmp) {
                    nnxt[tmp] = max(j->second + 1, nnxt[tmp]);
                }
            }
        }
        dp = nxt;
        nxt = nnxt;
    }
    int ans = 0;
    for (auto i = dp.begin(); i != dp.end(); i++) {
        ans = max(ans, i->second);
    }
    
    std::cout << ans << std::endl;

    return 0;
}