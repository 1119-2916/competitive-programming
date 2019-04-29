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

    int2(n, m);
    vvi data(n, vi(m));
    rep(i, n) {
        rep(j, m) {
            cin >> data[i][j];
        }
    }

    vector<pair<pii, pii>> output;
    rep(i, n-1) {
        rep(j, m-1) {
            if (data[i][j] % 2) {
                data[i][j]--;
                data[i][j+1]++;
                output.pb({{i+1, j+1}, {i+1, j+1+1}});
            }
        }
        if (data[i][m-1] % 2) {
            data[i][m-1]--;
            data[i+1][m-1]++;
            output.pb({{i+1, m-1+1}, {i+1+1, m-1+1}});
        }
    }

    rep(j, m-1) {
        if (data[n-1][j] % 2) {
            data[n-1][j]--;
            data[n-1][j+1]++;
            output.pb({{n-1+1, j+1}, {n-1+1, j+1+1}});
        }
    }

    std::cout << output.size() << std::endl;
    rep(i, output.size()) {
        std::cout << output[i].ffir << " " << output[i].fsec << " "
            << output[i].sfir << " " << output[i].ssec << std::endl;
    }

    return 0;
}



