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

void solve()
{
    int2(n, q);
    vi no(q+2, 0), so(q+2, 0), we(q+2, 0), ea(q+2, 0);
    rep(i, n) {
        int2(x, y);
        string dist;
        cin >> dist;
        if (dist == "N") {
            no[y+2]++;
        } else if (dist == "S") {
            so[y]++;
        } else if (dist == "W") {
            we[x]++;
        } else {
            ea[x+2]++;
        }
    }
    Rep(i, no.size()) no[i] += no[i-1];
    Rep(i, ea.size()) ea[i] += ea[i-1];
    for (int i = so.size()-1; i > 0; i--) so[i-1] += so[i];
    for (int i = we.size()-1; i > 0; i--) we[i-1] += we[i];

    int y = 1;
    Rep(i, q+2) {
        if (so[y] + no[y] < so[i] + no[i]) y = i;
    }
    int x = 1;
    Rep(i, q+2) {
        if (we[x] + ea[x] < we[i] + ea[i]) x = i;
    }
    cout << x-1 << " " << y-1;
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    Int(q);
    rep(i, q) {
        cout << "Case #" << i+1 << ": ";
        solve();
        cout << endl;
    }

    return 0;
}
