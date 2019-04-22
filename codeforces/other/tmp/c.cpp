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

void solve(int n)
{
    int ret = 0;
    rep(i, 7) {
        int tag = pow(2, i);
        vvi data(2);
        int status = 0;
        Rep(j, n+1) {
            data[status].pb(j);
            if (j % tag == 0) status = (status == 1 ? 0 :1);
        }
        if (data[0].size() && data[1].size()) {
            std::cout << data[0].size() << " " << data[1].size() << " ";
            rep(j, data[0].size()) std::cout << data[0][j] << " ";
            rep(j, data[1].size()) std::cout << data[1][j] << " ";
            cout << endl;
            Int(tmp);
            ret = max(ret, tmp);
        }
    }
    std::cout << -1 << " " << ret << std::endl;
    //Int(hoge);
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    Int(q);
    while (q--) {
        Int(n);
        solve(n);
    }

    return 0;
}
