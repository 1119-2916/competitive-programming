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

    vector<int> data(n);
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }
    
    int ans = 0, kk = (k * (k - 1) / 2) % MOD;
    rep(i, n) {
        int cntend = 0;
        for (int j = n-1; j > i; j--) {
            if (data[i] > data[j]) cntend++;
        }
        //cout << cntend << " ";
        ans = (ans + ((cntend * k) % MOD)) % MOD;
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if (data[i] > data[j]) cnt++;
        }
        //cout << cnt << endl;
        ans = (ans + ((((k-1) * cnt * k) % MOD) + (MOD - ((cnt * kk) % MOD))) % MOD) % MOD;
        //ans = (ans + ((cnt * (((k-1)) % MOD) * kk ) % MOD)) % MOD;
    }

    std::cout << ans << std::endl;

    return 0;
}
