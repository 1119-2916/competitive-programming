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

    int2(h, w);
    Int(d);
    map<int, pii> funami;

    rep(i, h) rep(j, w) {
        Int(tmp);
        funami[tmp] = {i, j};
    }

    vector<int> yui(h * w + 1, -1);

    Rep(i, yui.size()) {
        if (yui[i] == -1) {
            yui[i] = 0;
            int nxt = i + d, now = i;
            while (nxt < h * w + 1) {
                yui[nxt] = yui[now] + abs(funami[now].fir-funami[nxt].fir) + 
                    abs(funami[now].sec-funami[nxt].sec);
                now += d; nxt += d;
            }
        }
    }

    Int(q);
    while (q--) {
        int2(a, b);
        cout << yui[b] - yui[a] << endl;
    }

    return 0;
}
