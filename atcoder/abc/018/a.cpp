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
#define all(a) (a).begin(), (a).end()
#define Int(x) int x; scanf("%lld", &x);
#define int2(x, y) int x, y; scanf("%lld %lld", &x, &y);
 
//int dxy[5] = {0, 1, 0, -1, 0};
// assign
 
signed main()
{
    int a, b, c;
    cin >> a >> b >> c;
    if (a < b && a < c) {
        cout << 3 << endl;
        if (b < c) {
            cout << 2 << endl;
            cout << 1 << endl;
        } else {
            cout << 1 << endl;
            cout << 2 << endl;
        }
    } else if ( b < a && b < c) {
        if (a < c) {
            cout << 2 << endl;
            cout << 3 << endl;
            cout << 1 << endl;
        } else {
            cout << 1 << endl;
            cout << 3 << endl;
            cout << 2 << endl;
        }
    } else {
        if (a < b) {
            cout << 2 << endl;
            cout << 1 << endl;
            cout << 3 << endl;
        } else {
            cout << 1 << endl;
            cout << 2 << endl;
            cout << 3 << endl;
        }
    }



    return 0;
}

