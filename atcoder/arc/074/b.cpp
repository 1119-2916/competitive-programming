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
    Int(n);
    vi data(n*3);
    rep(i, data.size()) {
        cin >> data[i];
    }
    vvi dpl(n*3+1, vi(n+2, 0)), dpr(n*3+1, vi(n+2, INF));
    rep(i, n*3+1) dpr[i][0] = 0;

    rep(i, n+1) {
        for (int j = i; j < n * 3-1; j++) {
            dpl[j+1][i] = max(dpl[j][i], dpl[j+1][i]);
            dpl[j+1][i+1] = max(dpl[j+1][i+1], dpl[j][i] + data[j]);
        }
    }
    /*
    rep(i, n+1) {
        rep(j, n*3) {
            cout << dpl[j][i] << " ";
        }
        cout << endl;
    }*/
    //rep(i, n*3) {cout << dpl[i][n] << " " ; } cout << endl;
    //cout << "===" << endl;
    reverse(all(data));
    rep(i, n+1) {
        for (int j = i; j < n*3-1; j++) {
            dpr[j+1][i] = min(dpr[j][i], dpr[j+1][i]);
            dpr[j+1][i+1] = min(dpr[j+1][i+1], dpr[j][i] + data[j]);
        }
    }
//    rep(i, n*2) {cout << dpr[n+i][n] << endl; }
    int ans = -INF;
    rep(i, n+1) {
        ans = max(ans, dpl[n+i][n] - dpr[n+(n-i)][n]);
    }
    cout << ans << endl;



    return 0;
}

