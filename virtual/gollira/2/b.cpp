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

    Int(n);
    vvi data(n, vi(10, 0));
    rep(i, n) {
        rep(j, 10) {
            cin >> data[i][j];
        }
    }

    vvi funami(n, vi(11));
    rep(i, n) {
        rep(j, 11) {
            cin >> funami[i][j];
        }
    }

    int ans = -INF;
    Rep(i, 1 << 10) {
        vi hoge(10);
        int yui = i;
        rep(j, 10) {
            hoge[j] = yui % 2;
            yui /= 2;
        }
        int score = 0;
        rep(j, n) {
            int tmp = 0;
            rep(k, 10) {
                if (data[j][k] == hoge[k] && hoge[k]) tmp++;
            }
            score += funami[j][tmp];
        }
        ans = max(ans, score);
    }

    cout << ans << endl;

    return 0;
}
