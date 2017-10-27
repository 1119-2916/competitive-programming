#include <bits/stdc++.h>

using namespace std;

#define INF 1001000100010001000
#define MOD 1000000007
#define EPS 1e-8
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
#define Edge pair< i_i, int>
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
    int2(n, k);
    vp data(n);
    rep(i, n) {
        cin >> data[i].fir >> data[i].sec;
    }
    double l = 0.0, r = 100.0;
    rep(loop, 100) {
        double mid = (l + r) / 2.0;
        vector<double> score(n);
        rep(i, n) {
            score[i] = (double)data[i].fir * ((double)data[i].sec - mid);
        }
        sort(all(score));
        reverse(all(score));
        double ans = 0.0;
        rep(i, k) { 
            ans += score[i];
        }
        //cout << ans << endl;
        if (ans > EPS) {
            l = mid;
        } else {
            r = mid;
        }
    }
    printf("%.10lf\n", (l+r) / 2.0);


    return 0;
}

