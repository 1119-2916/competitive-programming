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

int dx[4] = {0, 1, -1, 0};
int dy[4] = {-1, 0, 0, 1};
// cmd

int solve(vector<string> &table, int a, int b)
{
    int ret = 0;
    vi np(8);
    rep(i, 4) {
        np[i*2] = a; np[i*2+1] = b;
    }

    while (1) {
        int cnt = 0;
        rep(i, 4) {
            np[i*2] += dx[i]; np[i*2+1] += dy[i];
            if (!(in(np[i*2], 0, table.size()) && in(np[i*2+1], 0, table[0].size()))) cnt++;
        }
        if (cnt > 1) break;

        cnt = 0;
        rep(i, 4) {
            //cout << "point : " << np[i*2] << " " << np[i*2+1] << endl;
            if (in(np[i*2], 0, table.size()) && in(np[i*2+1], 0, table[0].size())) {
                if (table[np[i*2]][np[i*2+1]] == '#')cnt++;
            }
        }
        if (cnt >= 3) ret++;
    }
    if (ret) cout << a << " " << b << endl;
    return ret;
}



signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int2(h, w);
    vector<string> table(h);
    rep(i, h) cin >> table[i];

    int ans = 0;

    rep(i, h) {
        rep(j, w) {
            ans += solve(table, i, j);
        }
    }

    cout << ans << endl;

    return 0;
}
