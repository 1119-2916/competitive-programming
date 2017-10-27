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
#define vp vector< pair<int, int> >
#define all(a) (a).begin(), (a).end()
#define Int(x) int x; scanf("%lld", &x);
 
//int dxy[5] = {0, 1, 0, -1, 0};
// assign
 
signed main()
{
    int n, ret = 0, reti = 0;
    cin >> n;

    Rep(i, n) {
        int tmp;
        cout << "? " << "1 " << i+1 << endl;
        cin >> tmp;
        if (ret < tmp) {
            ret = tmp;
            reti = i;
        }
    }

    ret = 0;
    rep(i, n) {
        if (i == reti) {
            continue;
        } else {
            int tmp;
            cout << "? " << reti+1 << " " << i+1 << endl;
            cin >> tmp;
            ret = max(ret, tmp);
        }
    }

    cout << "! " << ret << endl;
    
    return 0;
}

