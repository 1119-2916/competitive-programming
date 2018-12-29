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

bool inner(string a, string b)
{
    if (a.size() < b.size()) {
        return false;
    }
    rep(i, a.size() - b.size() + 1) {
        bool fl = true;
        rep(j, b.size()) {
            if (a[i + j] != b[j]) fl = false;
        }
        if (fl) return true;
    }
    return false;
}

bool yui(string a, string b, int p)
{
    rep(i, b.size()) {
        if (p + i < a.size()) {
            if (a[p+i] != b[i]) return false;
        } else {
            break;
        }
    }
    return true;
}

int funami(string a, string b)
{
    int as = a.size(), bs = b.size();
    rep(i, a.size()) {
        if (yui(a, b, i)) return (bs - as + i);
    }
    return b.size();
}

void calc(vector<string> &data, vvi &dist)
{
    rep(i, data.size()) {
        rep(j, data.size()) {
            dist[i][j] = funami(data[i], data[j]);
        }
    }
}

signed Main(int n)
{
    vector<string> input(n);
    rep(i, n) {
        cin >> input[i];
    }

    vi state(n, 0);
    rep(i, n) {
        rep(j, n) {
            if (i == j) continue;
            if (inner(input[i], input[j])) state[j] = 1;
        }
    }

    vector<string> data;
    rep(i, n) {
        if (!state[i]) data.pb(input[i]);
    }
    n = data.size();
    /*
    rep(i, n) {
        std::cout << data[i] << std::endl;
    }
    */
    vvi dist(n, vi(n, 0));
    calc(data, dist);
    /*
    rep(i, n) {
        rep(j, n) {
            std::cout << dist[i][j] << " ";
        }
        cout << endl;
    }
    */
    vvi dp(1 << 15, vi(15, INF));

    rep(i, n) {
        dp[1 << i][i] = data[i].size();
    }

    Rep(i, 1 << n) {
        rep(j, n) {
            if (!(i & (1 << j))) continue;
            rep(k, n) {
                int p = (1 << k);
                if (i & p) continue;
                dp[i | p][k] = min(dp[i | p][k], dp[i][j] + dist[j][k]);
            }
        }
    }
    /*
    rep(i, (1 << n)) {
        rep(j, n) {
            cout << dp[i][j] << " ";
        }
        std::cout << std::endl;
    }
    */
    int ans = INF;
    rep(i, n) ans = min(ans, dp[(1 << n) -1][i]);

    std::cout << ans << std::endl;

    return 0;
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    
    Int(tmp);
    while (tmp) {
        Main(tmp);
        cin >> tmp;
    }
}
