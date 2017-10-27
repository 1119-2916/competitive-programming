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
    int2(h, w);
    while (h) {
        vvi state(h, vi(w));
        rep(i, h) {
            rep(j, w) {
                cin >> state[i][j];
            }
        }
        int ans = 0;
        rep(sti, h-2) {
            rep(stj, w-2) {
                for (int eni = 2; eni < h; eni++) {
                    for (int enj = 2; enj < w; enj++) {

                        int high = 10;
                        for (int i = stj; i <= enj; i++) {
                            high = min(high, state[sti][i]);
                            high = min(high, state[eni][i]);
                        }
                        for (int i = sti; i <= eni; i++) {
                            high = min(high, state[i][stj]);
                            high = min(high, state[i][enj]);
                        }
                       // cout << high << endl;

                        bool ok = true;
                        int tmp = 0;
                        for (int i = sti+1; i < eni; i++) {
                            for (int j = stj+1; j < enj; j++) {
                                if (state[i][j] >= high) {
                                    ok = false;
                                    break;
                                } else {
                                    tmp += high - state[i][j];
                                }
                            }
                            if (!ok) {
                                break;
                            }
                        }

                        if (ok) {
                            ans = max(ans, tmp);
                        }
                    }
                }
            }
        }
        cout << ans << endl;

        cin >> h >> w;
    }
    return 0;
}

