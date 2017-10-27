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
#define mp make_pair
#define i_i pair<int, int>
#define vi vector<int>
#define vvi vector<vi >
#define vb vector<bool>
#define vvb vector<vb >
#define vp vector< i_i >
#define all(a) (a).begin(), (a).end()
#define Int(x) int x; scanf("%lld", &x);

//int dxy[5] = {0, 1, 0, -1, 0};
// assign

signed main()
{
    Int(n);
    int sum = 0;
    vi data(n, 0);
    rep(i, n) {
        cin >> data[i];
        sum += data[i];
    }

    int k = sum / (n * (n + 1) / 2);

    if (sum % (n * (n + 1) / 2))  {
        cout << "NO" << endl;
    } else {
        bool state = true;
        while (state) {
            state = false;
            vi inc(n, 0), dec(n, 0);
            Rep(i, n) {
                if (data[i-1] >= data[i]) {
                    int tmp = (data[i-1] - data[i] + k) / n;
                    inc[i] = tmp;
                    dec[i] = tmp;
                }
            }
            if ( data[0] <= data[n-1] ) {
                int tmp = (data[n-1] - data[0] + k) / n;
                inc[0] = tmp;
                dec[0] = tmp;
                cout << inc[0] << endl;
            }
            vi ret(n, 0);
            int add = 0, bef = 0;
            rep(i, n) {
                add += inc[i];
                bef += add;
                ret[i] += bef;
            }
            rep(i, n) {
                add -= dec[i];
                bef -= dec[i] * n;
                bef += add;
                ret[i] += bef;
            }
            rep(i, n) {
                data[i] -= ret[i];
                cout << data[i] << " ";
                if (data[i] > 0) {
                    state = true;
                    break;
                } else if(data[i] < 0) {
                    state = false;
                    break;
                }
            }
            cout << endl;
        }
        rep(i, n) {
            if (data[i]) {
                cout << "NO" << endl;
                return 0;
            } 
        }
        cout << "YES" << endl;
    }

    return 0;
}
