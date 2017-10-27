#include <bits/stdc++.h>
 
using namespace std;
 
#define INF 1001000100010001000
#define MOD 1000000007
#define EPS 1e-10
#define int long long
#define double long double
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
 
signed main()
{
    Int(dataset);
    Rep(state, dataset+1) {
        cout << "Case #" << state << ": ";

        int2(a, b);
        double add;
        cin >> add;
        vector <double> data(a);
        rep(i, a) {
            cin >> data[i];
        }
        sort(all(data));
        rep(i, a-1) {
            if ((data[i+1] - data[i]) * (i+1) <= add + EPS) {
                double funami = data[i+1] - data[i];
              //  cout << funami << endl;
                rep(j, i+1) {
                    data[j] += funami;
                    add -= funami;
                }
            } else {
                rep(j, i+1) {
                    data[j] += (add / (i+1));
                }
                add = 0.0;
                break;
            }
        }
       // cout << add << endl;
        //rep(i, a) cout << data[i] << endl;
        if (add > EPS) {
            rep(i, a) {
                data[i] += add / a;
            }
        }

        double ans = 1.0;
        for (double tmp : data) {
            if (tmp < 1) {
        //        cout << tmp << endl;
                ans *= tmp;
            }
        }

        printf("%.10Lf\n", ans);
    }
            


    return 0;
}

