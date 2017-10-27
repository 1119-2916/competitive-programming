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
#define eb emplece_back
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

//int dxy[5] = {0, 1, 0, -1, 0};
// assign avl ncm dijkstra geo2 kruskal graph uf lca BIT
// matrix dinic next_combination topcoder lcm

int keta(int a)
{
    int cnt = 0;
    while (a) {
        a /= 2;
        cnt++;
    }
    return cnt;
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int2(n, k);
    vector<i_i> data(n);
    for (int i = 0; i < n; i++) {
        cin >> data[i].fir >> data[i].sec;
    }

    sort(all(data));
    reverse(all(data));

    vector< vvi > dp(keta(k)+2, vvi(2, vi(2, 0)));

    rep(i, n) {
        int tmp = keta(data[i].fir);
        cout << tmp << endl;
        if (k % (1 << tmp) <= data[i].fir) {
            if (data[i].fir & (1 << (tmp-1))) {
                dp[tmp][1][1] += dp[tmp+1][1][1]+data[i].fir * data[i].sec;
            } else {
                dp[tmp][0][1] += dp[tmp+1][1][1]+data[i].fir * data[i].sec;
            }
        }

        if (data[i].fir & (1 << (tmp-1))) {
            dp[tmp][1][0] += dp[tmp+1][0][0] + data[i].fir * data[i].sec;
        } else {
            dp[tmp][0][0] += dp[tmp+1][0][0] + data[i].fir * data[i].sec;
        }

    rep(i, keta(k) + 1) {
        rep(j, 2) {
            cout << dp[i][j][0] << " ";
            cout << dp[i][j][1] << " ";
        }
        cout << endl;
    }

    }

    rep(i, keta(k) + 1) {
        rep(j, 2) {
            cout << dp[i][j][0] << " ";
            cout << dp[i][j][1] << " ";
        }
        cout << endl;
    }

    cout << max(dp[0][0][0], dp[0][1][0]) << endl;


    return 0;
}



