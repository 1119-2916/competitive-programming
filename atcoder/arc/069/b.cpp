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
    int n;
    string input;
    cin >> n >> input;
    string state[4];
    char st[4];

    if (input[0] == 'o') {
        state[0] = "SS";
        st[0] = 'S';
        state[1] = "SW";
        st[1] = 'W';
        state[2] = "WS";
        st[2] = 'W';
        state[3] = "WW";
        st[3] = 'S';
    } else {
        state[0] = "SS";
        st[0] = 'W';
        state[1] = "SW";
        st[1] = 'S';
        state[2] = "WW";
        st[2] = 'W';
        state[3] = "WS";
        st[3] = 'S';
    }

    Rep(i, n) {
        rep(j, 4) {
            if (state[j][i] == 'S') {
                if (input[i] == 'o') {
                    state[j].pb(state[j][i-1]);
                } else {
                    state[j].pb((state[j][i-1] == 'S') ? 'W' : 'S');
                }
            } else {
                if (input[i] == 'o') {
                    state[j].pb((state[j][i-1] == 'S') ? 'W' : 'S');
                } else {
                    state[j].pb(state[j][i-1]);
                }
            }
        }
    }
//    rep(i, 4) cout << state[i] << endl;

    int ans = -1;
    rep(i, 4) {
        if (state[i][n-1] == st[i] && state[i][0] == state[i][n]) {
            ans = i;
        }
    }
    if (ans != -1) {
        rep(i, state[ans].length()-1) {
            cout << state[ans][i];
        }
        cout << endl;
    } else {
        cout << ans << endl;
    }


    return 0;
}

