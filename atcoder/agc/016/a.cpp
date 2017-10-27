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
    string st;
    cin >> st;
    vvi test(26);

    rep(i, 26) {
        int cnt = 0;
        rep(j, st.size()) {
            if (st[j] == i + 'a') {
                test[i].pb(cnt);
                cnt = 0;
            } else {
                cnt++;
            }
        }
        test[i].pb(cnt);
    }

    int ans = INF;
    rep(i, 26) {
        int cnt = 0;
        bool up = true;
        rep(j, test[i].size()) {
            if (test[i][j]) {
                up = false;
            }
        }
        while (!up) {
            cnt++;
            rep(j, test[i].size()) {
                if (!j && test[i][j]) {
                    test[i][j]--;
                } else if (!j) {
                    int mxt = 0;
                    rep(k, test[i].size()) {
                        if (test[i][mxt] < test[i][k]) {
                            mxt = k;
                        }
                    }
                    test[i][mxt]--;
                } else {
                    test[i][j]--;
                }
            }
            up = true;
            rep(j, test[i].size()) {
                if (0 < test[i][j]) {
                    up = false;
                }
            }
        }
        cout << cnt << endl;
        ans = min(ans, cnt);
    }
    cout << ans << endl;







    return 0;
}

