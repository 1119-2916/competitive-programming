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

    vi xyz(3);
    cin >> xyz[0] >> xyz[1] >> xyz[2];
    int n = xyz[0] + xyz[1] + xyz[2], yui = 0;

    vector<pair<pair<int, pii>, pii>> data(n);
    int ans = 0;
    {
        vp tmp(3);
        rep(i, n) {
            int3(a, b, c);
            tmp[0].fir = a; tmp[1].fir = b; tmp[2].fir = c;
            tmp[0].sec = 0; tmp[1].sec = 1; tmp[2].sec = 2;
            sort(all(tmp));
            ans += tmp[0].fir;
            data[i].fsec.sec = -(tmp[0].fir - tmp[2].fir);
            data[i].fsec.fir = -(tmp[0].fir - tmp[1].fir);
            data[i].ffir = tmp[2].fir - tmp[1].fir;
            data[i].sfir = tmp[2].sec;
            data[i].ssec = tmp[1].sec;
            std::cout << data[i].ffir << " " <<
                data[i].fsec.fir << " " <<
                data[i].fsec.sec << " " <<
                data[i].sfir << " " <<
                data[i].ssec << std::endl;
        }
    }
    
    std::cout << "ans : " << ans << std::endl;

    sort(all(data));
    reverse(all(data));

    rep(i, data.size()) {
            std::cout << data[i].ffir << " " <<
                data[i].fsec.fir << " " <<
                data[i].fsec.sec << " " <<
                data[i].sfir << " " <<
                data[i].ssec << std::endl;
        if (xyz[data[i].sfir]) {
            xyz[data[i].sfir]--;
            ans += data[i].fsec.sec;
        } else if (xyz[data[i].ssec]) {
            xyz[data[i].ssec]--;
            ans += data[i].fsec.fir;
        }
        std::cout << "ans : " << ans << std::endl;
    }

    std::cout << ans << std::endl;

    return 0;
}
