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

    vp data(3);
    rep(i, 3) {
        int2(a, b);
        data[i].fir = min(a, b);
        data[i].sec = max(b, a);
    }

    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 4; j++) {
            if (i == j) continue;
            for (int k = 1; k <= 4; k++) {
                if (i == k || j == k) continue;
                for (int l = 1; l <= 4; l++) {
                    if (i == l || j == l || k == l) continue;
                    //cout << i << " " << j << " " << k << " " << l << endl;
                    bool fl = false;
                    rep(p, data.size()) {
                        if (data[p].fir == min(i, j) && 
                                data[p].sec == max(i, j)) {
                            fl = true;
                            break;
                        }
                    }
                    if (!fl) continue;
                    fl = false;
                    rep(p, data.size()) {
                        if (data[p].fir == min(k, j) && 
                                data[p].sec == max(k, j)) {
                            fl = true;
                            break;
                        }
                    }
                    if (!fl) continue;
                    fl = false;
                    rep(p, data.size()) {
                        if (data[p].fir == min(k, l) && 
                                data[p].sec == max(k, l)) {
                            fl = true;
                            break;
                        }
                    }
                    if (!fl) continue;
                    else {
                        cout << "YES" << endl;
                        return 0;
                    } 
                }
            }
        }
    }

    cout << "NO" << endl;





    return 0;
}
