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
    int2(n, s);

    vi item(n);
    vi state(n);
    rep(i, n) cin >> item[i];

    int l = 0, r = n+1;
    while ((r + l)/2 != l) {
        int mid = (r + l) / 2;
        rep(i, n) {
            state[i] = item[i] + (i+1) * mid;
        }
        sort(all(state));
        int sum = 0;
        rep(i, mid) {
            sum += state[i];
        }
        if (sum <= s) {
            l = mid;
        } else {
            r = mid;
        }
    }

    int mid = (r + l) / 2;
    rep(i, n) {
        state[i] = item[i] + (i+1) * mid;
    }
    sort(all(state));
    int sum = 0;
    rep(i, mid) {
        sum += state[i];
    }

    cout << mid << " " << sum << endl;



    return 0;
}

