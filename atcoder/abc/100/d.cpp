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
#define Decimal fixed << setprecision(10)

//int dxy[5] = {0, 1, 0, -1, 0};
// cmd

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int2(n, m);
    vector<int> a(n);
    vector<int> b(n);
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cin >> b[i];
        cin >> c[i];
    }

    int ans = 0;
    for (int i = 0; i < 8; i++) {
        vi score(0);
        rep(j, n) {
            int tmp = 0;
            if (i & 1) {
                tmp += a[j];
            } else {
                tmp += -a[j];
            }
            if (i & 2) {
                tmp += b[j];
            } else {
                tmp += -b[j];
            }
            if (i & 4) {
                tmp += c[j];
            } else {
                tmp += -c[j];
            }
            score.pb(tmp);
        }
        sort(all(score)); reverse(all(score));
        int tmp = 0;
        rep(j, m) tmp += score[j];
        ans = max(ans, tmp);
    }

    cout << ans << endl;

    return 0;
}
