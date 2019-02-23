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
    vp data(n); // y x
    rep(i, n) {
        cin >> data[i].sec >> data[i].fir;
    }
    
    sort(all(data));
    reverse(all(data));

    int p = 0, yui = data[0].fir;
    map<int, int> nxt;
    while (yui > 0) {
        map<int, int> mmnmm = nxt;
        while (p < data.size() && data[p].fir == yui) {
            mmnmm[data[p].sec]++;
            p++;
        }
        yui--;
        nxt = map<int, int>();
        for (auto i : mmnmm) {
            if (i.sec % 2) {
                nxt[i.fir]++;
                nxt[i.fir + 1]++;
            }
        }
    }

    map<int, int> funami = nxt;

    p = data.size()-1; yui = data.back().fir;
    nxt = map<int, int>();
    while (yui < 0) {
        map<int, int> mmnmm = nxt;
        while (p >= 0 && data[p].fir == yui) {
            mmnmm[data[p].sec]++;
            p--;
        }
        yui++;
        nxt = map<int, int>();
        for (auto i : mmnmm) {
            if (i.sec % 2) {
                mmnmm[i.fir+1]++;
                nxt[i.fir]++;
            }
        }
    }

    for (auto i : nxt) {
        if (i.sec % 2) {
            funami[i.fir]++;
        }
    }
    rep(i, data.size()) {
        if (data[i].sec == 0) {
            funami[data[i].fir]++;
        }
    }

    int ans = INF;
    for (auto i : funami) {
        if (i.sec % 2 && ans == INF) {
            ans = i.fir;
        } else if (i.sec % 2) {
            assert(0);
        }
    }

    std::cout << ans << std::endl;

    return 0;
}

