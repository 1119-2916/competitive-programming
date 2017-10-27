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

int n, like, hate;
vi a, b, c;
int alike[10000], blike[10000], distlike[10000], ahate[10000], 
    bhate[10000], disthate[10000], ans[1000];
bool updated;

void update(int &x, int y) 
{
    if (x > y) {
        x = y;
        updated = true;
    }
}
//
// 辺は別々でやったほうがいい
// どこからきて、どこへゆくのか、それぞれ違うので
// まとめて処理するのはしんどすぎる。
//
void bell()
{
    rep(k, n+1) {

    rep(i, n) {
        cout << ans[i] << " ";
    }cout << endl;

        updated = false;
        rep(i, a.size()-hate) {
            if (ans[a[i]] < INF) update(ans[a[i]], ans[b[i]] + c[i]);
        }
        for (int i = a.size()-hate; i < a.size(); i++) {
            cout << i << endl;
            if (ans[b[i]] < INF) update(ans[a[i]], ans[b[i]] - c[i]);
        }
        /*
        rep(i, n-1) {
            if (ans[i+1] < INF) update(ans[i], ans[i+1]);
        }
        rep(i, like) {
            if (ans[alike[i] - 1] < INF) 
                update(ans[blike[i]-1], ans[alike[i]-1] + distlike[i]);
        }
        rep(i, hate) {
            if (ans[bhate[i] - 1] < INF)
                update(ans[ahate[i] - 1], ans[bhate[i] - 1] - disthate[i]);
        }
        */
    }
}

signed main()
{
    cin >> n >> like >> hate;

    rep(i, n-1) {
        a.pb(i);
        b.pb(i+1);
        c.pb(0);
    }
    rep(i, like) {
        int2(yu, kyo);
        Int(aka);
        a.pb(yu-1);
        b.pb(kyo-1);
        c.pb(aka);
    //    cin >> alike[i] >> blike[i] >> distlike[i];
    }
    rep(i, hate) {
        int2(yu, kyo);
        Int(aka);
        a.pb(yu-1);
        b.pb(kyo-1);
        c.pb(aka);
    //    cin >> ahate[i] >> bhate[i] >> disthate[i];
    }
    rep(i, a.size()) 
        cout << a[i] << " " << b[i] << " " << c[i] << endl;
    cout << "========" << endl;

    fill(ans, ans + n, INF);
    ans[0] = 0;
    bell();

    rep(i, n) {
        cout << ans[i] << " ";
    }cout << endl;

    if (updated) cout << -1 << endl;
    else if (ans[n-1] == INF) cout << -2 << endl;
    else cout << ans[n-1] << endl;

    return 0;

}
