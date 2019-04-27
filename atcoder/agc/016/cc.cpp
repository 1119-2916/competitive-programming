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

    int2(H, W);
    int2(h, w);

    if (H % h) {
        std::cout << "Yes" << std::endl;
        vi ans(H+1, 0);
        ans[H] = 1;
        for (int i = H-h; i > 0; i -= h) {
            ans[i] = ans[i+h]+1;
        }
        rep(i, H) {
            if (!ans[i]) ans[i] = -(i / h);
        }
        for (int i = H; i > 0; i--) {
            ans[i] = ans[i] - ans[i-1];
        }
        Rep(i, ans.size()) {
            rep(j, W) {
                std::cout << ans[i] << " ";
            }
            cout << endl;
        }
    } else if (W % w) {
        std::cout << "Yes" << std::endl;
        vi ans(W+1, 0);
        ans[W] = 1;
        for (int i = W-w; i > 0; i -= w) {
            ans[i] = ans[i+w]+1;
        }
        rep(i, W) {
            if (!ans[i]) ans[i] = -(i / w);
        }
        for (int i = W; i > 0; i--) {
            ans[i] = ans[i] - ans[i-1];
        }
        rep(i, H) {
            Rep(j, ans.size()) {
                std::cout << ans[j] << " ";
            }
            cout << endl;
        }
    } else {
        std::cout << "No" << std::endl;
    }

    return 0;
}
