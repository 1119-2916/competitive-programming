#include <bits/stdc++.h>

using namespace std;

#define INF 1001000100010001000
#define INFd 1010001000.0
#define MOD 1000000007
#define EPS 1e-10
#define int long long
#define double long double
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
#define vd vector<double>
#define vvd vector< vd >
 
//int dxy[5] = {0, 1, 0, -1, 0};
// assign
//
void akari(int akane)
{
    string akaza;
    if (akane) {
        while (akane) {
            akaza.pb((akane&1)+'0');
            akane >>= 1;
        }
        reverse(all(akaza));
        cout << akaza;
    } else {
        cout << 0;
    }
}

 
signed main()
{
    Int(n);
    vi dist(n), weight(n), state(n), cost(1 << n);
    vvi line(1 << n, vi(n));
    vvd dp(1 << n, vd(n, INFd));

    rep(i, n) {
        cin >> state[i];
        cin >> dist[i] >> weight[i];
    }
    cost[0] = 0;
    Rep(i, 1 << n) {
        rep(j, n) {
            if (i & (1 << j)) {
                cost[i] += weight[j];
            }
        }
    }
    /*
    cout << "==cost=====" << endl;
    rep(i, 1 << n) {
        akari(i);
        cout << " : " << cost[i] << endl;
    }
    cout << endl;
    */
    rep(i, n) {
        dp[1 << i][i] = 0;
    }
    
    Rep(i, 1 << n) {
        rep(j, n) {
            if (i & (1 << j)) {
                rep(k, n) {
                    if (!(i & (1 << k))) {
                        double tmp = dp[i][j] + 
                            (double)(abs(dist[j]-dist[k])*(70+cost[i]*20))
                            /2000.0;
                        if (dp[i|(1 << k)][k] > tmp) {
                            dp[i|(1 << k)][k] = tmp;
                            line[i|(1 << k)][k] = j;
                        }
                    }
                }
            }
        }
    }

    /*
    cout << "===table======" << endl;
    rep(i, 1 << n) {
        akari(i);
        cout << " : ";
        rep(j, n) {
            cout << "(" << dp[i][j] << ", " << line[i][j] << ") ";
        }
        cout << endl;
    }
    cout << endl;
    */
    int ptr = 0;
    Rep(i, n) {
        if (dp[(1 << n)-1][i] < dp[(1 << n)-1][ptr]) {
            ptr = i;
        }
    }
    vi ans;
    int pos = (1 << n) - 1;
    ans.pb(ptr);
    Rep(i, n) {
        int tmp = ptr;
        ptr = line[pos][ptr];
        pos -= (1 << tmp);
        ans.pb(ptr);
    }
    reverse(all(ans));
    cout << state[ans[0]];
    Rep(i, n) {
        cout << " " << state[ans[i]];
    }
    cout << endl;


    return 0;
}

