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
    int m = 100001;
    vi imos(m+1, 0), sum(m+1, 0), rsum(m+1, 0);
    vp data(n);
    rep(i, n) {
        int2(a, b);
        a--; b--;
        data[i].fir = a; data[i].sec = b;
        imos[a]++; imos[b]--;
        sum[b]++; rsum[a]++;
    }

    Rep(i, imos.size()) {
        imos[i] += imos[i-1];
        sum[i] += sum[i-1];
    }

    for (int i = rsum.size()-1; i > 0; i--) {
        rsum[i-1] += rsum[i];
    }

    int ans = 0;
    rep(i, n) {
        ans = max(ans, n - rsum[data[i].sec] - sum[data[i].fir]);
    }

    cout << ans << " " << *max_element(all(imos)) << endl;



    return 0;
}
