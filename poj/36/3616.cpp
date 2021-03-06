#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
#include <stack>
#include <cstdlib>
#include <string>
#include <set>
#include <map>

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
#define Edge pair< int, i_i >
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

int dp[2000002];

signed main()
{
    int2(n, m);
    Int(r);
    vector< pair < i_i, int> > data(m);
    rep(i, m) {
        cin >> data[i].ffir >> data[i].fsec >> data[i].sec;
    }
    sort(all(data));
    int ptr = 0, ans = 0;
    rep(i, n + r + 1) {
        while (ptr < m && data[ptr].ffir == i) {
            dp[data[ptr].fsec + r] = max(dp[data[ptr].fsec + r],
                    dp[i] + data[ptr].sec);
            ptr++;
        }
        dp[i+1] = max(dp[i], dp[i+1]);
        ans = max(ans, dp[i+1]);
    }
    cout << ans << endl;

    return 0;
}

