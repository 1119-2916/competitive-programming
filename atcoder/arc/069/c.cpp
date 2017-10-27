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
#define mp make_pair
#define i_i pair<int, int>
#define vi vector<int>
#define vvi vector<vi >
#define vb vector<bool>
#define vvb vector<vb >
#define vp vector< i_i >
#define all(a) (a).begin(), (a).end()
#define Int(x) int x; scanf("%lld", &x);
#define int2(x, y) int x, y; scanf("%lld %lld", &x, &y);
 
//int dxy[5] = {0, 1, 0, -1, 0};
// assign
 
signed main()
{
    int n;
    cin >> n;
    vector< i_i > input(n, i_i(0, 0));
    vi ans(n, 0);
    rep(i, n) {
        cin >> input[i].first;
        input[i].second = i;
    }
    sort(all(input));
    //rep(i, n) cout << input[i].first << " " << input[i].second << endl;
   

    int add = input[0].second, dist = 0, ptr = 0;
    Rep(i, n) {
        if (input[i-1].first != input[i].first) {
            ans[add] += (input[ptr].first - dist) * (n - ptr);
            dist = input[ptr].first;
            ptr = i;
            add = input[i].second;
        }
    }
    ans[add] += (input[ptr].first - dist) * (n - ptr);

    rep(i, n) {
        cout << ans[i] << endl;
    }

    return 0;
}

