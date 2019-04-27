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
    int state = 0;
    rep(i, n) {
        int3(x, y, z);
        Int(m);
        int aa = INF, bb = INF, cc = INF, aaa = 0, bbb = 0, ccc = 0;
        rep(j, m) {
            int3(_a, _b, _c);
            aa = min(aa, _a);
            bb = min(bb, _b);
            cc = min(cc, _c);
            aaa = max(aaa, _a);
            bbb = max(bbb, _b);
            ccc = max(ccc, _c);
        }
        state ^= aa;
        state ^= x-aaa-1;
        state ^= bb;
        state ^= y-bbb-1;
        state ^= cc;
        state ^= z-ccc-1;
    }

    if (__builtin_popcount(state)) 
        std::cout << "WIN" << std::endl;
    else 
        std::cout << "LOSE" << std::endl;

    return 0;
}
