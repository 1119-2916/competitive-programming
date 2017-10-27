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
    vi data(n, 0);
    int m = 0;
    rep(i, n) {
        cin >> data[i];
        if (data[i] > data[m]) {
            m = i;
        }
    }
    bool fl = true;
    bool ret = false;
    while (fl) {
        fl = false;
        int max = 0;
        int st = m;
        for (int i = st+1; i < n; i++) {
            data[i] -= (i - st);
            if (max < data[i]) {
                max = data[i];
                m = i;
            }
            if (data[i] > 0) {
                fl = true;
            } else if (data[i] < 0) {
                ret = true;
                break;
            }
        }
        for (int i = 0; i < st+1; i++) {
            data[i] -= (n-st + i);
            if (max < data[i]) {
                max = data[i];
                m = i;
            }
            if (data[i] > 0) {
                fl = true;
            } else if ( data[i] < 0) {
                ret = true;
                break;
            }
        }
        if (ret) {
            cout << "NO" << endl;
            break;
        } 
    }
    if (!ret) {
        cout << "YES" << endl;
    }

    return 0;
}

