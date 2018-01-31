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
#define Edge pair< i_i, int>
#define all(a) (a).begin(), (a).end()
#define Int(x) int x; scanf("%lld", &x);
#define int2(x, y) int x, y; scanf("%lld %lld", &x, &y);
#define fir first
#define sec second
#define ffir first.first
#define fsec first.second
#define sfir second.first
#define ssec second.second
 
//int dxy[5] = {0, 1, 0, -1, 0};
// assign
 
signed main()
{
    int2(n, k);
    k = k * 2;
    vvi w(k, vi(k+1, 0)), b(k, vi(k+1, 0));
    rep(i, n) {
        int2(x, y);
        char c; cin >> c;
        if (c == 'W') {
            w[(x%k)+1][(y%k)+1]++;
        } else {
            b[(x%k)+1][(y%k)+1]++;
        }
    }
    Rep(i, k) {
        Rep(j, k) {
            data[i][j] += data[i][j-1];
        }
    }

    Rep(j, k) {
        Rep(i, k) {
            data[i][j] += data[i-1][j];
        }
    }

    int ans = -INF;
    Rep(i, k/2) {
        Rep(j, k/2) {
           int tmp += w[i][j] + ; 
            ans = max(ans, 
            rep(k, i+1) {
                rep(l, j+1) {
                    int tmp = -INF;
                    if (i == k && j == l) {
                        continue;
                    } else if (i == k || j == l) {
                        tmp = data[i][j] - data[k][l];
                    } else {
                        tmp = data[i][j] - data[k][j]
                            - data[i][l] + data[k][l];
                    }
                    ans = max(ans, tmp);
                }
            }
        }
    }



    cout << ans << endl;

    return 0;
}

