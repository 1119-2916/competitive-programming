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
    
    Int(data);
    while (data--) {
        Int(n);
        vector<int> data(n);
        int sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> data[i];
            data[i] %= 4;
            sum += data[i];
        }
        if (sum % 4) {
            cout << -1 << endl;
            continue;
        }
        vi cnt(4, 0);
        rep(i, n) cnt[data[i]]++;
        int ans = 0, tmp = 0;

        ans += (min(cnt[1], cnt[3]));
        cnt[1] -= ans; cnt[3] -= ans;

        tmp = cnt[2] / 2;
        ans += tmp; cnt[2] %= 2;

        tmp = cnt[1] / 2;
        cnt[1] = 0;
        ans += tmp; cnt[2] += tmp;

        tmp = cnt[3] / 2;
        cnt[3] = 0;
        ans += tmp; cnt[2] += tmp;

        ans += cnt[2] / 2;

        cout << ans << endl;

    }
        

    return 0;
}
