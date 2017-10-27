#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
#include <stack>
#include <cstdlib>
#include <string>
#include <set>
#include <map>

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
// assign
 
signed main()
{
    vi data(6);
    int three[4] = {0, 5, 3, 1};
    int tzero[4] = {0, 7, 6, 5};
    while (1) {
        bool finish = true;
        rep(i, 6) {
            cin >> data[i];
            if (data[i]) finish = false;
        }
        if (finish) break;
        int ans = data[5];
        ans += data[4];
        data[0] -= data[4] * 11;
        ans += data[3]; // 4 * 4 no Yatsu
        data[1] -= data[3] * 5;
        ans += (data[2] / 4);
        if (data[2] % 4) {
            ans++;
            data[1] -= three[data[2]%4];
            data[0] -= tzero[data[2]%4];
        }
        if (data[1] > 0) {
            ans += data[1]/9;
            if (data[1] % 9) {
                ans++;
                data[0] -= (9 - (data[1] % 9)) * 4;
            }
        } else {
            data[0] += data[1] * 4;
        }
        if (data[0] > 0) {
            ans += data[0] / 36 + !!(data[0] % 36);
        }
        cout << ans << endl;
    }
    return 0;
}

