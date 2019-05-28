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

    vi yui(3);
    rep(i, 3) cin >> yui[i];
    int n = 0;
    rep(i, 3) n += yui[i];

    vvi data(n, vi(3));
    rep(i, n) {
        rep(j, 3) {
            cin >> data[i][j];
        }
    }

    sort(all(data), [&](vi &x, vi &y){return x[1] - x[0] < y[1] - y[0];});

    /*
    rep(i, n) {
        rep(j, data[i].size()) {
            cout << data[i][j] << " ";
        }
        cout << " : " << data[i][1] - data[i][0] << endl;
    }
    */

    vi ans(n+1, -INF);
    {
        priority_queue<int> pq;
        ans[yui[0]] = 0;
        rep(i, yui[0]) {
            pq.push(data[i][2] - data[i][0]);
            ans[yui[0]] += data[i][0];

        }
        for (int i = yui[0]+1; i < n-yui[1]+1; i++) {
            ans[i] = ans[i-1];
            ans[i] += data[i-1][0];
            pq.push(data[i-1][2] - data[i-1][0]);
            ans[i] += pq.top();
            pq.pop();
        }
    }
/*
    rep(i, n) 
        std::cout << ans[i] << " ";
    std::cout << std::endl;
*/
    reverse(all(data));

    int ret = -INF, tmp = 0;
    priority_queue<int> pq;
    rep(i, yui[1]) {
        pq.push(data[i][2] - data[i][1]);
        tmp += data[i][1];
    }
    ret = max(ret, tmp + ans[n-yui[1]]);
    for (int i = yui[1]+1; i < n-yui[0]+1; i++) {
        tmp += data[i-1][1];
        pq.push(data[i-1][2] - data[i-1][1]);
        tmp += pq.top();
        pq.pop();
        ret = max(ret, tmp + ans[n-i]);
    }
    std::cout << ret << std::endl;

    return 0;
}
