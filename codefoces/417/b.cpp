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
    int2(n, m);
    vector <string> state(n);
    rep(i, n) {
        cin >> state[i];
    }
    reverse(all(state));
    /*
    rep(i, n) {
        cout << state[i] << endl;
    }
    */
    vi cnt(n);
    int all = 0;
    rep(i, n) {
        int tmp = 0;
        rep(j, m+2) {
            if (state[i][j] == '1') {
                tmp++;
                all++;
            }
        }
        cnt[i] = tmp;
    }
//    cout << cnt << endl;

    int ans = INF;

    rep(pos, 1 << n) {
        int sum = 0, now = 0, tmp = pos, right = all;
//        cout << pos << " ";
        rep(i, n) {
            right -= cnt[i];
            if ((tmp & 1) == now) {
                        //cout << "koko";
                int l = 0, r = m+2;
                rep(j, m+2) {
                    if (state[i][j] == '1') {
                        l = max(l, j);
                        r = min(r, j);
                    }
                }
                if (right) {
                    if (now) {
                        sum += ((m+1) - r) * 2;
                    } else {
                        //cout << "koko";
                        sum += l * 2;
                    }
                } else {
                    if (now) {
                        sum += (m+1) - r;
                    } else {
                        sum += l;
                    }
                    break;
                }
            } else {
                if (right) {
                    sum += m+1;
                } else {
                    int l = 0, r = m+2;
                    rep(j, m+2) {
                        if (state[i][j] == '1') {
                            l = max(l, j);
                            r = min(r, j);
                        }
                    }
                    //cout << l << " " << r;
                    if (now) {
                        //cout << "now" << now;
                        sum += (m+1) - r;
                    } else {
                        sum += l;
                    }
                    break;
                }
                now = !now;
            }
            sum++;
 //           cout << " " << sum;
            tmp >>= 1;
        }
//        cout << " " << sum << endl;
        ans = min(ans, sum);
    }
    cout << ans << endl;



    return 0;
}

