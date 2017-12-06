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

    Int(n);
    vvb table(n, vb(10, false));
    rep(i, n) {
        rep(j, 10) {
            Int(tmp);
            table[i][j] = tmp;
        }
    }
    vvi score(n, vi(11, 0));
    rep(i, n) {
        rep(j, 11) {
            cin >> score[i][j];
        }
    }

    int ans = -INF;
    Rep(i, 1 << 10) {
        vb yui(10, false);
        rep(j, 10) {
            yui[j] = (i & (1 << j));
        }
        int sum = 0;
        rep(j, n) {
            int cnt = 0;
            rep(k, 10) {
                cnt += (table[j][k] == yui[k] && table[j][k]);
            }
            sum += score[j][cnt];
        }
        ans = max(ans, sum);
    }
    cout << ans << endl;


    return 0;
}
