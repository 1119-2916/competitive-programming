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
#define eb emplace_back
#define mp make_pair
#define i_i pair<int, int>
#define vi vector<int>
#define vvi vector<vi >
#define vb vector<bool>
#define vvb vector<vb >
#define vp vector< i_i >
#define all(a) (a).begin(), (a).end()
#define Int(x) int x; cin >> x;
#define int2(x, y) Int(x); Int(y);
#define int3(x, y, z) Int(x); int2(y, z);
#define fir first
#define sec second
#define ffir first.first
#define fsec first.second
#define sfir second.first
#define ssec second.second
#define Decimal fixed << setprecision(10)

//int dxy[5] = {0, 1, 0, -1, 0};
// cmd

vb solve(int a)
{
    vb ret;
    vi num = {0, 8, 9, 10, 11, 12};
    vb state = {false, false, true, false, true, false};
                    for (int i10000 : num) {
                for (int i1000 : num) {
            for (int i100 : num) {
        for (int i10 : num) {
    for (int i1 : num) {
                        if (a == i1 + i10*10 + i100*100 + i1000*1000
                                + i10000 * 10000) {
                            /*
                            cout << i1 << " " << i10 << " " 
                            << i100 << " " << i1000 << " " << i10000 << 
                            endl;
                            */
                            if (i1) {
                                i1 -= 7;
                                ret.pb(state[i1]);
                                //cout << i1 << " " << state[i1] << endl;
                            }
                            if (i10) {
                                i10 -= 7;
                                ret.pb(state[i10]);
                                //cout << i10 << " " << state[i10] << endl;
                            }
                            if (i100) {
                                i100 -= 7;
                                ret.pb(state[i100]);
                                //cout << i100 << " " << state[i100] << endl;
                            }
                            if (i1000) {
                                i1000 -= 7;
                                ret.pb(state[i1000]);
                                //cout << i1000 << " " << state[i1000] << endl;
                            }
                            if (i10000) {
                                i10000 -= 7;
                                ret.pb(state[i10000]);
                                //cout << i10000 << " " << state[i10000] << endl;
                            }
                            return ret;
                        }
                    }
                }
            }
        }
    }
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    Int(n);

    vb ans(n, false);

    rep(i, 10) {
        int cnt = 0;
        cout << "? ";
        for (int j = 0; j < i * 5 && cnt < n; j++) {
            cout << "0 ";
            cnt++;
        }
        for (int j = 0; j < 5 && cnt < n; j++) {
            cout << 1 * pow(10, j) << " ";
            cnt++;
        }
        for (int j = 0; cnt < n; j++) {
            cout << "0 ";
            cnt++;
        }
        cout << endl;
        int tmp;
        cin >> tmp;
        vb yui = solve(tmp);
        //rep(j, yui.size()) cout << yui[j] << " ";cout << endl;
        rep(j, yui.size()) {
            ans[i*5+j] = yui[j];
        }
    }
    cout << "! ";
    rep(i, n) {
        cout << (int)ans[i] << " ";
    }
    cout << endl;

    return 0;
}
