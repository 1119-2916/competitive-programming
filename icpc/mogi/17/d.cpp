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
#define eb emplece_back
#define mp make_pair
#define i_i pair<int, int>
#define vi vector<int>
#define vvi vector<vi >
#define vb vector<bool>
#define vvb vector<vb >
#define vp vector< i_i >
#define Edge pair< int, i_i >
#define all(a) (a).begin(), (a).end()
#define Int(x) int x; scanf("%lld", &x);
#define int2(x, y) int x, y; scanf("%lld %lld", &x, &y);
#define fir first
#define sec second
#define ffir first.first
#define fsec first.second
#define sfir second.first
#define ssec second.second
 
//int dxy[5] = {0, 1, 0, -1, 0};
// assign


signed main()
{
    int2(n, m);

    while (n) {
        vi data(n);
        rep(i, n) cin >> data[i];

        int xl = data[0], xr = data[data.size()-1];

        while (xr - xl > 1) {
            int xm = (xr + xl) / 2;
            //cout << "X: " << xm << endl;

            int lv = 1;
            bool ans = true;
            rep(i, m-1) {
                auto e = upper_bound(all(data), lv);
                if (lv + xm > data[data.size()-1]) {
                    ans = false;
                    break;
                }
                //cout << *e << " ";
                if (e == data.begin()) {
                    // 倒せる
                    if (lv + xm > *e) {
                        lv += max(1LL, xm - abs(lv - *e));
                    } else {
                        ans = false;
                        break;
                    }
                } else {
                    //cout << "Yava" << e[-1] << endl;
                    int targ = min(abs(*e - lv), abs(e[-1] - lv));
                    lv += max(1LL, xm - targ);
                }
            }
            //cout << endl;
            
            if (ans) {
                xl = xm;
            } else {
                xr = xm;
            }
        }

            int xm = (xr + xl) / 2;

            int lv = 1;
            bool ans = true;
            rep(i, m-1) {
                auto e = upper_bound(all(data), lv);
                if (lv + xm > data[data.size()-1]) {
                    ans = false;
                    break;
                }
                if (e == data.begin()) {
                    // 倒せる
                    if (lv + xm > *e) {
                        lv += max(1LL, xm - abs(lv - *e));
                    } else {
                        ans = false;
                        break;
                    }
                } else {
                    //cout << "Yava" << e[-1] << endl;
                    int targ = min(abs(*e - lv), abs(e[-1] - lv));
                    lv += max(1LL, xm - targ);
                }
            }
            
            if (ans) {
                cout << xm << endl;
            } else {
                cout << -1 << endl;
            }

            cin >> n >> m;
    }

    return 0;
}

