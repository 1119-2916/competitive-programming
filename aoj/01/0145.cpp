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

vvi dp;
vp data(510);
int n;

int solve(int l, int r)
{
    int ret = INF;
    if (dp[l][r] != INF) {
        return dp[l][r];
    } else if (l == r) {
        dp[l][r] = 0;
        return 0;
    } else {
//        cout << l << " " << r << endl;
        for (int i = l; i < r; i++) {
            ret = min(ret, solve(l, i) + solve(i+1, r) + 
                    data[l].fir * data[i].sec *
                    data[i+1].fir * data[r].sec);
        }
    }
    dp[l][r] = ret;
    return ret;
}

signed main()
{
    cin >> n;
    dp = vvi(n, vi(n, INF));
    rep(i, n) {
        cin >> data[i].fir >> data[i].sec;
    }
    /*
    Rep(i, n) {
        dp[i-1][i] = data[i-1].fir*data[i-1].sec*data[i].fir*data[i].sec;
    }*/
    cout << solve(0, n-1) << endl;


    return 0;
}

