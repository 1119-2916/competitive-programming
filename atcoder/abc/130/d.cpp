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
    vector<int> data(n), sum(n+1, 0);
    for (int i = 0; i < n; i++) {
        cin >> data[i];
        sum[i+1] = sum[i] + data[i];
    }

    int ans = 0;
    rep(i, n) {
        int targ = k + sum[i];
        if (targ > sum.back()) {
            int tmp = n - i;
            ans += tmp;
            //cout << "tmp:" << tmp << endl;
        } else {
            auto p = lower_bound(all(sum), targ) - sum.begin();
            int tmp = p - i - 1;
            ans += tmp;
            //cout << "p : " << p << ", tmp:" << tmp << endl;
        }
    }

    cout << n*(n+1)/2 - ans << endl;

    return 0;
}
