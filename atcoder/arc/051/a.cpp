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
    int2(rx, ry);
    Int(r);
    int2(stx, sty);
    int2(enx, eny);
    bool blue = false, red = false;

    for (int i = -202; i < 202; i++) {
        for (int j = -202; j < 202; j++) {
            int state = 0;
            if ((i - rx) * (i - rx) + (j - ry) * (j - ry) <= r * r) {
                state = 514;
            }
            if (stx <= i && i <= enx && sty <= j && j <= eny) {
                state += 114000;
            }
            if (state == 514) {
                red = true;
            } else if (state == 114000) {
                blue = true;
            }
        }
    }

    cout << ((red) ? "YES" : "NO" ) << endl;
    cout << ((blue) ? "YES" : "NO" ) << endl;




    return 0;
}

