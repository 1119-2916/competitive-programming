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

    int2(n, k);
    vector<int> data(n);
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }

    sort(all(data));

    map<int, int> funami;
    funami[0] = 1;
    rep(i, n) {
        map<int, int> nxt;
        for (auto j = funami.begin(); j != funami.end(); j++) {
            nxt[j->fir] = (nxt[j->fir] + j->sec) % MOD;
            nxt[j->fir ^ data[i]] = (nxt[j->fir ^ data[i]] + j->sec) % MOD;
        }
        funami = nxt;
    }
    cout << funami[k] << endl;

    return 0;
}


