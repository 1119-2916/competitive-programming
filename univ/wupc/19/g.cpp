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

    int2(n, m);
    vector<int> data(m);
    vi yui(n, 0);
    for (int i = 0; i < m; i++) {
        cin >> data[i];
        yui[data[i]]++;
    }

    vvi cost(n, vi(n, 0));
    rep(i, n) {
        rep(j, n) {
            if (i == j) continue;
            int tmp = 0, cnt = yui[i];
            rep(k, m) {
                if (data[k] == i) { 
                    cnt--;
                } else if (data[k] == j) {
                    tmp += cnt;
                }
            }
            cost[i][j] = tmp;
        }
    }
    /*
    rep(i, n) {
        rep(j, n) {
            std::cout << cost[i][j] << " ";
        }
        cout << endl;
    }
    */
    vi memoneMomo(1 << n, INF);
    memoneMomo[0] = 0;
    rep(i, 1 << n) {
        rep(j, n) {
            if (i & (1 << j)) {
                continue;
            }
            int tmp = 0;
            rep(k, n) {
                if ((i & (1 << k)) == 0) {
                    tmp += cost[j][k];
                }
            }
            //std::cout << i << " " << j << " " << tmp << std::endl;
            memoneMomo[i | (1 << j)] = min(memoneMomo[i | (1 << j)], 
                    memoneMomo[i] + tmp);
        }
    }
    /*
    rep(i, memoneMomo.size()) {
        std::cout << memoneMomo[i] << std::endl;
    }
    */
    std::cout << memoneMomo[(1 << n) -1] << std::endl;

    return 0;
}
