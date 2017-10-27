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
    string s;
    cin >> s;
    vi cnt(26);
    rep(i, n) {
        cnt[s[i] - 'a']++;
    }
    string ans = "";
    rep(i, n) {
        rep(j, 26) {
            if (cnt[j]) {
                vi tc = cnt;
                int t = 0;
                tc[j]--;
                rep(k, ans.size()) {
                    if (ans[k] != s[k]) {
                        t++;
                    }
                }
                if (j != s[i] - 'a') {
                    t++;
                }
                for (int k = i+1; k < n; k++) {
                    if (!tc[s[k] - 'a']) {
                        t++;
                    } else {
                        tc[s[k] - 'a']--;
                    }
                }
                if (t <= m) {
                    ans.pb((char)(j + 'a'));
                    cnt[j]--;
                    break;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}

