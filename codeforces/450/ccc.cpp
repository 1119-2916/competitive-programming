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

int n, a[101000], tr[404000], ll, rr, x, ans1, ans2, num, ma[101000], w;

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    cin >> n;
    Rep(i, n+1) {
        cin >> a[i];
        ma[i] = max(ma[i-1], a[i]);
    }
    ans1 = -100000000;
    Rep(i, n+1) {
        if (a[i] > ma[i-1]) {
            num = -1; w = ma[i-1];
            for (int j = i+1; j < n+1; j++) {
                if (a[j] > a[i]) break;
                else {
                    if (a[j] > w && a[j] < a[i]) num++;
                    w = max(w, a[j]);
                }
            }
        } else {
            num = 0;
        }
        if (num > ans1) {
            ans1 = num; ans2 = a[i];
        } else if (num == ans1 && ans2 > a[i]) ans2 = a[i];
    }
    cout << ans2 << endl;

    return 0;
}




