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
    int sum = 0;
    vector<int> data(n);
    for (int i = 0; i < n; i++) {
        cin >> data[i];
        sum += data[i];
    }

    int ans = 1;
    Rep(i, sum+1) {
        if (sum % i) continue;
        int targ = sum / i;
        int amari = 0;
        std::cout << "targ : " << targ << std::endl;
        vi ama(n);
        rep(j, data.size()) {
            amari += data[j] % targ;
            ama[j] = data[j] % targ;
        }
        int cntmin = INF;
        rep(j, data.size()+1) {
            int cntinner = 0;
            rep(k, j) {
                cntinner += targ - ama[k];

        std::cout << "amari : " << amari << std::endl;
        if (amari % targ) {
            continue;
        }
        if (amari <= k) {
            ans = max(ans, targ);
        }
    }

    std::cout << ans << std::endl;

    return 0;
}
