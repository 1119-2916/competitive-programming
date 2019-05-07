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
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vi >
#define vb vector<bool>
#define vvb vector<vb >
#define vp vector< pii >
#define all(a) (a).begin(), (a).end()
#define Int(x) int x; cin >> x;
#define int2(x, y) Int(x); Int(y);
#define int3(x, y, z) Int(x); int2(y, z);
#define in(x, a, b) ((a) <= (x) && (x) < (b))
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

    int3(h, w, n);
    int2(x, y);

    string s; cin >> s;
    string t; cin >> t;

    vector<pair<pii, pii>> state(n); // l, r, u, d
    {
        int ld = 1, rd = w, ud = 1, dd = h;
        for (int i = n-1; i >= 0; i--) {
            if (t[i] == 'U') {
                dd = min(h, dd+1);
            } else if (t[i] == 'D') {
                ud = max(1ll, ud-1);
            } else if (t[i] == 'L') {
                rd = min(w, rd+1);
            } else if (t[i] == 'R') {
                ld = max(1ll, ld-1);
            }

            if (s[i] == 'U') {
                ud++;
            } else if (s[i] == 'D') {
                dd--;
            } else if (s[i] == 'L') {
                ld++;
            } else if (s[i] == 'R') {
                rd--;
            }
            state[i] = {{ld, rd}, {ud, dd}};
        }
    }
/*
    rep(i, n) {
        cout << state[i].ffir << "-" << state[i].fsec << " , " <<
            state[i].sfir << "-" << state[i].ssec << endl;
    }
    cout << endl;
*/
    vector<pair<pii, pii>> range(n); // l, r, u, d
    range[0] = {{y, y}, {x, x}};
    rep(i, n-1) {
        int ld = range[i].ffir, rd = range[i].fsec, ud = range[i].sfir, dd = range[i].ssec;
        if (s[i] == 'U') {
            dd--;
        } else if (s[i] == 'D') {
            ud++;
        } else if (s[i] == 'L') {
            rd--;
        } else if (s[i] == 'R') {
            ld++;
        }

        if (t[i] == 'U') {
            ud = max(1ll, ud-1);
        } else if (t[i] == 'D') {
            dd = min(h, dd+1);
        } else if (t[i] == 'L') {
            ld = max(1ll, ld-1);
        } else if (t[i] == 'R') {
            rd = min(w, rd+1);
        }

        range[i+1] = {{ld, rd}, {ud, dd}};
    }
/*
    rep(i, n) {
        cout << range[i].ffir << "-" << range[i].fsec << " , " <<
            range[i].sfir << "-" << range[i].ssec << endl;
    }
*/
    bool faild = false;
    rep(i, n) {
        if (range[i].ffir > state[i].fsec || 
                range[i].fsec < state[i].ffir || 
                range[i].sfir > state[i].ssec ||
                range[i].ssec < state[i].sfir) {
            //cout << i << endl;
            faild = true;
        }
    }

    std::cout << ((faild) ? "NO" : "YES") << std::endl;

    return 0;
}


