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


int solve(vp &range, const int p, const int over)
{
    //cout << "call " << p << " : ";
    int n = range.size(), bef = p, ret = 1;

    for (int i = (p + 1) % n; i != p; i = (i + 1) % n) {
        if (range[i].fir < range[i].sec && 
                range[i].fir <= range[bef].sec && range[bef].sec <= range[i].sec) {
            continue;
        } else if (range[i].fir > range[i].sec &&
                (range[i].fir <= range[bef].sec || range[bef].sec <= range[i].sec)) {
            continue;
        } else {
            //cout << i << " , ";
            ret++;
            bef = i;
        }
    }

    //cout << endl;

    return ret;
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    Int(n);
    int2(w, d);

    vector<pair<pii, pii>> data(n);
    rep(i, n) {
        int2(x, y); // yoko, tate
        string st;
        cin >> st;
        if (st[0] == 'E') { // right
            int b = y - x;
            data[i].ffir = d - b;
            data[i].fsec = d;
            if (data[i].ffir < 0 || w < data[i].ffir) {
                data[i].ffir = w;
                data[i].fsec = w + b;
            }
            b = y + x;
            data[i].sfir = b;
            data[i].ssec = 0;
            if (data[i].sfir < 0 || w < data[i].sfir) {
                data[i].sfir = w;
                data[i].ssec = -w + b;
            }
        } else if (st[0] == 'W') {
            int b = y - x;
            data[i].ffir = -b;
            data[i].fsec = 0;
            if (data[i].ffir < 0 || w < data[i].ffir) {
                data[i].ffir = 0;
                data[i].fsec = b;
            }
            b = y + x;
            data[i].sfir = b - d;
            data[i].ssec = d;
            if (data[i].sfir < 0 || w < data[i].sfir) {
                data[i].sfir = 0;
                data[i].ssec = b;
            }
        } else if (st[0] == 'N') {
            int b = y + x;
            data[i].ffir = b - d;
            data[i].fsec = d;
            if (data[i].ffir < 0 || w < data[i].ffir) {
                data[i].ffir = 0;
                data[i].fsec = b;
            }
            b = y - x;
            data[i].sfir = d - b;
            data[i].ssec = d;
            if (data[i].sfir < 0 || w < data[i].sfir) {
                data[i].sfir = w;
                data[i].ssec = w + b;
            }
        } else if (st[0] == 'S') {
            int b = y + x;
            data[i].ffir = b;
            data[i].fsec = 0;
            if (data[i].ffir < 0 || w < data[i].ffir) {
                data[i].ffir = w;
                data[i].fsec = -w + b;
            }
            b = y - x;
            data[i].sfir = -b;
            data[i].ssec = 0;
            if (data[i].sfir < 0 || w < data[i].sfir) {
                data[i].sfir = 0;
                data[i].ssec = b;
            }
        }
    }

/*
rep(i, n) {
        cout << data[i].ffir << " " << data[i].fsec << endl;
        cout << data[i].sfir << " " << data[i].ssec << endl;
    }
*/

    int rn = w + w + d + d;
    vp range(n);
    rep(i, n) {
        int s, e;
        if (data[i].ffir == 0) {
            s = data[i].fsec;
        } else if (data[i].fsec == d) {
            s = d + data[i].ffir;
        } else if (data[i].ffir == w) {
            s = d + w + (d - data[i].fsec);
        } else if (data[i].fsec == 0) {
            s = d + d + w + (w - data[i].ffir);
        }

        if (data[i].sfir == 0) {
            e = data[i].ssec;
        } else if (data[i].ssec == d) {
            e = d + data[i].sfir;
        } else if (data[i].sfir == w) {
            e = d + w + (d - data[i].ssec);
        } else if (data[i].ssec == 0) {
            e = d + d + w + (w - data[i].sfir);
        }
        /*
        range[i].fir = s;
        range[i].sec = e;
        //range[i].sec = (e > s ? e : e + rn);
        */
        range[i].fir = e;
        range[i].sec = s;
    }

    sort(all(range));
    rep(i, n) swap(range[i].fir, range[i].sec);

    //cout << "ops" << endl;
    //rep(i, n) {
    //    cout << range[i].fir << " " << range[i].sec << endl;
    //}

    int ans = n;
    rep(i, n) {
        ans = min(ans, solve(range, i, rn));
    }

    cout << ans << endl;

    return 0;
}


