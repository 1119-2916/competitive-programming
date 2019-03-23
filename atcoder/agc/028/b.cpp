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
    vi perm(n);
    rep(i, n) perm[i] = i;

    vi ans(n, 0);
    vector<map<int, int>> funami(n);

    do {
        cout << "# : " << endl;
        rep(i, n) {
            std::cout << perm[i] << " ";
        }
        cout << endl;

        vi used(n, 1);
        vi cnt(n, 0);
        rep(i, perm.size()) {
            int p = perm[i];
            cnt[p]++;
            used[p] = 0;
            for (int j = p+1; j < n; j++) {
                if (!used[j]) break;
                cnt[j]++;
            }
            for (int j = p-1; j >= 0; j--) {
                if (!used[j]) break;
                cnt[j]++;
            }
        }

        rep(i, n) {
            std::cout << cnt[i] << " ";
            funami[i][cnt[i]]++;
            ans[i] += cnt[i];
        }cout << endl;

    } while (next_permutation(all(perm)));

    cout << endl;
    std::cout << "sum : " << std::endl;
    rep(i, n) {
        for (auto j : funami[i]) {
            std::cout << j.second << " ";
        }
        cout << endl;
    }
    cout << endl;
    
    cout << "ans : " << endl;
    rep(i, ans.size()) {
        std::cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}
