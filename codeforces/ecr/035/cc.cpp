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

bool solve(int a, int b, int c)
{
    vi table(1000, 0);

    rep(da, 10) {
        rep(db, 10) {
            rep(dc, 10) {
                rep(j, table.size()) {
                    table[j] = 0;
                }
                rep(j, table.size()) {
                    if (j % a == da) {
                        table[j] = 1;
                    }
                    if (j % b == db) {
                        table[j] = 1;
                    }
                    if (j % c == dc) {
                        table[j] = 1;
                    }
                }
                bool ret = true;
                rep(j, table.size()) {
                    if (!table[j]) {
                        ret = false;
                        break;
                    }
                }
                if (ret) return true;
            }
        }
    }
    return false;
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    for (int i = 2; i < 30; i++) {
        for (int j = 2; j < 30; j++) {
            for (int k = 2; k < 30; k++) {
                if (solve(i, j, k)) {
                    vi hoge; hoge.pb(i); hoge.pb(j); hoge.pb(k);
                    sort(all(hoge));
                    if (hoge[1] != 2)
                    std::cout << i << " " << j << " " << k << std::endl;
                }
            }
        }
    }

    return 0;
}
