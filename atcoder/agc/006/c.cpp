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

int next(int a, int b)
{
    int diff = abs(a - b);
    if (a < b) {
        return a + diff + diff;
    } else {
        return a - diff - diff;
    }
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n = 100000;
    vector<double> dp(n, 0);

    int st = n / 2;
    set<int> pos;
    pos.insert(st);
    dp[st] = 1;
    vi nomv = {n / 2 - 3, n / 2 + 7};

    rep(i, 100) {
        vector<double> nxt(n, 0);
        set<int> npos;
        for (auto i : pos) {
            int a = next(i, nomv[0]), b = next(i, nomv[1]);
            npos.insert(a);
            npos.insert(b);
            nxt[a] += dp[i] / 2;
            nxt[b] += dp[i] / 2;
        }
        pos = npos;
        dp = nxt;
        for (auto i : npos) {
            cout << nxt[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
