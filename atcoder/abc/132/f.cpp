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

    int2(n, k);
    int nrt = sqrt(n) + 1;
    vi inc;

    for (int i = 1; i * i <= n; i++) {
        inc.pb(n / i);
    }
    
    vi table = inc;
    for (int i = inc.size()-1; i >= 0; i--) {
        if (inc[i] == i+1) continue;
        table[i] = i+1;
        table.pb(inc[i]);
    }

    //rep(i, table.size()) cout << table[i] << " "; cout << endl;

    vi mm(table.size(), 0);
    mm[0] = 1;
    Rep(i, mm.size()) {
        mm[i] = table[i] - table[i-1];
    }
    //rep(i, mm.size()) cout << mm[i] << " "; cout << endl; // kai

    vi mmn = mm; // seni

    Rep(i, k) {
        vi nxt = mm;
        int sm = 0;
        rep(j, mmn.size()) {
            sm = (sm + mm[j]) % MOD;
            //nxt[nxt.size()-1-j] = (sm + nxt[nxt.size()-1-j]) % MOD;
            nxt[nxt.size()-1-j] = (sm * mmn[nxt.size()-1-j]) % MOD;
        }
        //rep(j, nxt.size()) cout << nxt[j] << " "; cout << endl;
        /*
        rep(j, mm.size()) {
            mm[j] = (mm[j] * mmn[j]) % MOD;
        }
        */
        mm = nxt;
    }

    int ans = 0;
    rep(i, mm.size()) ans = (ans + mm[i]) % MOD;

    std::cout << ans << std::endl;

    return 0;
}
