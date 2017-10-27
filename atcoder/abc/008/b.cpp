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
#define Int(x) int x; scanf("%lld", &x);
#define int2(x, y) int x, y; scanf("%lld %lld", &x, &y);
 
//int dxy[5] = {0, 1, 0, -1, 0};
// assign
 
signed main()
{
    Int(n);
    vector<string> s(n);
    rep(i, n) {
        cin >> s[i];
    }
    sort(all(s));
    int max = 0, tmp = 0;
    string ans = s[0];
    Rep(i, n) {
        if (s[i] == s[i-1]) {
            tmp++;
            if (tmp > max) {
                max = tmp;
                ans = s[i];
            }
        } else {
            tmp = 0;
        }
    }
    cout << ans << endl;




    return 0;
}

