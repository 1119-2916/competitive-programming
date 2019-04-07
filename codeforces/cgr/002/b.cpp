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

bool solve(int h, vi &input, int k)
{
    vi data(k);
    rep(i, k) data[i] = input[i];
    sort(all(data));
    int s = 0;
    for (int i = k-1; i >= 0; i -= 2) {
        s += data[i];
    }
    //std::cout << k << " : " << s << std::endl;
    if (s > h) return false;
    else return true;
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int2(n, h);
    vector<int> data(n);
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }
    
    if (solve(h, data, data.size())) {
        std::cout << n << std::endl;
        return 0;
    }

    int l = 1, r = n;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (solve(h, data, mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }

    std::cout << l << std::endl;

    return 0;
}
