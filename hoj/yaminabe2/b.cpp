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
// assign avl ncm dij geo2

signed main()
{
    int2(n, p);
    int ret = 0;
    rep(i, n) {
        int2(x, y);
        int r = x * x + y * y;

        int po = p * p;
        if (r < po) {
            ret += 5;
        } else if (r < po * 4) {
            ret += 4;
        } else if (r < po * 9) {
            ret += 3;
        } else if (r < po * 16) {
            ret += 2;
        } else if (r < po * 25) {
            ret += 1;
        }
    }
    cout << ret << endl;
    if (ret >= 25) {
        cout << "A" << endl;
    } else if ( ret >= 20 ) {
        cout << "B" << endl;
    } else if ( ret >= 15 ) {
        cout << "C" << endl;
    } else if ( ret >= 10 ) {
        cout << "D" << endl;
    } else if ( ret >= 5 ) {
        cout << "E" << endl;
    } else {
        cout << "F" << endl;
    }

    return 0;
}
