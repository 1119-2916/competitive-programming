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

    Int(n);
    vector<int> from(n);
    for (int i = 0; i < n; i++) {
        cin >> from[i];
    }
    
    vector<int> to(n);
    for (int i = 0; i < n; i++) {
        cin >> to[i];
    }

    if (n == 2) {
        if (from[0] <= to[0] && 
                from[1] <= to[1]) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
        return 0;
    }
    
    {
        vi ff = from, tt = to;
        sort(all(ff));
        sort(all(tt));
        rep(i, n) {
            if (!(ff[i] <= tt[i])) {
                cout << "No" << endl;
                return 0;
            }
        }
        Rep(i, n) {
            if (!(tt[i-1] < ff[i])) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }

    vector<pii> f(n), t(n);
    rep(i, n) {
        f[i].fir = from[i];
        f[i].sec = i;
        t[i].fir = to[i];
        t[i].sec = i;
    }

    sort(all(f));
    sort(all(t));

    bool fl = false;
    rep(i, n-1) {
        if (!(f[i+1].sec == t[i].sec)) {
            fl = true;
        }
    }
    if (!fl) {
        cout << "No" << endl;
        return 0;
    }

    fl = false;
    rep(i, n-1) {
        if (!(f[i].sec == t[i+1].sec)) {
            fl = true;
        }
    }
    if (!fl) {
        cout << "No" << endl;
        return 0;
    }

    vi used(n, 0);
    int p = 0;
    rep(i, n-1) {
        //cout << p << endl;
        if (used[f[p].sec]) {
            cout << "Yes" << endl;
            return 0;
        }
        used[f[p].sec] = 1;
        p = t[p].sec;
    }

    cout << "No" << endl;

    return 0;
}
