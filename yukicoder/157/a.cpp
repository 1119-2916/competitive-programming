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
#define int2(x, y) int x, y; scanf("%lld %lld", &x, &y);
 
//int dxy[5] = {0, 1, 0, -1, 0};
// assign
 
signed main()
{
    string a;
    cin >> a;
    int w = 0, l = 0;
    rep(i, a.size()) {
        if (a[i] == 'O') {
            w++;
            l = 0;
        } else {
            l++;
            w = 0;
        }
        if (w == 3) {
            cout << "East" << endl;
            return 0;
        } else if (l == 3) {
            cout << "West" << endl;
            return 0;
        }
    }
    cout << "NA" << endl;


             

         

    return 0;
}

