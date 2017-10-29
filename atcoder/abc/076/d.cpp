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
// cmd

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    Int(n);
    vector<int> time(n);
    for (int i = 0; i < n; i++) {
        cin >> time[i];
    }
    vector<int> fast(n);
    for (int i = 0; i < n; i++) {
        cin >> fast[i];
    }
    fast.pb(0);

    double bef = 0.0;
    double ans = 0.0;
    rep(i, n) {
        if (fast[i] > fast[i+1]) {
            if ((fast[i] - bef)+(fast[i] - fast[i+1]) <= (double)time[i]) {
                ans += (fast[i] - bef)*(fast[i] - bef)/2.0;
                ans += (fast[i] - fast[i+1])*(fast[i] - fast[i+1])/2.0;
                ans += ((double)time[i] -
                    (fast[i] - bef)+(fast[i] - fast[i+1])) *fast[i];
                ans += bef * (fast[i] - bef);
                ans += (fast[i] - fast[i+1]) * fast[i+1];
            } else {



    
    

    return 0;
}
