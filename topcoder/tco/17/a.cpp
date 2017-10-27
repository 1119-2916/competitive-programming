#include <bits/stdc++.h>
 
using namespace std;
 
#define INF 1001000100010001000
#define MOD 1000000007
#define EPS 1e-9
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
#define all(a) (a).begin(), (a).end()
#define Int(x) int x; scanf("%lld", &x);
#define int2(x, y) int x, y; scanf("%lld %lld", &x, &y);
 
//int dxy[5] = {0, 1, 0, -1, 0};
// assign

class WaterAndOxygen {

public : 
    double maxDays(int remainH20, int remainO2, int costH2O, int costO2)
    {
        double rh, ro, ch, co;
        rh = (double)remainH20;
        ro = (double)remainO2;
        ch = (double)costH2O;
        co = (double)costO2;
        double l = 0.0, r = 1000000001;
        while (abs(r - l) > EPS) {
            double mid = (r + l) / 2;
            double tmp = co * mid - ro;
            if (tmp < 0 - EPS) tmp = 0;
            //cout << u << endl;
            //printf("%.10lf\n", mid);
            printf("%.10lf\n", abs(r - l));
            printf("EPS%.10lf\n", EPS);
            //printf("%.10lf, %.10lf\n", l, r);
            if (ch * mid <= (rh - tmp * 2) &&
                    co * mid <= ro + tmp) {
                l = mid;
            } else {
                r = mid;
            }
        }
        return r;
    }
};

signed main()
{

    WaterAndOxygen w;
    double a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << w.maxDays(a, b, c, d) << endl;
    return 0;
}


