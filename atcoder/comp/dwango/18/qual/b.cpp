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

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    string st;
    cin >> st;

    vb used(st.size(), false);

    int ans = 0, state = 0;
    while (1) {
        bool yui = true;
        rep(i, st.size()) yui &= used[i];
        if (yui) break;
        yui = true;
        rep(i, st.size()) {
            if (!used[i]) {
                yui &= (st[i] == '5');
            }
        }
        if (yui) {
            cout << -1 << endl;
            return 0;
        }
        rep(i, st.size()) {
            if (!used[i]) {
                if (state == 0 && st[i] == '2') {
                    used[i] = true;
                    state = 1;
                } else if (state == 1 && st[i] == '5') {
                    used[i] = true;
                    state = 0;
                }
            }
        }
        if (state) {
            cout << -1 << endl;
            return 0;
        }
        ans++;
    }
    cout << ans << endl;


        
    


    return 0;
}



