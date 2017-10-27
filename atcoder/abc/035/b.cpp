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
    string st;
    cin >> st;
    int l = 0, r = 0, u = 0, d = 0, q = 0;
    Int(type);
    rep(i, st.size()) {
        switch(st[i]) {
            case 'L' : 
                l++;
                break;
            case 'R' : 
                r++;
                break;
            case 'U' : 
                u++;
                break;
            case 'D' : 
                d++;
                break;
            case '?' : 
                q++;
                break;
            default :
                break;
        }
    }
    int x = abs(l - r), y = abs(u - d);
    if (type == 1) {
        cout << x + y + q << endl;
    } else {
        int dx = min(x, q);
        x -= dx; q -= dx;
        int dy = min(y, q);
        y -= dy; q -= dy;
        cout << x + y + (q % 2) << endl;
    }

    return 0;
}

