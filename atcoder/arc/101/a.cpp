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

    int ans = INF, pos = n;

    if (n == 1) {
        cout << abs(data[0]) << endl;
        return 0;
    }

    Rep(i, n) {
        if (data[i-1] < 0 && data[i] >= 0) {
            pos = i;
            break;
        }
    }
    if (data[0] >= 0) pos = 0;

    //cout << pos << endl;

    rep(i, pos) {
        int tmp = INF;
        if (pos - i >= k) tmp = -data[i];
        else if (pos - i == k-1 && data[pos] == 0) {
            tmp = -data[i];
        }
        else tmp = data[i] * -2;
        if (pos - i < k && pos + k - (pos - i) - 1 < n) {
            tmp += data[pos + k - (pos - i) - 1];
        } else if (pos + k - (pos - i) - 1 >= n) {
            tmp = INF;
        }
        //cout << tmp << endl;
        ans = min(ans, tmp);
    }

    if (!pos) {
        ans = data[k-1];
    }

    if (pos + k - 1 < n) ans = min(ans, data[pos + k - 1]);

    cout << ans << endl;


    return 0;
}
